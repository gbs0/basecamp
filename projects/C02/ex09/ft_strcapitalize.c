/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbs0 <gbs0@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:45:27 by gbs0              #+#    #+#             */
/*   Updated: 2022/04/13 16:38:34 by gbs0             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strcapitalize(char *str)
{
    int i;
    
    i = 0;
    if (str[i + 1] + 1 >= 'a' && str[i + 1] + 1 <= 'z') // Capitalize first letter of sequence
        str[i + 1] -= 32;
    
    while (str[i])
    {
        if (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z') ||
            (str[i - 1] >= 'a' && str[i - 1] <= 'z') ||
            (str[i - 1] >= '0' && str[i - 1] <= '9')))
        {
            	if (str[i] >= 'a' && str[i] <= 'z')
				    str[i] = str[i] - 32;
		}
		else
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
        }
                
        // if (str[i] - 1 == ' ' || str[i] - 1 == '\t' || str[i] - 1 == '\n' || str[i] - 1 == '+' || str[i] - 1 == '-')
        // {
        //     if (str[i] >= 'a' && str[i] <= 'z')
        //         str[i] -= 32;
        //     else
        //         str[i] += 32;
            
        //     i++;
        // }
        
        
     
        i++;
    }

    return (str);
}
