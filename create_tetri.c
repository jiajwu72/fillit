/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:43:20 by jwu               #+#    #+#             */
/*   Updated: 2017/11/25 12:19:59 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	newpoint(int i)
{
	t_point	p;

	if (i >= 21)
		i = i - (i / 21) * 21;
	p.x = i % 5;
	p.y = i / 5;
	return (p);
}

t_tetri			*init_tetri(void)
{
	t_tetri	*t;

	t = (t_tetri *)malloc(sizeof(t_tetri));
	return (t);
}

int				ntm_norme(char *s, int g, t_tetri *tetri)
{
	int		i;
	int		j;

	while (s[g])
	{
		i = 0;
		j = 0;
		while (i++ < 21 && s[g])
		{
			if (s[g] == '#')
			{
				tetri->points[j++] = newpoint(g);
				if (j > 4)
					return (0);
			}
			g++;
		}
		tetri->ind = s[g] == '\0' ? (g / 21) : (g / 21) - 1;
		if (s[g] != '\0')
		{
			tetri->next = init_tetri();
			tetri = tetri->next;
		}
	}
	return (1);
}

t_tetri			*create_tetri(char *s)
{
	t_tetri	*init;

	if (!(init = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	init->next = NULL;
	if (!ntm_norme(s, 0, init))
		return (0);
	return (init);
}
