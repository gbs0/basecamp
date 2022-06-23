/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:59:50 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/23 20:46:32 by gschiavo         ###   ########.fr       */
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
