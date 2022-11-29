/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:33:23 by mmakinen          #+#    #+#             */
/*   Updated: 2022/05/05 13:17:25 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(const char *str, int base)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_isprefix(&str[i], base))
		return (FALSE);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i += 1;
	else if (base == 10 && (str[i] == '+' || str [i] == '-'))
		i += 1;
	while (str[i])
	{
		if (!ft_isdigit_base(str[i], base))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
