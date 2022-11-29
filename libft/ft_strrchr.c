/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:07:52 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/01 13:34:25 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*seeker;
	const char	*last;

	seeker = s;
	last = NULL;
	while (*seeker != '\0')
	{
		if (*seeker == (char)c)
			last = seeker;
		seeker++;
	}
	if ((char)c == '\0')
		return ((char *)seeker);
	return ((char *)last);
}
