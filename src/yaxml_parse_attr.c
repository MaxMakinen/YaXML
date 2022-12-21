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

int	tag_name(int index[2], char *lex, t_xml_node *current_node)
{
	lex[index[1]] = '\0';
	current_node->tag = ft_strdup(lex);
	index[1] = 0;
	index[0]++;
	return (TRUE);
}

int	attribute_key(const char *buf, char *lex, int index[2], t_xml_node *current_node)
{
	t_xml_attr	current_attr;

	current_attr.key = 0;
	current_attr.value = 0;
	lex[index[1]] = '\0';
	current_attr.key = ft_strdup(lex);
	index[1] = 0;
	lex[index[1]++] = buf[index[0]++];
	if (buf[index[0]] == '"')
	{
		index[1] = 0;
		index[0]++;
		while (buf[index[0]] != '"')
			lex[index[1]++] = buf[index[0]++];
		lex[index[1]] = '\0';
		current_attr.value = ft_strdup(lex);
		xml_attrlist_add(&current_node->attributes, &current_attr);
		index[1] = 0;
		index[0]++;
		return (TRUE);
	}
	free(current_attr.key);
	return (FALSE);
}

t_tag_type	inline_mode(int *index, char *lex, t_xml_node *current_node)
{
	lex[index[1]] = '\0';
	if (!current_node->tag)
		current_node->tag = ft_strdup(lex);
	index[0]++;
	return (TAG_INLINE);
}

t_tag_type	parse_attr(const char *buf, int index[2], char *lex, \
t_xml_node *current_node)
{
	while (buf[index[0]] != '>')
	{
		lex[index[1]++] = buf[index[0]++];
		if (buf[index[0]] == ' ' && !current_node->tag && \
		tag_name(index, lex, current_node))
			continue ;
		if (lex[index[1] - 1] == ' ')
			index[1]--;
		if (buf[index[0]] == '=')
		{
			if (attribute_key(buf, lex, index, current_node))
				continue ;
		}
		if (buf[index[0]] == '"')
			return (TAG_START);
		if (buf[index[0] - 1] == '/' && buf[index[0]] == '>')
			return (inline_mode(index, lex, current_node));
	}
	return (TAG_START);
}
