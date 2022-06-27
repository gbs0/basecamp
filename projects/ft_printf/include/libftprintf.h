/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:08:39 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/27 11:50:44 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putstr(char *str);
int		putnbr_unsigned(unsigned int nbr);
int		put_pointer(void *nbr, char *base);
int		put_hex(unsigned int nbr, char *base);
int		ft_printf(const char	*format, ...);
#endif