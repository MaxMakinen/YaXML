/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaxml_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:59:39 by mmakinen          #+#    #+#             */
/*   Updated: 2022/11/29 10:59:40 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yaxml.h"

void	*resize_memory(void *ptr, size_t size, size_t old_size)
{
	void	*new;

	new = malloc(size);
	if (new == NULL || (size <= 0 && ptr != NULL))
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (ptr == 0)
		return (new);
	if (size < old_size)
		old_size = size;
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}

int	xml_comment(const char *buf, int *index)
{
	if (buf[*index + 2] == '\0' || buf[*index + 3] == '\0' || \
		buf[*index + 2] != '-' || buf[*index + 3] != '-')
		return (FALSE);
	while (buf[*index] != '\0')
	{
		while (buf[*index] != '\0' && buf[*index] != '>')
			(*index)++;
		if (buf[*index] == '\0')
			return (FALSE);
		else if (buf[*index] == '>' && buf[*index - 1] == '-' && \
		buf[*index - 2] == '-')
			return (TRUE);
		else
			(*index)++;
	}
	return (FALSE);
}

int	xml_declaration(const char *buf, int *index, t_xml_doc *doc)
{
	t_xml_node	*desc;
	char		lex[1024];

	while (buf[index[0]] != '\0' && buf[index[0]] != ' ' && \
	buf[index[0]] != '>')
		lex[index[1]++] = buf[index[0]++];
	lex[index[1]] = '\0';
	if (!ft_strcmp(lex, "<?xml"))
	{
		index[1] = 0;
		desc = xml_node_new(NULL);
		parse_attr(buf, index, lex, desc);
		doc->version = ft_strdup(\
		xml_node_attr_value(desc, "version"));
		doc->encoding = ft_strdup(\
		xml_node_attr_value(desc, "encoding"));
		xml_node_free(desc);
		index[1] = 0;
		index[0]++;
		return (TRUE);
	}
	return (FALSE);
}
