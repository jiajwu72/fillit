/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:03:24 by jwu               #+#    #+#             */
/*   Updated: 2017/11/28 11:42:42 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetri
{
	t_point				points[4];
	struct s_tetri		*next;
	int					ind;
}				t_tetri;

typedef struct	s_map
{
	char		**map;
	int			max;
}				t_map;

/*
 ** READ
*/
char			*read_file(char *nom);
t_tetri			*fichier_to_tetri(char *nom);
t_tetri			*create_tetri(char *s);

/*
 ** CHECK
*/
t_tetri			*better_coord(t_tetri *tetri);
t_tetri			*checkfillit(char *s);
t_tetri			*check_tetri(t_tetri *s);

/*
 ** RESOLVE
*/
int				resolve(t_tetri *tetri);
int				freemap(t_map **map);
t_map			*create_map(t_tetri *tetri, int plus);
t_map			*del_tetri(t_map *map, t_tetri *tetri, int x, int y);
t_map			*write_tetri(t_map *map, t_tetri *tetri, int x, int y);

/*
 ** PRINT
*/
void			print_map(t_map *map);
void			print_tetri(t_tetri *tetri);

#endif
