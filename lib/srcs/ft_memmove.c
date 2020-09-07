/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:27:24 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/20 11:41:52 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst2 <= src2)
	{
		while (i < len)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i-- > 0)
			dst2[i] = src2[i];
	}
	return (dst);
}
