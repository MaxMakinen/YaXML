/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:23:44 by mmakinen          #+#    #+#             */
/*   Updated: 2022/05/06 13:12:13 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexval(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (c);
}

static long	hextoi(const char *nptr)
{
	long	value;

	value = 0x0;
	nptr += 2;
	while (*nptr != 0 && ft_isxdigit(*nptr) != 0)
		value = value * 16 + hexval(*nptr++);
	return (value);
}

int	ft_atoi(const char *nptr)
{
	long	value;
	int		negative;

	value = 0;
	negative = 1;
	while (ft_isspace(*nptr) == 1)
		nptr++;
	if (nptr[0] == '-' || nptr[0] == '+')
	{
		if (nptr[0] == '-')
			negative = -1;
		nptr++;
	}
	if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X'))
		value = hextoi(nptr);
	else
	{
		while (*nptr != 0 && (ft_isdigit(*nptr) != 0))
			value = value * 10 + (*nptr++ - '0');
	}
	return ((int)(value * negative));
}
