/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:13:53 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:15:38 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	char	*str;

	begin = 0;
	if (!s)
		return (0);
	end = ft_strlen(s) - 1;
	while (is_space(s[begin]))
		begin++;
	while (begin < end && is_space(s[end]))
		end--;
	if (end - begin > 0)
	{
		if ((str = ft_strnew(end - begin + 1)))
		{
			if (!(str = ft_strncpy(str, s + begin, end - begin + 1)))
				return (0);
			return (str);
		}
	}
	return (0);
}
