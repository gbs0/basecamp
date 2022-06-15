/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:36:15 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/14 15:35:10 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *last;

    last = *alst;
    new->next = NULL;
    if(!*alst)
        *alst = new;
    else
    {
        while(last->next)
            last = last->next;
        last->next = new;
    }
}
