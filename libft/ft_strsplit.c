/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 16:44:08 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/05 18:59:52 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbwords(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			j++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (j);
}

static char		*add_w(size_t *i, char const *s, char c)
{
	size_t		size;
	size_t		j;
	char		*word;

	size = *i;
	j = 0;
	while (s[size] && s[size] != c)
		size++;
	word = ft_strnew(size - *i);
	if (word)
	{
		while (*i < size)
		{
			word[j] = s[*i];
			j++;
			*i += 1;
		}
		return (word);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		o;
	size_t		*i;
	size_t		j;

	o = 0;
	i = &o;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char **)malloc(sizeof(char *) * (nbwords(s, c) + 1));
	if (tab)
	{
		while (j < nbwords(s, c))
		{
			while (s[*i] == c)
				*i = (*i + 1);
			if (s[*i] != c && s[*i])
				tab[j++] = add_w(i, s, c);
		}
		tab[j] = 0;
		return (tab);
	}
	return (0);
}
