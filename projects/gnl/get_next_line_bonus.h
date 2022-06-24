/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:19:49 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/24 16:32:48 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# define MAX_FD_SIZE 1024

char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_alloc(size_t mem, size_t size);
char	*ft_buffer_join(char *s1, char *s2);
#endif