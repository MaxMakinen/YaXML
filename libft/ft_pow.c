/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:56:34 by mmakinen          #+#    #+#             */
/*   Updated: 2022/06/20 16:57:40 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow(size_t num, size_t pow)
{
	size_t	temp;

	if (pow == 0)
		return (0);
	temp = num;
	while (pow > 0)
	{
		num *= temp;
		pow--;
	}
	return (num);
}
