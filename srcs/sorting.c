/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 19:19:14 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				check_alpha(t_argvs *current)
{
	if (ft_strcmp(current->name, current->next->name) > 0)
		return (true);
	return (false);
}

bool				check_alpha_r(t_argvs *current)
{
	if (ft_strcmp(current->name, current->next->name) < 0)
		return (true);
	return (false);
}

bool				check_time(t_argvs *current)
{
	if ((current->info.ltime_mod - current->next->info.ltime_mod) < 0)
		return (true);
	return (false);
}

bool				check_time_r(t_argvs *current)
{
	if ((current->info.ltime_mod - current->next->info.ltime_mod) > 0)
		return (true);
	return (false);
}

void				flags_sort(t_ls *doll)
{
	if (doll->optns.t && doll->optns.r)
		doll->ft_sort = check_time_r;
	else if (doll->optns.t)
		doll->ft_sort = check_time;
	else if (doll->optns.r)
		doll->ft_sort = check_alpha_r;
	else
		doll->ft_sort = check_alpha;
	sorting(doll->ft_sort, doll->info_av);
}
