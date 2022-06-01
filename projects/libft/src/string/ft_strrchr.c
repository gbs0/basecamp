/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:15:55 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/01 15:19:58 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;

	length = ft_strlen(s);
	if (s[length] == c)
		return ((char *)(s + length));
	while (length > 0)
	{
		if (s[length - 1] == c)
			return ((char *)(s + length - 1));
		length--;
	}
	return (0);
}
