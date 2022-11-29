/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:52:06 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/24 10:51:43 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (n == 0 || !s1 || !s2)
		return (0);
	while (counter < n)
	{
		if (s1[counter] != s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		if (s1[counter] == '\0')
			return (0);
		counter++;
	}
	return (0);
}
