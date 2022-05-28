/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:19:08 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/28 19:23:03 by gschiavo         ###   ########.fr       */
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
** ==== checker ====
*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);

/*
** ==== convert ====
*/
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** ==== display ====
*/
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl_fd(char *s, int fd);

/*
** ==== string manipulation ====
*/

#endif