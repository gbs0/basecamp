/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:19:08 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/27 15:19:41 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef unsigned char	t_uchar;
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/*
** ==== memory management ====
*/

/*
** ==== display ====
*/
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);

/*
** ==== string manipulation ====
*/

#endif