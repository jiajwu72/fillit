/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:06 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:49 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (del && alst && *alst)
	{
		if (alst[0]->next != NULL)
			ft_lstdel(&(alst[0]->next), del);
		ft_lstdelone(alst, del);
	}
}
