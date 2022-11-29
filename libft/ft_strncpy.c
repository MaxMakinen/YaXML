/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:59:16 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 10:49:50 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned char	*dstp;
	unsigned char	*srcp;
	unsigned char	*end;

	if (len != 0)
	{
		dstp = (unsigned char *)dst;
		srcp = (unsigned char *)src;
		end = dstp + len;
		while (*srcp != '\0' && dstp < end)
			*dstp++ = *srcp++;
		while (dstp < end)
			*dstp++ = '\0';
	}
	return (dst);
}
