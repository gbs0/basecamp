/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:15:39 by gschiavo          #+#    #+#             */
/*   Updated: 2022/04/18 08:01:39 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// ------------------------- TEST -------------------------
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// char	*ft_strcpy(char *dest, char *src);
// void ft_strcpy_test(char *ft_res, char *str_res)
// {
// 	if (ft_res != str_res)
// 		printf("> KO, expected: %s, got: %s\n", ft_res, str_res);
// 	else
// 		printf("> OK, result: %s, expected: %s\n", ft_res, str_res);
// }
// int	main(void)
// {
// 	char *src;
// 	char *dest;
// 	char *result;
// 	char *expected;
// 	src = calloc(11, sizeof(char));
// 	src = "0123456789";
// 	dest = calloc(11, sizeof(char));
// 	result = ft_strcpy(dest, src);
// 	expected = strcpy(dest, src);
// 	ft_strcpy_test(result, expected);
//     return (0);
// }