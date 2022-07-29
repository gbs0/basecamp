/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:12:23 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/01 14:51:49 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_size(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	size;
	int				i;
	char			*str;

	nb = (unsigned int)n;
	size = ft_get_size(nb);
	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		size = ft_get_size(nb) + 1;
	}
	i = size - 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (n < 0)
		str[0] = '-';
	str[size] = '\0';
	while (nb >= 10)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = (nb % 10) + '0';
	return (str);
}
