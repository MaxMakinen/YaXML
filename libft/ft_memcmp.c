/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:57:31 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/19 12:04:18 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pointer1;
	const unsigned char	*pointer2;
	const unsigned char	*end1;
	int					test;

	test = 0;
	pointer1 = s1;
	pointer2 = s2;
	end1 = s1 + n;
	while (test == 0 && pointer1 < end1)
	{
		test = (int)*pointer1++ - (int)*pointer2++;
	}
	return (test);
}
