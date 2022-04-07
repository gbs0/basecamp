/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:51:35 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/07 19:51:38 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_numbers(void); {
    int number;

    number = 0;
    while (number <= 99) {
        write(1, &number, 1);
        number++;
    }
}