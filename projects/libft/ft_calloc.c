/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:10:24 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/14 10:02:34 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	malloc_size;

	malloc_size = count * size;
	if (count != 0 && malloc_size / count != size)
		return (NULL);
	pointer = (void *)malloc(malloc_size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, malloc_size);
	return (pointer);
}
