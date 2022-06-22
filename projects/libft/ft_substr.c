/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:03:00 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/14 10:24:19 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		i = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		i = 1;
	if (i > len)
		i = len + 1;
	dest = (char *)malloc(sizeof(char) * i);
	if (!dest)
		return (NULL);
	if (i - 1 == 0)
		dest[0] = '\0';
	else
		ft_strlcpy(dest, &s[start], i);
	return (dest);
}
