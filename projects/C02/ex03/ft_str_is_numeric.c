/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:21:41 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/13 16:29:06 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
    int		i;

    i = 0;

    if (str[i] == '\0')
	return (1);
    
    while (str[i] != '\0')
    {
	if (str[i] < '0' || str[i] > '9')
	    return (0);
	i++;
    }

    return	(1);
}
