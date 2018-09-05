/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:38:33 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 19:44:25 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(unsigned int unb, int nb, int base)
{
	int				size;

	if (nb < 0 && base == 10)
		size = 2;
	else
		size = 1;
	while (unb >= (unsigned int)base)
	{
		size++;
		unb /= base;
	}
	return (size);
}

static unsigned int	get_unb(int value)
{
	unsigned int	unb;

	unb = 0;
	if (value < 0)
		unb -= value;
	else
		unb += value;
	return (unb);
}

static char			get_char(char *tab, unsigned int unb, int base)
{
	return (tab[(unb % base)]);
}

char				*ft_itoa_base(int value, int base)
{
	int				size;
	char			*str;
	int				i;
	unsigned int	unb;

	if (base < 2 || base > 16)
		return (0);
	unb = get_unb(value);
	size = get_size(unb, value, base);
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	i = 0;
	if (value < 0 && base == 10)
	{
		str[0] = '-';
		i = 1;
	}
	while (size - 1 >= i)
	{
		str[size - 1] = get_char("0123456789ABCDEF", unb, base);
		unb /= base;
		size--;
	}
	return (str);
}
