/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:30:37 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 10:35:58 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*srcp;
	unsigned char	*dstp;

	srcp = (unsigned char *)src;
	dstp = (unsigned char *)dst;
	if (dst == src)
		return (0);
	if (srcp < dstp && srcp + len > dstp)
	{
		srcp += len;
		dstp += len;
		while (len-- != 0)
		{
			*--dstp = *--srcp;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
