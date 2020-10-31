/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:33:42 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 13:16:31 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;
	unsigned int	slen;

	i = 0;
	if (s)
	{
		slen = ft_strlen(s);
		if (start > slen)
			return (NULL);
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (s[start] != '\0' && i < len)
		{
			res[i] = s[start];
			start++;
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
