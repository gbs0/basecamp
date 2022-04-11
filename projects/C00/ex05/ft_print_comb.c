/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbs0 <gbs0@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:11:58 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/11 17:47:32 by gbs0             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	unidade;
	int	dezena;
	int	centena;

	unidade = '0' - 1;
	while (++unidade <= '9')
	{
		dezena = '0' - 1;
		while (++dezena <= '9')
		{
			centena = '0' - 1;
			while (++centena <= '9')
			{
				if (dezena > unidade && dezena < centena)
				{
					write (1, &unidade, 1);
					write (1, &dezena, 1);
					write (1, &centena, 1);
					if (unidade != '7')
						write (1, ", ", 2);
				}
			}
		}
	}
}
