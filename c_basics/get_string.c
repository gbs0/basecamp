/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:17:43 by gschiavo          #+#    #+#             */
/*   Updated: 2022/03/31 20:40:44 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple C Program to print a string from user input.
#include <stdio.h>

void printName(char*);

int main(void) {
    char *name[100];
	printf("Enter your name: ");
    fgets(*name, sizeof(*name), stdin);
    printName(*name);
    return (0);
}

void printName(char *word) {
    printf("%c", *word);
    printName(++word);
}