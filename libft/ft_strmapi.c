/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:35:36 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/26 14:36:12 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*newstr;

	counter = 0;
	if (s == 0)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	if (newstr == NULL)
		return (NULL);
	while (s[counter] != '\0')
	{
		newstr[counter] = f(counter, s[counter]);
		counter++;
	}
	return (newstr);
}
