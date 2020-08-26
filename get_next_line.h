/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:20:06 by tpouget           #+#    #+#             */
/*   Updated: 2020/08/26 19:01:04 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef SIZE_MAX
#  define SIZE_MAX 18446744073709551615U
# endif

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin_and_free(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		get_next_line(int fd, char **line);

void	printbuffer(char*, size_t);

#endif
