#include "get_next_line.h"
#include <string.h>
#include "printbuffer.c"
#include <stdio.h>


static int grow_buffer_until_newline(int fd, char **buffer,
										size_t *bufsize, char** newline)
{
	char		*new_buffer;
	ssize_t		bytes_read;

	while(!(*newline = strchr(*buffer, '\n')))
	{
		puts("Hello !\n");
		new_buffer = malloc(BUFFER_SIZE + 1);
		if(!(bytes_read = read(fd, new_buffer, BUFFER_SIZE)))
			break;
		else if (bytes_read < 0)
			return (0);
		new_buffer[bytes_read] = '\0';
		if(!(*buffer = ft_strjoin(*buffer, new_buffer)))
			return (0);
		free(new_buffer);
		*bufsize += bytes_read;
		printbuffer(*buffer, *bufsize);
	}
	return (1);
}


int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*temp;
	char		*newline;
	size_t 	bufsize;
	size_t 	line_size;

	if (fd < 0 || BUFFER_SIZE < 1
		|| (!buffer && (!(buffer = calloc(sizeof(char), BUFFER_SIZE + 1)))))
		return (-1);
	puts("salut\n");
	newline = NULL;
	bufsize = strlen(buffer) + 1;
	if (!grow_buffer_until_newline(fd, &buffer, &bufsize, &newline))
		return (-1);
	line_size = newline ? bufsize - BUFFER_SIZE + (newline - buffer) : bufsize;
	temp = *line;
	if (!(*line = ft_strndup(buffer, line_size)))
		return (-1);
	free(temp);
	temp = buffer;
	if (!(buffer = ft_strndup(++newline, bufsize - line_size))) //hypothesis : if !newline, line_size = bufsize, so we have strndup(nl, 0) --> returns empty string ?
		return (-1);
	free(temp);
	puts("Ciao\n");
	return (newline ? 1 : 0);
}

int main(void)
{
	char *line;
	FILE *file;
	file = fopen("input.txt", "r");
	int fd = fileno(file);
	int ret;

	for (int i = 0;  i < 3; i++)
	{
		ret = get_next_line(fd, &line);
		*line ? printf("%s\n", line) : printf("Empty string\n");
		printf("Function returned %d\n", ret);
		free(line);
	}
	fclose(file);
	return (0);
}

/*int main(void)*/
/*{*/

	/*FILE *dest =  fopen("output.txt", "w");*/

	/*char *line = NULL;*/
	/*FILE *src = fopen("input.txt", "r");*/
	/*int fd = fileno(src);*/

	/*while (get_next_line(fd, &line))*/
	/*{*/
		/*printf("%s\n", line);*/
		/*fprintf(dest, "%s\n", line);*/
		/*free(line);*/
		/*line = NULL;*/
	/*}*/
	/*[>printf("%s", line);<]*/
	/*[>fprintf(dest, "%s", line);<]*/
	/*free(line);*/

	/*fclose(src);*/
	/*return (0);*/
/*}*/

/*int main(void)*/
/*{*/
	/*FILE *dest =  fopen("output.txt", "a");*/

	/*static char *lines[3];*/
	/*FILE *src1 = fopen("1.txt", "r");*/
	/*FILE *src2 = fopen("2.txt", "r");*/
	/*FILE *src3 = fopen("3.txt", "r");*/
	/*int fds[3];*/
	/*fds[0] = fileno(src1);*/
	/*fds[1] = fileno(src2);*/
	/*fds[2] = fileno(src3);*/

	/*for (int i = 0;  i < 3; i++)*/
	/*{*/
		/*int j = 0;*/
		/*while(j <= i)*/
		/*{*/
			/*get_next_line(fds[i], &lines[j]);*/
			/*j++;*/
		/*}*/
		/*[>printf("%s\n", lines[i]);<]*/
		/*fprintf(dest, "%s\n", lines[i]);*/
	/*}*/
	/*fclose(src1);*/
	/*fclose(src2);*/
	/*fclose(src3);*/
	/*fclose(dest);*/
/*}*/

