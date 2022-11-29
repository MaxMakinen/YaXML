/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:30:11 by mmakinen          #+#    #+#             */
/*   Updated: 2022/01/05 12:55:10 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*srcp;
	unsigned char	*dstp;
	unsigned char	*end;

	if (!dst || !src || dst == src)
		return (NULL);
	srcp = (unsigned char *)src;
	dstp = (unsigned char *)dst;
	end = srcp + n;
	while (srcp < end)
	{
		*dstp++ = *srcp;
		if (*srcp++ == (unsigned char)c)
			return (dstp);
	}
	return (NULL);
}
