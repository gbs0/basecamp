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

	factor = 1;
	if (nb > 0)
	{
		while ((factor * factor) <= nb)
		{
			if ((factor * factor) == nb)
				return (factor);
			else if (factor >= 46341)
				return (0);
			factor++;
		}
	}
	return (0);
}
