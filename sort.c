/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/29 22:38:56 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void				ft_sorting(bool (*ft_sort)(t_argvs *), t_argvs *cur_struct)
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
}
