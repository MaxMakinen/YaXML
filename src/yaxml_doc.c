/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaxml_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:20:49 by mmakinen          #+#    #+#             */
/*   Updated: 2022/11/29 12:20:50 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yaxml.h"

int	xml_error_free(char *buf, char *err_str)
{
	if (err_str != NULL)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putendl_fd(err_str, 2);
	}
	free(buf);
	return (FALSE);
}

size_t	xml_get_size(const char *path)
{
	int		fd;
	size_t	size;
	size_t	temp;
	char	buf[4096];

	size = 0;
	fd = open(path, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (xml_return_error("ERROR: Input is directory"));
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (xml_return_error("ERROR: Could not load file"));
	temp = read(fd, buf, 4096);
	while (temp > 0)
	{
		size += temp;
		temp = read(fd, buf, 4096);
	}
	if (close(fd) == -1)
		return (xml_return_error("ERROR: Could not close file"));
	return (size);
}

int	xml_read_file(t_buffer *buf, const char *path)
{
	int	fd;

	buf->buff_len = xml_get_size(path);
	if (buf->buff_len == FALSE)
		return (FALSE);
	buf->mem = (char *)malloc(sizeof(buf->mem) * buf->buff_len + 1);
	if (!buf->mem)
		return (xml_error_free(buf->mem, "Buffer malloc failed"));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (xml_error_free(buf->mem, "Could not load file"));
	if (read(fd, buf->mem, buf->buff_len) == -1)
		return (xml_error_free(buf->mem, "Could not read file"));
	buf->mem[buf->buff_len] = '\0';
	if (close(fd) == -1)
		return (xml_error_free(buf->mem, "Could not close file"));
	return (TRUE);
}

int	xml_get_data(t_xml_node *current_node, char *buf, char lex[256])
{
	if (!current_node)
		return (xml_error_free(buf, "Text outside document"));
	if (!current_node->data)
		current_node->data = ft_strdup(lex);
	return (TRUE);
}

int	xml_node_end(char *buf, char lex[256], int index[2], \
t_xml_node **current_node)
{
	index[0] += 2;
	while (buf[index[0]] != '>')
		lex[index[1]++] = buf[index[0]++];
	lex[index[1]] = '\0';
	if (!*current_node)
		return (xml_error_free(buf, "Already at head"));
	if (ft_strcmp((*current_node)->tag, lex))
	{
		ft_putstr_fd((*current_node)->tag, 2);
		ft_putstr_fd(" != ", 2);
		ft_putendl_fd(lex, 2);
		return (xml_error_free(buf, "Mismatched tags"));
	}
	*current_node = (*current_node)->parent;
	index[0]++;
	index[1] = 0;
	return (TRUE);
}

int	xml_doc_load(t_xml_doc *doc, const char *path)
{
	t_buffer	buffer;
	char		*buf;
	char		lex[1024];
	int			index[2];
	t_xml_node	*current_node;

	index[0] = 0;
	index[1] = 1;
	lex[0] = 0;
	if (!xml_read_file(&buffer, path))
		return (FALSE);
	doc->head = xml_node_new(NULL);
	if (doc->head == NULL)
	{
		xml_doc_free(doc);
		free(buffer.mem);
		return (FALSE);
	}
	current_node = doc->head;
	buf = buffer.mem;
	while (buf[index[0]] != '\0')
	{
		if (buf[index[0]] == '<')
		{
			lex[index[1]] = '\0';
			if (index[1] > 0)
			{
				if (!xml_get_data(current_node, buf, lex))
					return (FALSE);
				index[1] = 0;
			}
			if (buf[index[0] + 1] == '/')
			{
				if (!xml_node_end(buf, lex, index, &current_node))
					return (FALSE);
				continue ;
			}
			if (buf[index[0] + 1] == '!')
			{
				if (xml_comment(buf, &index[0]))
					continue ;
			}
			if (buf[index[0] + 1] == '?')
			{
				if (xml_declaration(buf, index, doc))
					continue ;
			}
			current_node = xml_node_new(current_node);
			if (xml_start_tag(buf, index, lex, &current_node))
				continue ;
			index[1] = 0;
			index[0]++;
			continue ;
		}
		else
		{
			lex[index[1]++] = buf[index[0]++];
			if (lex[index[1] - 1] == '\n' || lex[index[1] - 1] == '\t')
				index[1]--;
		}
	}
	if (buf != NULL)
		free(buf);
	return (TRUE);
}
