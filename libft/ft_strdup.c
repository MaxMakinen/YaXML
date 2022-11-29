/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:33:12 by mmakinen          #+#    #+#             */
/*   Updated: 2021/12/07 15:38:54 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1);
	str = ft_strnew(size);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1, size);
	return (str);
}
