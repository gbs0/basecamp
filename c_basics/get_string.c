/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:17:43 by gschiavo          #+#    #+#             */
/*   Updated: 2022/03/31 14:10:39 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple C Program to print a string from user input.
#include <stdio.h>

void printName(char*);

int main(void) {
    printf("Enter your name: ");
    char name[100];
    gets(name);
    printName(name);
    return (0);
}

void printName(char *word) {
    printf("%c", *word);
    printName(++word);
}