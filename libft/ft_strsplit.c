/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:13:43 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:36 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int		words;

	words = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			words++;
		else if (*str && *str == c)
			str++;
		while (*str && *str != c)
			str++;
	}
	return (words);
}

static int	ntm_norme(char const *s, size_t i, char c, size_t *size)
{
	while (s[i] && s[i] != c)
	{
		i++;
		(*size)++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;
	size_t	size;

	i = 0;
	j = 0;
	if (s &&
	(tab = (char **)ft_memalloc(sizeof(char *) * (count_words(s, c) + 1))))
	{
		while (s[i] && count_words(s, c) >= 1)
		{
			size = 0;
			while (s[i] && s[i] == c)
				i++;
			i = ntm_norme(s, i, c, &size);
			if (!(tab[j] = ft_strsub(s, i - size, size)))
				return (0);
			j++;
		}
		tab[count_words(s, c)] = 0;
		return (tab);
	}
	return (0);
}
