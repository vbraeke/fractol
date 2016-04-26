/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:31:19 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/05 16:44:02 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ssrc;
	unsigned char	*ddst;
	unsigned char	x;
	size_t			i;

	ssrc = (unsigned char *)src;
	ddst = (unsigned char *)dst;
	x = (unsigned char)c;
	i = 0;
	while (ssrc[i] != x && i < n)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	if (n == i)
		return (NULL);
	else if (ssrc[i] == x)
	{
		ddst[i] = ssrc[i];
		i++;
	}
	return ((void *)ddst + i);
}
