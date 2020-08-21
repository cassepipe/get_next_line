/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:39 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/21 17:39:56 by tpouget          ###   ########.fr       */
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
		return NULL;
	i = 0;
	while(i < total_size)
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

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*duplicate;

	i = 0;
	len = 0;
	if (n)
		while (len < n && s[len])
			len++;
	duplicate = malloc(len + 1);
	if (!duplicate)
		return (NULL);
	while (i < len)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	ssize_t	i;
	ssize_t	j;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !*s1)
		return (ft_strndup(s2, SIZE_MAX));
	if (!s2 || !*s2)
		return (ft_strndup(s1, SIZE_MAX));
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
	return (joined);
}
