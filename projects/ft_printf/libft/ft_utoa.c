/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:18:46 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/27 12:21:40 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_len(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	int				i;
	unsigned int	aux;
	char			*ptr;

	i = num_len(n);
	aux = n;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (aux == 0)
		ptr[0] = '0';
	ptr[i--] = '\0';
	while (aux)
	{
		ptr[i--] = (aux % 10) + '0';
		aux /= 10;
	}
	return (ptr);
}

static int	num_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}
