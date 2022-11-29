/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:21:22 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/26 14:36:40 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*end;
	const char	*srcp;

	srcp = src;
	end = dst + size - 1;
	if (size != 0)
	{
		while (dst < end && *srcp != '\0')
		{
			*dst++ = *srcp++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}
