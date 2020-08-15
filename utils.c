/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:39 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/08 17:03:11 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*duplicate;

	i = 0;
	duplicate = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!duplicate)
		return (NULL);
	while (s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !*s1)
		return (ft_strdup(s2));
	if (!s2 || !*s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = malloc(len + 1)))
		return (NULL);
	ft_strlcpy(joined, s1, len + 1);
	i = 0;
	while (i < len + 1 && joined[i])
		i++;
	ft_strlcpy(joined + i, s2, len + 1 - i);
	return (joined);
}
