/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbuffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:48:06 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/16 09:59:57 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static long	ft_10powerof(long n)
{
	long result;

	result = 1;
	while (n--)
		result *= 10;
	return (result);
}

char		*ft_itoa(int n)
{
	long nbr;
	long digit;
	long i;
	long len;
	char *result;

	len = 1;
	nbr = n < 0 ? -1 * (long)n : n;
	i = nbr;
	while (i /= 10)
		len++;
	result = n < 0 ? malloc(len + 2) : malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
		result[i++] = '-';
	while (--len >= 0)
	{
		digit = nbr / ft_10powerof(len);
		result[i++] = digit + '0';
		nbr = nbr - digit * ft_10powerof(len);
	}
	result[i] = '\0';
	return (result);
}
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
			write(1, "\\", 2);
		else
			write(1, &buffer[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	char index_message[] = "Size   :";
	write(1, index_message, sizeof index_message);
	i = 0;
	int j = 1;
	while (i < size)
	{
		if (j >= 10)
			j = 0;
		char *tmp = ft_itoa(j);
		write(1, tmp, strlen(tmp));
		free(tmp);
		write(1, " ", 1);
		i++;
		j++;
	}
	write(1, "\n", 1);
	char blank[] = "        ";
	write(1, blank, sizeof blank);
	i = 0;
	j = 1;
	while (i < size)
	{
		if (j >= 10)
			j = 0;
		if (!j)
			write(1, "|", 1);
		else
			write(1, " ", 1);
		write(1, " ", 1);
		i++;
		j++;
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
