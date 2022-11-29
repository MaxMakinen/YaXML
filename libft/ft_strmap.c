/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:17:46 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/24 16:21:03 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		counter;
	char	*newstr;

	counter = 0;
	if (s != 0)
	{
		newstr = ft_strnew(ft_strlen(s));
		if (newstr == 0)
			return (NULL);
		while (s[counter] != '\0')
		{
			newstr[counter] = f(s[counter]);
			counter++;
		}
		newstr[counter] = '\0';
		return (newstr);
	}
	return (NULL);
}
