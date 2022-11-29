/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:26:08 by mmakinen          #+#    #+#             */
/*   Updated: 2021/11/24 15:42:11 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*seeker;
	size_t		len;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	seeker = haystack;
	while (*seeker != '\0')
	{
		if (ft_strncmp(seeker, needle, len) == 0)
			return ((char *)seeker);
		seeker++;
	}
	return (NULL);
}
