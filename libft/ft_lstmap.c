/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:11:15 by sbrucker          #+#    #+#             */
/*   Updated: 2017/11/21 19:14:52 by sbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n_lst;

	if (f)
	{
		if (!lst)
			return (NULL);
		n_lst = ft_lstnew(lst->content, lst->content_size);
		if (n_lst)
			n_lst = f(n_lst);
		if (n_lst && lst->next == NULL)
			n_lst->next = NULL;
		else if (n_lst)
			n_lst->next = ft_lstmap(lst->next, f);
		return (n_lst);
	}
	else
		return (0);
}
