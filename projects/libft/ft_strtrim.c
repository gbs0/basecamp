/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:38:06 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/08 14:34:41 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	i = 0;
	while (ft_is_set(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (ft_is_set(s1[len - 1], set) == 1)
		len--;
	dest = ft_substr(s1, i, len - i);
	if (!dest)
		return (NULL);
	return (dest);
}
