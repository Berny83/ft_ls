/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:16:58 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/28 19:07:54 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_maxmin(unsigned long long int nbr, long long int num)
{
	if (nbr > 9223372036854775807 && num == 1)
		return (-1);
	if (nbr > 9223372036854775807 && num == -1)
		return (0);
	return (nbr * num);
}

int					ft_atoi(const char *str)
{
	int				i;
	long long int	nbr;
	long long int	num;

	nbr = 0;
	num = 1;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			num = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	return (ft_maxmin(nbr, num));
}
