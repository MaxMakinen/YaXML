/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:46:15 by mmakinen          #+#    #+#             */
/*   Updated: 2022/01/03 16:23:48 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*strnew;

	strnew = (char *)malloc(sizeof(char) * (size + 1));
	if (strnew == 0)
		return (NULL);
	ft_bzero(strnew, size + 1);
	return (strnew);
}
