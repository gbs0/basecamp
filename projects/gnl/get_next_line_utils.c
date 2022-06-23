/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:59:50 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/23 20:58:28 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_alloc(size_t mem, size_t size)
{
	char	*buffer;
	size_t	i;
	size_t	mem_size;

	i = 0;
	mem_size = (mem * size) / size;
	if (mem_size != mem)
		return (NULL);
	buffer = malloc(mem * size);
	while (i < mem_size)
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_buffer_join(char *s1, char *s2)
{
	size_t	str_size;
	size_t	i;
	size_t	j;
	char	*dst;

	i = 0;
	j = 0;
	str_size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	dst = ft_alloc(str_size + 1, sizeof(char));
	while (s1 && s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dst[i + j] = s2[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
