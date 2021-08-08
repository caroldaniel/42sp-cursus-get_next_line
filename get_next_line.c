/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:44:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/08 19:48:57 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*line_read = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!ft_strchr(line_read, '\n'))
	{
		if (!read_file(fd, buffer, line_read))
			return (NULL);
		free(buffer);		
	}
	put_line(line_read);
	return (line_read);
}

static int	read_file(int fd, char *buffer, char *line_read)
{
	ssize_t n;

	while (!ft_strchr(buffer, '\n'))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (0);
		if (n == 0)
			return (1);	
		if (n > 0)
			line_read = ft_strjoin(line_read, buffer);
	}
	ft_bzero(buffer, BUFFER_SIZE + 1);
	return (1);
}

void	put_line(char *line_read)
{
	size_t	i;

	i = 0;
	while (line_read[i] != '\n')
	{
		write(1, &line_read, 1);
		i++;
	}
	write(1, '\n', 1);
	line_read += i;
}
