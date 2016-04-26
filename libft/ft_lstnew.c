/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 15:33:17 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/06 16:59:40 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*item;

	item = (t_list *)malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	if (content == NULL)
	{
		item->content = NULL;
		item->content_size = 0;
		item->next = NULL;
		return (item);
	}
	else if (item)
	{
		item->content = (void *)malloc(sizeof(char *) * content_size);
		ft_memcpy(item->content, content, content_size);
		item->content_size = content_size;
		item->next = NULL;
		return (item);
	}
	return (NULL);
}
