/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_resolve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:43:10 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/23 17:50:34 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*get_good_coord(t_tetri *tetri)
{
	int		small_x;
	int		small_y;
	int		i;

	i = 0;
	small_x = tetri->points[0].x;
	small_y = tetri->points[0].y;
	while (i < 4)
	{
		if (tetri->points[i].x < small_x)
			small_x = tetri->points[i].x;
		if (tetri->points[i].y < small_y)
			small_y = tetri->points[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		tetri->points[i].x -= small_x;
		tetri->points[i].y -= small_y;
		i++;
	}
	return (tetri);
}

t_tetri			*better_coord(t_tetri *tetri)
{
	t_tetri		*head;

	head = tetri;
	while (tetri)
	{
		tetri = get_good_coord(tetri);
		tetri = tetri->next;
	}
	return (head);
}

t_map			*del_tetri(t_map *map, t_tetri *tetri, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map->map[tetri->points[i].y + y][tetri->points[i].x + x] = '\0';
		i++;
	}
	return (map);
}

t_map			*write_tetri(t_map *map, t_tetri *tetri, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		map->map[tetri->points[i].y + y][tetri->points[i].x + x] =
			tetri->ind + 'A';
		i++;
	}
	return (map);
}
