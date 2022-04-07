/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:03:18 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/07 14:23:40 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void)
{
    char word;

    word = 'a';
    while (word <= 'z')
    {
        write(1, &word, 1);
        word++;
    }
}

