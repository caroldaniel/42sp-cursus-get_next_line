/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:44:55 by cado-car          #+#    #+#             */
/*   Updated: 2021/08/09 20:31:34 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int		read_file(int fd, char *buffer, char **buff_read, ssize_t *buff_len);
char	*get_line(char **buff_read, ssize_t *buff_len, char **line);

char	*get_next_line(int fd)
{
	static char		*buff_read = NULL;
	static ssize_t	buff_len = 0;
	char			*buffer;
	char			*line;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!ft_strchr(buff_read, '\n'))
	{
		n = read_file(fd, buffer, &buff_read, &buff_len);
		if (n < 1)
			return (NULL);
	}
	if (ft_strchr(buff_read, '\n') || (buff_len && !n))
		buff_read = get_line(&buff_read, &buff_len, &line);
	if (!buff_len && !n)
	{
		free(buff_read);
		return (NULL);
	}
	return (line);
}

int	read_file(int fd, char *buffer, char **buff_read, ssize_t *buff_len)
{
	char	*temp;
	ssize_t	n;

	if (!(*buff_read))
	{
		*buff_read = (char *)malloc(1 * sizeof(char));
		if (!(*buff_read))
			return (-1);
		*buff_read = "";
	}
	while (!ft_strchr(*buff_read, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			return (n);
		buffer[n] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, buffer);
		free(temp);
		free(buffer);
		*buff_len += n;
	}
	return (n);
}

char	*get_line(char **buff_read, ssize_t *buff_len, char **line)
{
	ssize_t	i;
	ssize_t	j;
	char	*new_buff;

	i = 0;
	while (*buff_read[i] != '\n' && *buff_read[i] != '\0')
		i++;
	if (*buff_read[i] == '\n')
		i++;
	*line = ft_substr(*buff_read, 0, i);
	new_buff = ft_strdup(*(buff_read + i + 1));
	free(*buff_read);
	*buff_len -= i;
	return (new_buff);
}
