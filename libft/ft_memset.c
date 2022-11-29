/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:41:58 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/23 11:09:46 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*copy;
	unsigned char	*end;

	copy = (unsigned char *)s;
	end = copy + len;
	while (copy < end)
	{
		*copy++ = (unsigned char)c;
	}
	return (s);
}
