/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fichier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:57:35 by jwu               #+#    #+#             */
/*   Updated: 2017/11/25 11:49:36 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *nom)
{
	int		fd;
	char	buf[10000 + 1];
	int		ret;
	char	*s;

	fd = open(nom, O_RDONLY);
	ret = read(fd, buf, 10000);
	buf[ret] = '\0';
	s = buf;
	close(fd);
	return (s);
}
