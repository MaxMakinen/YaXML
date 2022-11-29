/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:41:54 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/29 13:23:58 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	unsigned char	*end;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	end = str + n;
	while (str < end)
	{
		if (*str == ch)
		{
			return ((unsigned char *)str);
		}
		str++;
	}
	return (NULL);
}
