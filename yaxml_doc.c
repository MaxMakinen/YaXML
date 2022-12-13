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

static int	check_end(const char *str, const char *target)
{
	int	str_len;
	int	target_len;
	int	index;

	index = 0;
	str_len = ft_strlen(str);
	target_len = ft_strlen(target);
	if (str_len < target_len)
		return (FALSE);
	while (index < target_len)
	{
		if (str[str_len - target_len + index] != target[index])
			return (FALSE);
	}
	return (TRUE);
}

static t_tag_type parse_attr(char *buf, int *index, char *lex, int *lexi, \
t_xml_node *current_node)
{
	t_xml_attr	current_attr;
	current_attr.key = 0;
	current_attr.value = 0;
	while (buf[*index] != '>')
	{
		lex[(*lexi)++] = buf[(*index)++];

		//tag name
		if (buf[*index] == ' ' && !current_node->tag)
		{
			lex[*lexi] = '\0';
			current_node->tag = ft_strdup(lex);
			*lexi = 0;
			(*index)++;
			continue;
		}

		//usually ignore spaces
		if (lex[*lexi - 1] == ' ')
			(*lexi)--;

		// attribute key
		if (buf[*index] == '=')
		{
			lex[*lexi] = '\0';
			current_attr.key = ft_strdup(lex);
			*lexi = 0;
		}

		// attribute value
		if (buf[*index] == '"')
		{
			if (!current_attr.key)
			{
				return (TAG_START);
			}
			*lexi = 0;
			(*index)++;
			while (buf[*index] != '"')
				lex[(*lexi)++] = buf[(*index)++];
			lex[*lexi] = '\0';
			current_attr.value = ft_strdup(lex);
			xml_attrlist_add(&current_node->attributes, &current_attr);
			current_attr.key = NULL;
			current_attr.value = NULL;
			*lexi = 0;
			(*index)++;
			continue;
		}

		//Inline mode
		if (buf[*index - 1] == '/' && buf[*index] == '>')
		{
			lex[*lexi] = '\0';
			if (!current_node->tag)
				current_node->tag = ft_strdup(lex);
			(*index)++;
			return (TAG_INLINE);
		}
	}
	return (TAG_START);
}

size_t get_size(const char *path)
{
	int 	fd;
	size_t	size;
	size_t	temp;
	char	buf[4096];

	size = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("ERROR: Could not load file", 2);
		return (FALSE);
	}
	temp = read(fd, buf, 4096);
	while (temp > 0)
	{
		size += temp;
		temp = read(fd, buf, 4096);
	}
	if (close(fd) == -1)
	{
		ft_putendl_fd("ERROR: Couild not close file at get_size", 2);
		return (FALSE);
	}
	return (size);
}

int	xml_doc_load(t_xml_doc *doc, const char *path)
{
	int			fd;
	size_t		size;
	char		*buf;
	char		lex[256];
	int			lexi;
	int			index;
	t_xml_node	*current_node;
	t_xml_node	*desc;

	lexi = 0;
	index = 0;
	size = get_size(path);
	buf = (char *)malloc(sizeof(*buf) * size + 1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("ERROR: Could not load file", 2);
		return (FALSE);
	}
	if (read(fd, buf, size) == -1)
	{
		ft_putendl_fd("ERROR: Couild not read file", 2);
		return (FALSE);
	}
	buf[size] = '\0';
	if (close(fd) == -1)
	{
		ft_putendl_fd("ERROR: Could not close file at xml_doc_load", 2);
		return (FALSE);
	}
	doc->head = xml_node_new(NULL);
	current_node = doc->head;

	while (buf[index] != '\0')
	{
		if (buf[index] == '<')
		{
			lex[lexi] = '\0';

			//data
			if (lexi > 0)
			{
				if (!current_node)
				{
					ft_putendl_fd("ERROR: Text outside document", 2);
					return (FALSE);
				}
				if (!current_node->data){
				current_node->data = ft_strdup(lex);
				}
				lexi = 0;
			}

			//End of node
			if (buf[index + 1] == '/')
			{
				index += 2;
				while (buf[index] != '>')
					lex[lexi++] = buf[index++];
				lex[lexi] = '\0';

				if (!current_node)
				{
					ft_putendl_fd("ERROR: Already at head", 2);
					return (FALSE);
				}

				if (ft_strcmp(current_node->tag, lex))
				{
					ft_putstr_fd(current_node->tag, 2);
					ft_putstr_fd(" != ", 2);
					ft_putendl_fd(lex, 2);
					ft_putendl_fd("ERROR: Mismatched tags", 2);
					return (FALSE);
				}

				current_node = current_node->parent;
				index++;
				lexi = 0;
				continue;
			}

			// Special nodes - COMMENTS NEED MORE WORK
			if (buf[index + 1] == '!')
			{
				while (buf[index] != ' ' && buf[index] != '>')
					lex[lexi++] = buf[index++];
				lex[lexi] = '\0';
				 //comments - This while loop seems kinda stupid, make it better
				 if (!ft_strcmp(lex, "<!--"))
				 {
					while (!check_end(lex, "-->"))
					{
						lex[lexi++] = buf[index++];
						lex[lexi] = '\0';
					}
					continue;
				}
			}
			//declaration tags
			if (buf[index + 1] == '?')
			{
				while (buf[index] != ' ' && buf[index] != '>')
					lex[lexi++] = buf[index++];
				lex[lexi] = '\0';
				// This is XML declaration
				if (!ft_strcmp(lex, "<?xml"))
				{
					lexi = 0;
					desc = xml_node_new(NULL);
					parse_attr(buf, &index, lex, &lexi, desc);

					doc->version = ft_strdup(xml_node_attr_value(desc, "version"));
					doc->encoding = ft_strdup(xml_node_attr_value(desc, "encoding"));
					xml_node_free(desc);
					lexi = 0;
					index++;
					continue;
				}
			}

			//set current node
			current_node = xml_node_new(current_node);

			//start tag
			index++;
			if (parse_attr(buf, &index, lex, &lexi, current_node) == TAG_INLINE)
			{
				lexi = 0;
				current_node = current_node->parent;
				index++;
				continue;
			}

			//set tag name if none
			lex[lexi] = '\0';
			if (!current_node->tag)
				current_node->tag = ft_strdup(lex);

			//reset lexer
			lexi = 0;
			index++;
			continue;
		}
		else
		{
			lex[lexi++] = buf[index++];
			//ignore newlines and tabs
			if (lex[lexi - 1] == '\n' || lex[lexi - 1] == '\t')
				lexi--;
		}
	}
	return (TRUE);
}
