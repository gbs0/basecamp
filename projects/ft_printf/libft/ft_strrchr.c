/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:15:55 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/14 10:12:44 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str_end;

	str_end = s;
	while (*str_end)
		str_end++;
	while (str_end != s)
	{
		if (*str_end == (char)c)
			return ((char *)str_end);
		else
			str_end--;
	}
	if (*str_end == (char)c)
		return ((char *)str_end);
	else
		return (NULL);
}
