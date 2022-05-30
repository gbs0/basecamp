/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:03:00 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/29 17:06:23 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;
	size_t		len_src;

	i = 0;
	len = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize <= len)
		return (len_src + dstsize);
	while (dst[i] != '\0' && i < dstsize - 1)
		i++;
	while (src[i - len] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i - len];
		i++;
	}
	dst[i] = '\0';
	return (len + len_src);
}
