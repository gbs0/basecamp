/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschiavo <gschiavo@42student.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:18:35 by gschiavo          #+#    #+#             */
/*   Updated: 2022/06/08 10:21:40 by gschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			nb++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static size_t	ft_get_len_word(const char *s, int index, char c)
{
	size_t	len_word;

	len_word = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		len_word++;
		index++;
	}
	return (len_word);
}

static char	**free_tab(char **tab, int j)
{
	while (j-- >= 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			result[j] = ft_substr(s, i, ft_get_len_word(s, i, c));
			if (!result[j])
				return (free_tab(result, j));
			j++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	result[j] = 0;
	return (result);
}
