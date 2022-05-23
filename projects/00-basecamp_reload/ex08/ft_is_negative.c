/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:51:55 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/23 13:37:57 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar("N");
	}
	else if (n == NULL)
	{
		ft_putchar("P");
	}
	else
	{
		ft_putchar("P");
	}
}
