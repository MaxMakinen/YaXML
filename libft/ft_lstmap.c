/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:53:19 by mmakinen          #+#    #+#             */
/*   Updated: 2022/01/03 17:17:33 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*eraser(t_list *lst)
{
	t_list	*temp;

	while (lst != 0)
	{
		temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*node;
	t_list	*head;

	head = f(lst);
	if (head == NULL)
		return (NULL);
	node = head;
	while (lst->next != 0)
	{
		node->next = f(lst->next);
		if (node->next == NULL)
			return (eraser(head));
		node = node->next;
		lst = lst->next;
	}
	return (head);
}
