/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:36 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:56 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	t1;
	unsigned char	t2;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		t1 = ((unsigned char *)s1)[i];
		t2 = ((unsigned char *)s2)[i];
		if (t1 != t2)
			return (t1 - t2);
		i++;
	}
	return (0);
}
