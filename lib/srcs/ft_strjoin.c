/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:28:52 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 13:29:15 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!res)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			res[i++] = s2[j];
			j++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
