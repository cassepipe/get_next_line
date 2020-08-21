/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:55:59 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/21 18:02:43 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	grow_buffer_until_newline(int fd, char **buffer,
									size_t *bufsize, char **newline)
{
	char		*old_buffer;
	char		*new_buffer;
	ssize_t		bytes_read;

	while (!(*newline = ft_strchr(*buffer, '\n')))
	{
		new_buffer = malloc(BUFFER_SIZE + 1);
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
		old_buffer = *buffer;
		if (!(*buffer = ft_strjoin(old_buffer, new_buffer)))
			return (0);
		free(old_buffer);
		free(new_buffer);
		*bufsize += bytes_read;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		*temp;
	char		*newline;
	size_t		bufsize;
	long		line_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!buffer[fd] && (!(buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char)))))
		return (-1);
	newline = NULL;
	bufsize = ft_strlen(buffer[fd]) + 1;
	if (!grow_buffer_until_newline(fd, &buffer[fd], &bufsize, &newline))
		return (-1);
	line_len = newline ? (size_t)(newline - buffer[fd]) : bufsize;
	if (!(*line = ft_strndup(buffer[fd], line_len)))
		return (-1);
	temp = buffer[fd];
	if (!(buffer[fd] = ft_strndup(newline + 1, bufsize - line_len)))
		return (-1);
	free(temp);
	if (!newline)
		free(buffer[fd]);
	return (newline ? 1 : 0);
}
