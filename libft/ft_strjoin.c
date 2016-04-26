/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:45:49 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/07 16:28:58 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (s1 && s2)
	{
		fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (fresh)
		{
			ft_strcpy(fresh, (char *)s1);
			ft_strcat(fresh, s2);
			return (fresh);
		}
	}
	return (NULL);
}
