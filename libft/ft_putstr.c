/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:32:32 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 14:37:57 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	unsigned char	*uc;

	uc = (unsigned char *)s;
	if (s != 0)
	{
		write(1, uc, ft_strlen(s));
	}
}
