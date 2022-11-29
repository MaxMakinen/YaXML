/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:28:33 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/19 11:18:49 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*printer;
	const char	*reader;

	printer = s1;
	reader = s2;
	while (*printer != '\0')
		printer++;
	while (*reader != '\0')
		*printer++ = *reader++;
	*printer = '\0';
	return (s1);
}
