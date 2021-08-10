/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:44:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/10 09:25:59 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
ssize_t	read_file(int fd, char *buffer, char *buff_read, char **line);
char	*get_line(char *buff_read, char **line);

char	*get_next_line(int fd)
{
	static char		*buff_read = NULL;
	char			*buffer;
	char			*line;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff_read)
		buff_read = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	n = read_file(fd, buffer, buff_read, &line);
	free(buffer);
	if (n < 0 || (n == 0 && !line))
		return (NULL);
	return (line);
}

ssize_t	read_file(int fd, char *buffer, char *buff_read, char **line)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(buff_read, '\n') && n)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff_read);
			return (n);
		}
		buffer[n] = '\0';
		temp = ft_strjoin(buff_read, buffer);
		free(buff_read);
		buff_read = temp;
	}
	buff_read = get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;		
	}
	return (n);
}

char	*get_line(char *buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = NULL;
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
