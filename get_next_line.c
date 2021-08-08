/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:44:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/08 20:43:09 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int		read_file(int fd, char *buffer, char *line_read);
char	*put_line(char *line_read);

char *get_next_line(int fd)
{
	static char	line_read[1] = "\0";
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!ft_strchr(line_read, '\n'))
	{
		if (!read_file(fd, buffer, line_read))
			return (NULL);
	}
	free(buffer);		
	line = put_line(line_read);
	return (line);
}

int	read_file(int fd, char *buffer, char *line_read)
{
	ssize_t n;

	while (!ft_strchr(line_read, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (0);
		if (n == 0)
			return (1);	
		if (n > 0)
			line_read = ft_strjoin(line_read, buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	return (1);
}

char	*put_line(char *line_read)
{
	size_t	i;
	char	nl;
	char	*line;
	
	i = 0;
	nl = '\n';
	while (line_read[i] != '\n')
	{
		write(1, &line_read, 1);
		i++;
	}
	write(1, &nl, 1);
	line = (char *)malloc((i + i) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, line_read, i);
	line_read += i;
	return (line);
}
