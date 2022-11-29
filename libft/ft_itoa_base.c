/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:55:28 by mmakinen          #+#    #+#             */
/*   Updated: 2022/05/11 12:04:17 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long num, int base, int *neg)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (base != 10)
		*neg = 2;
	while (num > 0)
	{
		len++;
		num /= base;
	}
	len += *neg;
	return (len);
}

static void	prefix(char *str, int base, int neg)
{
	if (base != 10)
	{
		str[0] = '0';
		if (base == 16)
			str[1] = 'x';
		if (base == 8)
			str[1] = 'o';
		if (base == 2)
			str[1] = 'b';
	}
	else if (neg == 1)
		str[0] = '-';
}

static void	check_neg(long *num, int *neg, int base)
{
	if (*num < 0)
	{
		*num *= -1;
		if (base == 10)
			*neg = 1;
	}
}

char	*ft_itoa_base(int num, int base)
{
	int		len;
	int		neg;
	long	temp;
	char	*key;
	char	*answer;

	key = "0123456789ABCDEF";
	temp = num;
	neg = 0;
	check_neg(&temp, &neg, base);
	len = get_len(temp, base, &neg);
	answer = (char *)ft_calloc(sizeof(char), len);
	if (!answer)
		exit(1);
	len--;
	prefix(answer, base, neg);
	while (len >= neg)
	{
		answer[len] = key[(int)(temp % base)];
		temp /= base;
		len--;
	}
	return (answer);
}
