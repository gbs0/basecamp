/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:51:35 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/08 16:59:58 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_numbers(void) {
    // int number;
	// int limit;
	int digit;

	digit = 99;
	// limit = 99;
    // number = 0;
	
    // while (number <= limit) {
    //     write(1, &number, 1);
    //     number += 1;
    // }

	while (digit >= 0)
	{
		write(1, &digit, 1);
		digit--;
	}
	
}

int main(void) {
	ft_print_numbers();
}