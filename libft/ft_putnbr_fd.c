/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:12:19 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:08 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_unsigned(unsigned int unb, int fd)
{
	if (unb < 10)
		ft_putchar_fd(unb + '0', fd);
	else
	{
		ft_putnbr_unsigned(unb / 10, fd);
		ft_putchar_fd(unb % 10 + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_unsigned((unsigned int)(0 - n), fd);
	}
	else
		ft_putnbr_unsigned((unsigned int)n, fd);
}
