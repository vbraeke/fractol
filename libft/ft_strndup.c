/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 18:52:56 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/05 16:35:34 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab || !s)
		return (NULL);
	while (i < n)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
