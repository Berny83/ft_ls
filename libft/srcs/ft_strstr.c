/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:44:52 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/21 18:55:49 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (haystack[i + j] == needle[i] && needle[i] != '\0')
				i++;
			if (needle[i] == '\0')
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (0);
}
