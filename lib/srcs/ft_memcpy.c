/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:23:09 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/21 16:02:39 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dst2;
	char			*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (0 < n)
	{
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (dst);
}
