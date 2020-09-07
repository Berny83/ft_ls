/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:04:38 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/17 15:26:16 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	long	len;
	long	j;

	j = (long)n;
	len = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (j /= 10)
		len++;
	if (n < 0)
	{
		len += ++j;
		n = -n;
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		res[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (j)
		res[0] = '-';
	return (res);
}
