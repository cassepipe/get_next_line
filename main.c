#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line = NULL;
	FILE *file;
	file = fopen("input.txt", "r");
	int fd = fileno(file);
	int ret;

	for (int i = 0;  i < 9; i++)
	{
		ret = get_next_line(fd, &line);
		printf("Function returned %d\n", ret);
		//printbuffer(line, ft_strlen(line));
		*line ? printf("[%d] %s\n", ret, line) : printf("[%d] Empty string\n", ret);
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
	/*//	printf("%s\n", line);*/
		/*fprintf(dest, "%s\n", line);*/
		/*free(line);*/
		/*line = NULL;*/
	/*}*/
	/*//printf("%s", line);*/
	/*[>fprintf(dest, "%s", line);<]*/
	/*[>free(line);<]*/

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
		/*//printf("%s\n", lines[i]);*/
		/*fprintf(dest, "%s\n", lines[i]);*/
	/*}*/
	/*fclose(src1);*/
	/*fclose(src2);*/
	/*fclose(src3);*/
	/*fclose(dest);*/
/*}*/

