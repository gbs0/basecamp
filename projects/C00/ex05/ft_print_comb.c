/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbs0 <gbs0@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:11:58 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/11 15:22:44 by gbs0             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_dozens(char string[3])
{
    ft_putchar(string[0]);
	ft_putchar(string[1]);
	ft_putchar(string[2]);
	if (!(string[0] == '7' && string[1] == '8' && string[2] == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}

}

void ft_print_comb(void) 
{
    char string[3];

    string[0] = '0';
    string[1] = '1';
    string[2] = '2';
    
    while(1)
    {
        while (string[2] <= '9')
        {   
            ft_print_dozens(string);
            string[2]++;
        }
        
        if (string[1] <= '8')
        {
            string[2] = string[1];
            string[1]++;
        }
        else if (string[0] <= '7')
        {
            string[1] = string[0] + 1;
            string[2] = string[1];
        }
        else
            break;
            
    }
        
    
}

int main(void) {
    ft_print_comb();
    // ft_print_dozens();
    return (0);
}