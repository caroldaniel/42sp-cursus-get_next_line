/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:44:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/10 00:31:44 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int		read_file(int fd, char *buffer, char **buff_read);
char	*get_line(char *buff_read, char **line);

char	*get_next_line(int fd)
{
	static char		*buff_read = "";
	char			*buffer;
	char			*line;
	ssize_t			n;

	n = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!ft_strchr(buff_read, '\n'))
	{
		n = read_file(fd, buffer, &buff_read);
		if (n < 0)
			return (NULL);
	}
	if (ft_strchr(buff_read, '\n') || !n)
		buff_read = get_line(buff_read, &line);
	if (!n)
		return (NULL);
	return (line);
}

int	read_file(int fd, char *buffer, char **buff_read)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(*buff_read, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (n);
}

char	*get_line(char *buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = "(null)";
	while ((*(buff_read + i) != '\n') && (*(buff_read + i) != '\0'))
		i++;
	if (*(buff_read + i) == '\n')
	{
		i++;
		*line = ft_substr(buff_read, 0, i);
		new_buff = ft_strdup(buff_read + i);
	}
	else
		*line = ft_strdup(buff_read);
	free(buff_read);
	return (new_buff);
}
