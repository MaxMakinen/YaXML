/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:21:42 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 10:17:53 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstp;
	const char			*srcp;
	const char			*end;

	if (n == 0 || dst == src)
		return (dst);
	dstp = (unsigned char *)dst;
	srcp = (const char *)src;
	end = srcp + n;
	while (srcp < end)
	{
		*dstp++ = *srcp++;
	}
	return (dst);
}
