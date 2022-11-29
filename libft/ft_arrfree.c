/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:04:49 by mmakinen          #+#    #+#             */
/*   Updated: 2022/05/06 10:50:21 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_arrfree(char **arr)
{
	int		i;
	char	*ptr;

	i = 0;
	while (arr[i])
	{
		ptr = arr[i];
		ft_strdel(&ptr);
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}
