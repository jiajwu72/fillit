/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:21 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:55 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;

	if (size == 0)
		return (0);
	tab = malloc(size);
	if (tab == 0)
		return (0);
	tab = ft_memset(tab, 0, size);
	return ((void*)tab);
}
