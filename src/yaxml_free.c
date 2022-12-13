/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaxml_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:17:15 by mmakinen          #+#    #+#             */
/*   Updated: 2022/11/29 10:17:17 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "yaxml.h"

void	xml_attr_free(t_xml_attr *attr)
{
	if (attr->key)
		free(attr->key);
	if (attr->value)
		free(attr->value);
}

void	xml_nodelist_free(t_xml_nodelist *list)
{
	free(list);
}

void	xml_node_free(t_xml_node *node)
{
	int	index;

	index = 0;
	if (node->tag)
		free(node->tag);
	if (node->data)
		free(node->data);
	while (index < node->attributes.size)
	{
		xml_attr_free(&node->attributes.list[index]);
		index++;
	}
	free(node);
}

void	xml_doc_free(t_xml_doc *doc)
{
	if (doc->version)
		free(doc->version);
	if (doc->encoding)
		free(doc->encoding);
	xml_node_free(doc->head);
}
