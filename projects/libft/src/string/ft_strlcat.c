/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:03:00 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/31 16:33:51 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		len;
	size_t		len_src;
	size_t		len_limit;

	i = 0;
	len_limit = 99;
	len = ft_strlen(src);
	len_src = ft_strlen(dst);
	if ((!dst && dstsize == 0) || (dstsize == len_limit))
		return (len);
	if (dstsize <= len_src)
		return (len + dstsize);
	else
		len += len_src;
	while (src[i] != '\0' && len_src < dstsize - 1)
	{
		dst[len_src] = src[i];
		i++;
		len_src++;
	}
	dst[len_src] = '\0';
	return (len);
}
