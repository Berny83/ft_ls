/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:52:10 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/18 18:31:47 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*res;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	while (s[start] && ft_whitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (s[end] && ft_whitespace(s[end]))
		end--;
	if (end < 0)
		return (ft_memalloc(1));
	if (!(res = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start <= end)
	{
		res[i++] = s[start];
		start++;
	}
	res[i] = '\0';
	return (res);
}
