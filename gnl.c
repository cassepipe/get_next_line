#include "get_next_line.h"
#include <string.h>

/*char *	find_newline_or_read(char **buffer, size_t *bufsize)*/
/*{*/
/*}*/


int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*temp;
	char		*newline;
	ssize_t		bytes_read;
	size_t 	bufsize;
	size_t 	line_size;

	if (fd < 0 || BUFFER_SIZE < 1
		|| (!buffer && (!(buffer = calloc(sizeof(char), BUFFER_SIZE + 1)))))
		return (-1);
	bufsize = strlen(buffer) + 1;
	while(!(newline = strchr(buffer, '\n')))
	{
		temp = malloc(BUFFER_SIZE + 1);
		if(!(bytes_read = read(fd, temp, BUFFER_SIZE)))
			break;
		else if (bytes_read < 0)
			return (-1);
		buffer[BUFFER_SIZE] = '\0';
		if(!(buffer = ft_strjoin(buffer, temp)))
			return (-1);
		free(temp);
		bufsize += bytes_read;
	}
	line_size = newline ? bufsize - BUFFER_SIZE + (newline - buffer) : bufsize;
	temp = *line;
	if (!(*line = strndup(buffer, line_size)))
		return (-1);
	free(temp);
	temp = buffer;
	if (!(buffer = strndup(++newline, bufsize - line_size))) //hypothesis : if !newline, line_size = bufsize, so we have strndup(nl, 0) --> returns empty string ?
		return (-1);
	free(temp);
	return (newline ? 0 : 1);
}
