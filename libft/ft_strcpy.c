/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:50:40 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 10:48:06 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*dstp;
	unsigned char	*srcp;

	dstp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	while (*srcp != '\0')
	{
		*dstp++ = *srcp++;
	}
	*dstp = *srcp;
	return (dst);
}
