/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:49 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:01 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_bloc(t_list *lst, unsigned int i)
{
	ft_putnbr(i);
	if (i > 9)
		ft_putstr(" ");
	else
		ft_putstr("  ");
	ft_putstr("-> ");
	if (lst->next == NULL)
		ft_putstr("NULL");
	else
		print_bloc(lst->next, i + 1);
}

void		ft_print_list(t_list *lst)
{
	if (lst)
	{
		ft_putchar(' ');
		print_bloc(lst, 0);
	}
}
