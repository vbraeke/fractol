/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:29:50 by vbraeke           #+#    #+#             */
/*   Updated: 2015/12/21 14:48:43 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s2[i])
		return ((char *)s1);
	while (s1[i] && n > 0)
	{
		while (s1[i + j] == s2[j] && n > 0)
		{
			if (!s2[j + 1])
				return ((char *)&s1[i]);
			n--;
			j++;
		}
		i++;
		n--;
	}
	return (NULL);
}
