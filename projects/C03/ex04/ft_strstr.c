/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:47:36 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/18 10:57:43 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		pos;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			pos = 1;
			while (to_find[pos] != '\0' && str[i + pos] == to_find[pos])
			{
				pos++;
				if (to_find[pos] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}	
	return (0);
}
