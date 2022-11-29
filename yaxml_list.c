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

void	*resize_memory(void *ptr, size_t size)
{
	void	*new;
	size_t	ptr_size;

	new = malloc(size);
	if (new == NULL || (size <= 0 && ptr != NULL))
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (ptr == 0)
		return (new);
	ptr_size = ((size_t *) ptr)[-1];
	if (size > ptr_size)
		size = ptr_size;
	ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}

void	xml_attrlist_init(t_xml_attrlist *list)
{
	list->memory_size = 1;
	list->size = 0;
	list->list = (t_xml_attr *)malloc(sizeof(t_xml_attr) * list->memory_size);
}

void	xml_attrlist_add(t_xml_attrlist *list, t_xml_attr *attr)
{
	if (list->size >= list->memory_size)
	{
		list->memory_size *= 2;
		list->list = (t_xml_attr *)resize_memory(list->list, \
		sizeof(t_xml_attr) * list->memory_size);
	}
	list->list[list->size++] = *attr;
}

void	xml_nodelist_init(t_xml_nodelist *list)
{
	list->memory_size = 1;
	list->size = 0;
	list->list = (t_xml_nodelist *)malloc(sizeof(t_xml_nodelist) * list->memory_size);
}

void	xml_nodelist_add(t_xml_nodelist *list, t_xml_node *node)
{
	if (list->size >= list->memory_size)
	{
		list->memory_size *= 2;
		list->list = (t_xml_node *)resize_memory(list->list, \
		sizeof(t_xml_node) * list->memory_size);
	}
	list->list[list->size++] = node;
}

t_xml_node	*xml_nodelist_at(t_xml_nodelist *list, int index)
{
	return (list->list[index]);
}