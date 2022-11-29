/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakinen <mmakinen@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:27:44 by mmakinen          #+#    #+#             */
/*   Updated: 2022/01/10 15:28:10 by mmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	newline(const char *memory, char **line)
{
	size_t	finder;

	finder = 0;
	while (memory[finder] != '\n' && memory[finder] != '\0')
		finder++;
	if (memory[finder] == '\n')
	{
		*line = ft_strsub(memory, 0, finder);
		if (!*line)
			return (-1);
		return (finder + 1);
	}
	return (0);
}

static int	cleanup(char **memory, int bytes, char **buffer)
{	
	ft_strdel(buffer);
	if (bytes < 0)
		return (bytes);
	ft_strncpy(*memory, *memory + bytes, ft_strlen(*memory));
	return (1);
}

static int	last_line(char **line, char **memory, char **buffer, int bytes)
{
	int	check;

	ft_strdel(buffer);
	if (bytes < 0)
		return (bytes);
	check = 0;
	if (bytes == 0 && *memory && *memory[0] != '\n' && *memory[0])
	{
		*line = ft_strdup(*memory);
		if (!*line)
		{
			ft_strdel(memory);
			return (-1);
		}
		check = 1;
	}
	ft_strdel(memory);
	return (check);
}

static int	read_file(char **memory, char **line, char *buffer)
{
	char	*temp;

	temp = *memory;
	*memory = ft_strjoin(*memory, (const char *)buffer);
	if (!*memory)
		return (-1);
	free(temp);
	ft_bzero(buffer, BUFF_SIZE);
	return (newline(*memory, line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*memory[MAX_FD];
	char		*buffer;
	int			bytes;

	if (fd < 0 || fd >= MAX_FD || !line)
		return (-1);
	buffer = ft_strnew(BUFF_SIZE);
	if (!buffer)
		return (-1);
	if (memory[fd])
	{
		bytes = newline(memory[fd], line);
		if (bytes != 0)
			return (cleanup(&memory[fd], bytes, &buffer));
	}
	bytes = read(fd, buffer, BUFF_SIZE);
	while (bytes > 0)
	{
		bytes = read_file(&memory[fd], line, buffer);
		if (bytes != 0)
			return (cleanup(&memory[fd], bytes, &buffer));
		bytes = read(fd, buffer, BUFF_SIZE);
	}
	return (last_line (line, &memory[fd], &buffer, bytes));
}
