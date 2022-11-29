/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:54:42 by mmakinen          #+#    #+#             */
/*   Updated: 2022/04/28 17:57:00 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_base(int c, int base)
{
	if (base == 10)
		return (ft_isdigit(c));
	if (base == 2)
		return (ft_isbdigit(c));
	if (base == 8)
		return (ft_isodigit(c));
	if (base == 16)
		return (ft_isxdigit(c));
	return (0);
}
