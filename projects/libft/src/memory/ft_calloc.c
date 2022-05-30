/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:10:24 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/30 11:22:27 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	void	*dest;

	if (count * size == 0)
	{
		size = 1;
		count = 1;
	}
	dest = (void *)malloc(size * count);
	if (!dest)
		return (0);
	ft_memset(dest, '\0', size * count);
	return (dest);
}
