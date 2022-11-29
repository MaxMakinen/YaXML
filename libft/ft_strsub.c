/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:54:09 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 14:08:45 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	counter;

	counter = 0;
	if (s == 0)
		return (NULL);
	newstr = ft_strnew(len);
	if (newstr == 0)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (counter < len)
		{
			newstr[counter] = s[start + counter];
			counter++;
		}
	}
	return (newstr);
}
