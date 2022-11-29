/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:32:21 by mmakinen          #+#    #+#             */
/*   Updated: 2022/05/05 13:17:42 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprefix(const char *str, int base)
{
	int	i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (FALSE);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (TRUE);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (TRUE);
		if (base == 8)
			return (TRUE);
	}
	return (FALSE);
}
