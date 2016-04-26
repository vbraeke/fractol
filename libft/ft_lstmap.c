/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 16:56:57 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/05 16:48:11 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*item;
	t_list	*frai;

	if (!lst || !f)
		return (NULL);
	frai = f(lst);
	item = frai;
	lst = lst->next;
	while (lst)
	{
		item->next = f(lst);
		item = item->next;
		lst = lst->next;
	}
	return (frai);
}
