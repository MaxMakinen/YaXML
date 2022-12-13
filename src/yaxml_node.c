/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yaxml_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:35:23 by mmakinen          #+#    #+#             */
/*   Updated: 2022/11/29 10:35:25 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yaxml.h"

t_xml_node	*xml_node_new(t_xml_node *parent)
{
	t_xml_node	*new;

	new = (t_xml_node *)malloc(sizeof(t_xml_node));
	new->parent = parent;
	new->tag = NULL;
	new->data = NULL;
	xml_attrlist_init(&new->attributes);
	xml_nodelist_init(&new->children);
	if (parent)
		xml_nodelist_add(&parent->children, new);
	return (new);
}

t_xml_node	*xml_node_child(t_xml_node *parent, int index)
{
	return (parent->children.list[index]);
}

t_xml_nodelist	*xml_node_children(t_xml_node *parent, const char *tag)
{
	t_xml_nodelist	*list;
	t_xml_node		*child;
	int				index;

	index = 0;
	list = (t_xml_nodelist *)malloc(sizeof(t_xml_nodelist));
	xml_nodelist_init(list);
	while (index < parent->children.size)
	{
		child = parent->children.list[index];
		if (!ft_strcmp(child->tag, tag))
			xml_nodelist_add(list, child);
		index++;
	}
	return (list);
}

char	*xml_node_attr_value(t_xml_node *node, char *key)
{
	t_xml_attr	attr;
	int			index;

	index = 0;
	while (index < node->attributes.size)
	{
		attr = node->attributes.list[index];
		if (attr.key != 0 && !ft_strcmp(attr.key, key))
			return (attr.value);
		index++;
	}
	return (NULL);
}

t_xml_attr	*xml_node_attr(t_xml_node *node, char *key)
{
	t_xml_attr	*attr;
	int			index;

	index = 0;
	while (index < node->attributes.size)
	{
		attr = &node->attributes.list[index];
		if (!ft_strcmp(attr->key, key))
			return (attr);
		index++;
	}
	return (NULL);
}
