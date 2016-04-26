/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:35:40 by vbraeke           #+#    #+#             */
/*   Updated: 2015/12/03 16:50:16 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (dest[j] && j < n)
		j++;
	i = 0;
	while ((src[i]) && ((j + i + 1) < n))
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j != n)
		dest[j + i] = '\0';
	return (j + ft_strlen(src));
}
