/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:33:48 by jwu               #+#    #+#             */
/*   Updated: 2017/11/28 11:41:47 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char		*s;
	t_tetri		*tetri;

	if (ac == 2)
	{
		s = read_file(av[1]);
		tetri = checkfillit(s);
		if (!tetri || !resolve(tetri))
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
