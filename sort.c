/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/24 15:21:28 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


bool			check_alpha(t_argvs *current)
{
	if (ft_strcmp(current->name, current->next->name) > 0)
		return(true);
	return (false);	
}

bool			check_alpha_r(t_argvs *current)
{
	if (ft_strcmp(current->name, current->next->name) < 0)
		return(true);
	return (false);	
}

bool			check_time(t_argvs *current)
{
	if ((current->info.ltime_mod - current->next->info.ltime_mod) < 0)
		return(true);
	return (false);
}

bool			check_time_r(t_argvs *current)
{
	if ((current->info.ltime_mod - current->next->info.ltime_mod) > 0)
		return(true);
	return (false);	
}

bool			ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *current)
{
	t_data			tmp;
	int				tmp_total;
	char			*tmp_name;
	char			*tmp_path;
	unsigned char	tmp_ex;

	// printf("test3\n");
	if (ft_sort(current))
	{
		// printf("test4\n");
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
	// printf("test5\n");
	return (false);
}

void			ft_sorting(bool (*ft_sort)(t_argvs *), t_argvs *cur_struct)
{
	t_argvs			*current;
	t_argvs			*head;
	int				all_sorted;

	current = cur_struct;
	head = current;
	while (true)
	{
		current = head;
		all_sorted = 1;
		while (current && current->next)
		{
			if (ft_swap(ft_sort, current))
				all_sorted = 0;
			// printf("sort_alpha = %s\n", current->name);
			// printf("all_sorted = %i\n", all_sorted);
			current = current->next;
		}
		if (all_sorted)
			return ;
	}
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
	ft_sorting(doll->ft_sort, doll->info_av);
	// printf("all_sorted = %p\n", doll->ft_sort);
}
