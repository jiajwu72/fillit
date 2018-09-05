/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:13:36 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:34 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!needle[0])
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (i < len && haystack[i] == needle[i] && haystack[i] && needle[i])
		{
			i++;
		}
		if (!needle[i])
			return ((char*)(haystack));
		haystack++;
		len--;
	}
	return (0);
}
