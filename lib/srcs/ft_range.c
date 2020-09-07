/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:43:05 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 18:26:49 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min && max)
	{
		if (min >= max)
			return (NULL);
		if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
			return (NULL);
		while (min < max)
		{
			tab[i] = min;
			i++;
			min++;
		}
		return (tab);
	}
	return (NULL);
}
