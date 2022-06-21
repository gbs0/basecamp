/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:43:29 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/16 20:45:24 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current_node;

	if (lst && del)
	{
		current_node = *lst;
		next_node = (*lst);
		while (next_node != NULL)
		{
			current_node = next_node;
			next_node = next_node->next;
			(*del)(current_node->content);
			free(current_node);
		}
		*lst = NULL;
	}
}
