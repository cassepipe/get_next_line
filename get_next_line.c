#include "get_next_line.h"
#include <string.h>
#include <stdio.h>


static int	grow_buffer_until_newline(int fd, char **buffer,
										size_t *bufsize, char** newline)
{
	char		*old_buffer;
	char		*new_buffer;
	ssize_t		bytes_read;

	while(!(*newline = strchr(*buffer, '\n')))
	{
		new_buffer = malloc(BUFFER_SIZE + 1);
		if(!(bytes_read = read(fd, new_buffer, BUFFER_SIZE)))
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
		if(!(*buffer = ft_strjoin(old_buffer, new_buffer)))
			return (0);
		free(old_buffer);
		free(new_buffer);
		*bufsize += bytes_read;
		/*printbuffer(*buffer, *bufsize);*/
	}
	return (1);
}


int			get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		*temp;
	char		*newline;
	size_t		bufsize;
	long 		line_len;

	//Check initial
	if (fd < 0 || BUFFER_SIZE < 1
		|| (!buffer[fd] && (!(buffer[fd] = calloc(sizeof(char), BUFFER_SIZE + 1)))))
		return (-1);

	//Demande un buffer avec un \n dedans
	newline = NULL;
	bufsize = strlen(buffer[fd]) + 1;
	if (!grow_buffer_until_newline(fd, &buffer[fd], &bufsize, &newline))
		return (-1);
	line_len = newline ? (size_t)(newline - buffer[fd]) : bufsize;

	/*printf("buff is at %ld\n", buffer[fd]);*/
	/*printf("newline is at %ld\n", newline);*/
	/*printf("buff size = %zu\n", bufsize);*/
	/*printf("line size = %zu\n", line_len);*/

	//Copie le buffer dans line jusquau \n
	if (!(*line = ft_strndup(buffer[fd], line_len)))
		return (-1);

	//Recupere le reste du buffer apres le \n pour le prochain appel
	temp = buffer[fd];
	if (!(buffer[fd] = ft_strndup(newline + 1, bufsize - line_len))) //hypothesis : if !newline, line_len = bufsize, so we have strndup(nl, 0) --> returns empty string
		return (-1);
	free(temp);

	if (!newline)
		free(buffer[fd]);
	return (newline ? 1 : 0);
}
