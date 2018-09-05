/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:12:50 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:21 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (s1[0] == '\0' && ((str = ft_strnew(1))))
		str[0] = '\0';
	if ((str = ft_strnew(ft_strlen(s1))))
		ft_strcpy(str, s1);
	else
		return (0);
	return (str);
}
