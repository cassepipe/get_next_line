/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:48:06 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/07 18:31:41 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printbuffer(char *buffer, size_t size)
{
	char message[] = "Buffer :";
	write(1, message, sizeof message);
	size_t i = 0;
	while(i < size)
	{
		if (!buffer[i])
			write(1, "\\0", 2);
		else if (buffer[i] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &buffer[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	printline(char *buffer, size_t size)
{
	char message[] = "Line :";
	write(1, message, sizeof message);
	size_t i = 0;
	while(i < size)
	{
		if (!buffer[i])
			write(1, "\\0", 2);
		else if (buffer[i] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &buffer[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
