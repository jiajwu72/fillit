/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:00:34 by jwu               #+#    #+#             */
/*   Updated: 2017/11/24 00:16:58 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			point_equal(t_point p1, t_point p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return (1);
	return (0);
}

static t_point		*pointcpy(t_point point)
{
	t_point	*new;

	if (!(new = (t_point*)malloc(sizeof(t_point))))
		return (0);
	new->x = point.x;
	new->y = point.y;
	return (new);
}

static int			get_connect(t_point point, t_point *tmp)
{
	int		connect;

	connect = 0;
	tmp->x++;
	connect += point_equal(point, *tmp);
	tmp->x--;
	tmp->y++;
	connect += point_equal(point, *tmp);
	tmp->x--;
	tmp->y--;
	connect += point_equal(point, *tmp);
	tmp->x++;
	tmp->y--;
	connect += point_equal(point, *tmp);
	tmp->y++;
	return (connect);
}

static int			check_connect(t_point point[4])
{
	t_point	*tmp;
	int		i;
	int		connect;
	int		j;

	connect = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		if (!(tmp = pointcpy(point[i])))
			return (0);
		while (j < 4)
		{
			connect += get_connect(point[j], tmp);
			j++;
		}
		free(tmp);
		i++;
	}
	if (connect >= 6)
		return (1);
	return (0);
}

t_tetri				*check_tetri(t_tetri *tetri)
{
	t_tetri *init;
	int		count;

	count = 0;
	init = tetri;
	if (tetri == NULL)
		return (NULL);
	while (tetri)
	{
		if (check_connect(tetri->points) == 0)
			return (NULL);
		tetri = tetri->next;
	}
	return (init);
}
