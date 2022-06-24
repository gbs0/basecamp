/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:59:46 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/24 13:41:21 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*offset(char *buffer)
{
	size_t	i;
	size_t	shift;
	char	*new_buffer;

	i = -1;
	shift = 0;
	if (!buffer)
		return (NULL);
	if (!*buffer)
	{
		free(buffer);
		buffer = NULL;
		return (buffer);
	}
	while (buffer[shift] && buffer[shift] != '\n')
		shift++;
	new_buffer = malloc(ft_strlen(buffer) + 1);
	if (!new_buffer)
		return (NULL);
	while (buffer[shift])
		new_buffer[++i] = buffer[++shift];
	new_buffer[++i] = '\0';
	free(buffer);
	buffer = NULL;
	return (new_buffer);
}

char	*get_breakline(char *buffer)
{
	size_t	i;
	size_t	offset;
	char	*line;

	i = 0;
	offset = 0;
	if (!buffer)
		return (NULL);
	if (!*buffer)
		return (NULL);
	while (buffer[offset] && buffer[offset] != '\n')
		offset++;
	line = malloc((offset + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= offset)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*buffer_handler(char *buffer, int fd)
{
	char	*temp;
	char	*switch_buf;
	int		ref_bytes;

	ref_bytes = 1;
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && ref_bytes != 0)
	{
		ref_bytes = read(fd, temp, BUFFER_SIZE);
		if (ref_bytes < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[ref_bytes] = '\0';
		switch_buf = ft_buffer_join(buffer, temp);
		free(buffer);
		buffer = switch_buf;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD_SIZE];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD_SIZE)
		return (NULL);
	buffer[fd] = buffer_handler(buffer[fd], fd);
	line = get_breakline(buffer[fd]);
	buffer[fd] = offset(buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (buffer[fd]);
	}
	return (line);
}
