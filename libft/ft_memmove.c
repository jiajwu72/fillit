/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:44 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:59 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src >= dst)
		ft_memcpy(dst, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			*((unsigned char *)dst + n) = *((unsigned char *)src + n);
		}
	}
	return (dst);
}
