/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbs0 <gbs0@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:52:30 by gbs0              #+#    #+#             */
/*   Updated: 2022/04/15 09:10:19 by gbs0             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	counter;
	int	index;

	counter = 0;
	index = 0;
	while (dest[counter] != '\0')
	{
		counter++;
	}
	while (src[index] != '\0')
	{
		dest[counter] = src[index];
		index++;
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}
