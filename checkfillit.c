/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:02:03 by jwu               #+#    #+#             */
/*   Updated: 2017/11/25 11:55:54 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	checkcara(char *s)
{
	while (*s)
	{
		if (!(*s == '#' || *s == '.' || *s == '\n'))
			return (0);
		s++;
	}
	return (1);
}

static int	check_new_line(char *s)
{
	int		stock;
	int		i;
	int		count;

	i = 0;
	stock = 0;
	count = 0;
	if (s[i] == '\n' || s[ft_strlen(s) - 1] != '\n'
		|| s[ft_strlen(s) - 2] == '\n')
		return (0);
	while (s[i++])
	{
		if (s[i] == '\n')
		{
			stock++;
			if (stock > 4 || (stock == 4 &&
					(s[i + 1] != '\n' && s[i + 1] != '\0')))
				return (0);
			else if (stock == 4 && s[i + 1] == '\n')
				stock = -1;
		}
	}
	return (1);
}

static int	checklen(char *s)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != '\n')
			count++;
		else
		{
			if (s[i - 1] != '\n')
			{
				if (count != 4)
					return (0);
				if (s[i + 1] != '\0')
					count = 0;
			}
		}
	}
	return (count == 4 ? 1 : 0);
}

t_tetri		*checkfillit(char *s)
{
	t_tetri	*t;

	if (check_new_line(s) == 0 || checklen(s) == 0 || checkcara(s) == 0)
		return (NULL);
	t = create_tetri(s);
	t = check_tetri(t);
	return (t);
}
