/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:01 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:47 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(unsigned int unb, int n)
{
	int				size;

	if (n < 0)
		size = 2;
	else
		size = 1;
	while (unb > 9)
	{
		unb /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	unsigned int	unb;
	char			*str;
	size_t			size;

	if (n < 0)
		unb = 0 - n;
	else
		unb = n;
	size = get_size(unb, n);
	if (!(str = ft_strnew(size)))
		return (0);
	if (n < 0)
		*str = '-';
	while ((size > 1 && n < 0) || (size > 0 && n >= 0))
	{
		str[size - 1] = unb % 10 + '0';
		unb /= 10;
		size--;
	}
	return (str);
}
