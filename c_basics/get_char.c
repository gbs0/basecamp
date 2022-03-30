/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:55:17 by gschiavo          #+#    #+#             */
/*   Updated: 2022/03/30 16:02:29 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple C Program to show how to use getchar()
#include <stdio.h>

int main() {
    printf("Hello, what is your name?\n");
    char userName = getchar();
    
    printf("Hello %c, nice to meet you!\n", userName);
    putchar(userName);
    return 0;
}