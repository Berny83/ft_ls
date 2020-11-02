/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:21:02 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 16:24:55 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			nbr_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) \
	|| (c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int		nbr;
	int		sign;

	if (!str || (base < 2 || base > 16))
		return (0);
	nbr = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		(*str == '-') ? sign = -1 : 0;
		str++;
	}
	while (*str && nbr_base(*str, base))
	{
		if (*str >= 'A' && *str <= 'F')
			nbr = (nbr * base) + (*str - 'A' + 10);
		else if (*str >= 'a' && *str <= 'f')
			nbr = (nbr * base) + (*str - 'a' + 10);
		else
			nbr = (nbr * base) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
