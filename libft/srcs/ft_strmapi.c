/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:15:03 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 13:14:21 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;
	int		len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		map = (char *)malloc(sizeof(char) * len + 1);
		if (!map)
			return (NULL);
		while (s[i] != '\0')
		{
			map[i] = f(i, s[i]);
			i++;
		}
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
