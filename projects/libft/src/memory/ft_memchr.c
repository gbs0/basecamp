/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:26:19 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/31 11:12:52 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_c;

	i = 0;
	src_c = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (src_c[i] == (unsigned char)c)
			return ((void *)&src_c[i]);
		i++;
	}
	return (0);
}
