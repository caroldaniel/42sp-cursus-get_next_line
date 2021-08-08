/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:28:24 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/08 19:48:54 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char		*get_next_line(int fd);

// get_next_line subfunctions
static int	read_file(int fd, char *buffer, char *line_read);
void		put_line(char *line_read);

// utils
void		ft_bzero(void *s, size_t n);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
