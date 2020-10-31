/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:38:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/31 20:09:21 by aagrivan         ###   ########.fr       */
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

bool				ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *current)
{
	t_data			tmp;
	int				tmp_total;
	char			*tmp_name;
	char			*tmp_path;
	unsigned char	tmp_ex;

	if (ft_sort(current))
	{
		tmp_total = current->total;
		tmp_path = current->path;
		tmp_name = current->name;
		tmp = current->info;
		tmp_ex = current->not_exist;
		current->total = current->next->total;
		current->path = current->next->path;
		current->name = current->next->name;
		current->info = current->next->info;
		current->not_exist = current->next->not_exist;
		current->next->total = tmp_total;
		current->next->path = tmp_path;
		current->next->name = tmp_name;
		current->next->info = tmp;
		current->next->not_exist = tmp_ex;
		return (true);
	}
	return (false);
}
