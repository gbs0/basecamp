/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:10:25 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/02 18:23:48 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s2;
	size_t	len_s1;
	char	*str;
	int		i;

	len_s2 = ft_strlen(s2);
	len_s1 = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!s1 || !s2 || !str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + len_s1] = s2[i];
		i++;
	}
	str[i + len_s1] = '\0';
	return (str);
}
