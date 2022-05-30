/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:19:08 by gschiavo          #+#    #+#             */
/*   Updated: 2022/05/30 11:47:23 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** ==== BONUS Part ====
*/
// typedef unsigned char	t_uchar;
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

/*
** ==== memory management ====
*/
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);

/*
** ==== checker ====
*/
int				ft_isalpha(int c);
int				ft_isascii(int c);
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
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *s1);
#endif