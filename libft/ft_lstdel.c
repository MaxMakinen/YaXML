/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:23:34 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/29 15:17:57 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*temp;

	if (alst != 0)
	{
		node = *alst;
		while (node != 0)
		{
			temp = node->next;
			del(node->content, node->content_size);
			node->next = NULL;
			free(node);
			node = temp;
		}
		node = NULL;
		*alst = NULL;
	}
}
