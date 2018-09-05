/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:12:37 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:13 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t		i;
	size_t		length;

	if (s)
	{
		length = ft_strlen(s);
		i = 0;
		while (i < length)
		{
			s[i] = '\0';
			i++;
		}
	}
}