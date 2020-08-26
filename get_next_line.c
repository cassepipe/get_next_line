/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:55:59 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/26 16:52:15 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

static int	grow_buffer_until_newline(int fd, char **buffer,
									size_t *bufsize, char **newline)
{
	char		*new_buffer;
	ssize_t		bytes_read;

	printbuffer(*buffer, *bufsize);
	while (!(*newline = ft_strchr(*buffer, '\n')))
	{
		if (!(new_buffer = malloc(BUFFER_SIZE + 1)))
			return (0);
		if (!(bytes_read = read(fd, new_buffer, BUFFER_SIZE)))
		{
			free(new_buffer);
			return (1);
		}
		else if (bytes_read < 0)
		{
			free(new_buffer);
			return (0);
		}
		new_buffer[bytes_read] = '\0';
		if (!(*buffer = ft_strjoin_and_free(*buffer, new_buffer)))
			return (0);
		*bufsize += bytes_read;
		printbuffer(*buffer, *bufsize);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		*newline;
	size_t		bufsize;
	long		line_len;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!buffer[fd] && !(buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	newline = NULL;
	bufsize = ft_strlen(buffer[fd]) + 1;
	if (!grow_buffer_until_newline(fd, &buffer[fd], &bufsize, &newline))
		return (-1);
	line_len = newline ? (size_t)(newline - buffer[fd]) : bufsize;
	if (!(*line = malloc(line_len + 1)))
		return (-1);
	ft_memmove(*line, buffer[fd], line_len);
	(*line)[line_len] = 0;
	printbuffer(buffer[fd], bufsize);
	if(newline)
		ft_memmove(buffer[fd], newline + 1, bufsize - line_len - 1);
	if (!newline)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (newline ? 1 : 0);
}
