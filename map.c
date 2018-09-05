/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:22:17 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/25 12:33:25 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		sqrt(int nb)
{
	int		i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

t_map			*create_map(t_tetri *tetri, int plus)
{
	int		nb_tetri;
	t_map	*map;
	int		i;

	if (!tetri)
		return (0);
	nb_tetri = 4;
	while (tetri->next)
	{
		nb_tetri += 4;
		tetri = tetri->next;
	}
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->max = sqrt(nb_tetri) + plus;
	if (!(map->map = (char **)ft_memalloc(sizeof(char *) * map->max)))
		return (0);
	i = 0;
	while (i < map->max)
	{
		if (!(map->map[i] = (char *)ft_memalloc(sizeof(char) * map->max)))
			return (0);
		i++;
	}
	return (map);
}

int				freemap(t_map **map)
{
	int		i;

	i = 0;
	while (i < map[0]->max)
	{
		free(map[0]->map[i]);
		i++;
	}
	free(map[0]->map);
	free(*map);
	*map = 0;
	return (0);
}

void			print_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->max)
	{
		x = 0;
		while (x < map->max)
		{
			if (map->map[y][x] == 0)
				ft_putchar('.');
			else
				ft_putchar(map->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
