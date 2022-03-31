/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primeNumbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:47:02 by gschiavo          #+#    #+#             */
/*   Updated: 2022/03/31 11:16:12 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple C function to return if number is prime or not.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int is_prime(int number);

int main() {
    // printf("%d is prime? %d\n", 2, is_prime(2));
    // printf("%d is prime? %d\n", 5, is_prime(5));
    // printf("%d is prime? %d\n", 11, is_prime(11));
    printf("%d is prime? %d\n", 11, is_prime(0));  
}

int is_prime(uint32_t number) {
    uint32_t remainder = number % number; 
    if (number == 0) {
        return 0;
    }
    
    else if ( number < 1 ) {
        return 0; 
        
    }
    
    return 1;
}