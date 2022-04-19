/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:53:27 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/19 09:41:44 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *string)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (string[i] == '\t' || string[i] == '\f'
		|| string[i] == '\v' || string[i] == '\n'
		|| string[i] == '\r' || string[i] == ' ' )
		i++;
	sign = 1;
	while (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	return (result * sign);
}
