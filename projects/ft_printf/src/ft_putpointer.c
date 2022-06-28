/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:27:46 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/28 14:46:52 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

static int	count_hexadecimal(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*hexadecimal_to_str(unsigned long n, char *base)
{
	int		size;
	char	*hexadecimal;

	size = count_hexadecimal(n);
	hexadecimal = (char *)malloc(sizeof(char) * (size + 1));
	if (!hexadecimal)
		return (NULL);
	hexadecimal[size] = '\0';
	while (size > 0)
	{
		hexadecimal[size - 1] = base[n % 16];
		n /= 16;
		size--;
	}
	return (hexadecimal);
}

int	put_pointer(void *nbr, char *base)
{
	int				len;
	char			*str;
	unsigned long	n;

	n = (unsigned long)nbr;
	str = hexadecimal_to_str(n, base);
	len = ft_putstr(str);
	free(str);
	return (len);
}
