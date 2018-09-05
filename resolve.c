/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:15:34 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/25 11:47:49 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		check_place(t_tetri *tetri, t_map map, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (tetri->points[i].y + y >= map.max)
			return (-2);
		if (tetri->points[i].x + x >= map.max)
			return (-1);
		if (map.map[tetri->points[i].y + y][tetri->points[i].x + x] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int		ntm_norme(int place, int *x, int *y)
{
	if (place == 0)
		(*x)++;
	else if (place == -1)
	{
		(*y)++;
		*x = 0;
	}
	else if (place == -2)
		return (0);
	return (1);
}

static int		backtrack(t_map *map, t_tetri *tetri, int x, int y)
{
	int		place;

	place = 0;
	if (!tetri)
		return (1);
	while (place != 1)
	{
		place = check_place(tetri, *map, x, y);
		if (ntm_norme(place, &x, &y) == 0)
			return (0);
		else if (place == 1)
		{
			map = write_tetri(map, tetri, x, y);
			if (backtrack(map, tetri->next, 0, 0) == 0)
			{
				place = 0;
				map = del_tetri(map, tetri, x, y);
				x++;
			}
		}
	}
	return (1);
}

int				resolve(t_tetri *tetri)
{
	t_map	*map;
	int		big;

	map = create_map(tetri, 0);
	if (!map)
		return (0);
	tetri = better_coord(tetri);
	big = 0;
	while (backtrack(map, tetri, 0, 0) == 0)
	{
		freemap(&map);
		big++;
		map = create_map(tetri, big);
	}
	print_map(map);
	return (1);
}
