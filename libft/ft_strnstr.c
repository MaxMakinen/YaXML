/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:04:48 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 13:38:16 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	const char	*seeker;
	const char	*end;
	size_t		len;

	seeker = haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)seeker);
	len = ft_strlen(needle);
	end = seeker + n;
	while (*seeker != '\0' && seeker != end)
	{
		if (ft_strncmp(seeker, needle, len) == 0)
		{
			if ((seeker + len) <= end)
				return ((char *)seeker);
		}
		seeker++;
	}
	return (NULL);
}
