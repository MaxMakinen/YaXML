/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:51:38 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/09 15:03:31 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}

static char const	*beginning(char const *s)
{
	char const	*pos;

	pos = s;
	while (*pos != '\0')
	{
		if (iswhitespace(*pos) == 0)
			return (pos);
		pos++;
	}
	return (s);
}

static char const	*ending(char const *s)
{
	char const	*pos;
	int			counter;

	pos = s;
	counter = 0;
	while (*pos != '\0')
	{
		while (iswhitespace(*pos) == 1)
		{
			counter++;
			pos++;
		}
		if (*pos == '\0')
			return (pos - counter);
		counter = 0;
		pos++;
	}
	return (pos);
}

char	*ft_strtrim(char const *s)
{
	char		*newstr;
	int			len;
	char const	*start;
	char const	*end;
	int			counter;

	counter = 0;
	if (s == 0)
		return (NULL);
	start = beginning(s);
	end = ending(s);
	len = end - start;
	newstr = ft_strnew(len);
	if (newstr == 0)
		return (NULL);
	while (counter < len)
	{
		newstr[counter] = (char)start[counter];
		counter++;
	}
	return (newstr);
}
