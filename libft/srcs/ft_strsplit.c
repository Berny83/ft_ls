/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:46:35 by aagrivan          #+#    #+#             */
/*   Updated: 2020/05/23 13:51:14 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wd(char const *s, char c)
{
	int		word;

	word = 0;
	if (*s != c && *s)
	{
		s++;
		word++;
	}
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s)
				word++;
		}
		s++;
	}
	return (word);
}

static int	ft_lwd(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		r[2];
	char	**wrd;

	r[0] = 0;
	r[1] = 0;
	if (!s || !(wrd = (char **)malloc(sizeof(char *) * ft_wd(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!(wrd[r[1]] = (char *)malloc(sizeof(char) * ft_lwd(s, c) + 1)))
			return (NULL);
		if (*s != c && *s)
		{
			while (*s && *s != c)
				wrd[r[1]][r[0]++] = (char)*s++;
			wrd[r[1]++][r[0]] = '\0';
			r[0] = 0;
		}
	}
	wrd[r[1]] = NULL;
	return (wrd);
}
