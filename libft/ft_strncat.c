/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:44:42 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 10:52:16 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*printer;
	const char	*reader;
	const char	*end2;

	if (n != 0)
	{
		printer = s1;
		reader = s2;
		end2 = s2 + n;
		while (*printer != '\0')
			printer++;
		while (reader < end2 && *reader != '\0')
			*printer++ = *reader++;
		*printer = '\0';
	}
	return (s1);
}
