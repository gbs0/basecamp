/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:11:58 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/11 17:12:58 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_dozens(void)
{
    char i;
    char j;

    i = '0';
    j = '0';
    
}
void ft_print_comb(void) 
{
    char string[3];

    string[0] = '0';
    string[1] = '1';
    string[2] = '2';
    
        while (string[2] <= '9')
        {
            ft_putchar(string[0]);
            ft_putchar(string[1]);
            ft_putchar(string[2]);
            if (string[0] != '7' || string[1] != '8' || string[2] != '9') {
                ft_putchar(',');
                ft_putchar(' ');
            }
            string[2]++; 
        }
        
        while(string[1] <= '9')
        {
            ft_putchar(string[0]);
            ft_putchar(string[1]);
            ft_putchar(string[2]);
            if (string[0] != '7' || string[1] != '8' || string[2] != '9') {
                ft_putchar(',');
                ft_putchar(' ');
            }
            string[1]++;
        }
        
    
}

// int main(void) {
//     // ft_print_comb();
//     ft_print_dozens();
//     return (0);
// }