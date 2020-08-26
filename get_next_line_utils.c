/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:39 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/26 19:00:51 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*memory;
	size_t	i;
	size_t	total_size;

	total_size = nmemb * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	value;
	char			*ptr;

	value = (unsigned char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == value)
			return (ptr);
		ptr++;
	}
	if (!c)
		return (ptr);
	else
		return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size > 0)
	{
		while (src[i])
		{
			if (i + 1 == size)
				break ;
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin_and_free(char const *s1, char const *s2)
{
	size_t	len;
	ssize_t	i;
	ssize_t	j;
	char	*joined;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = malloc(len + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	free((void*)s1);
	free((void*)s2);
	return (joined);
}
