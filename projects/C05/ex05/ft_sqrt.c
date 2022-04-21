/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:27:08 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/21 15:28:07 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		factor;
	int		result;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	factor = 1;
	result = factor;
	if (nb > 0)
	{
		while (result <= nb)
		{
			if (result == nb)
				return (factor);
			else if (result >= 46341)
				return (0);
			factor++;
			result = factor * factor;
		}
	}
	return (0);
}
