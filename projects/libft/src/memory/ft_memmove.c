/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:28:54 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/08 14:02:01 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	if (src_c < dst_c)
	{
		while (0 < len)
			dst_c[len - 1] = src_c[len - 1];
			len--;
	}
	else
	{
		while (i < len)
			dst_c[i] = src_c[i];
			i++;
	}
	return (dst);
}
