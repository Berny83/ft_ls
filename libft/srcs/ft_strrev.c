/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:34:54 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 16:58:00 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	if (str)
	{
		len = ft_strlen(str) - 1;
		if (!(new = (char *)malloc(sizeof(char) * len + 2)))
			return (NULL);
		while (len >= 0)
		{
			new[i] = str[len];
			i++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
