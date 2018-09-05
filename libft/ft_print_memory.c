/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:52 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:02 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hexa(unsigned char *tab, size_t size, char *base)
{
	size_t	i;

	i = 0;
	while (i < 16 && i < size)
	{
		ft_putchar(base[tab[i] / 16]);
		ft_putchar(base[tab[i] % 16]);
		if (i % 2 == 1 && size != i)
			ft_putchar(' ');
		i++;
	}
}

static void	print_char(unsigned char *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (size < 16 && i < (16 - size) * 2 + ((16 - size) / 2) + (size % 2))
	{
		ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < 16 && i < size)
	{
		if (tab[i] > 31 && tab[i] < 127)
			ft_putchar(tab[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void		ft_print_memory(void const *tab, size_t size)
{
	if (tab && size)
	{
		while (size > 0)
		{
			print_hexa((unsigned char *)tab, size, "0123456789ABCDEF");
			ft_putchar(' ');
			print_char((unsigned char *)tab, size);
			if (size > 16)
			{
				size -= 16;
				tab += 16;
			}
			else
				size = 0;
			ft_putchar('\n');
		}
	}
}
