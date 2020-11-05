/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:38:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/05 19:25:23 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool				ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *current)
{
	t_data			tmp;
	int				tmp_total;
	char			*tmp_name;
	char			*tmp_path;

	if (ft_sort(current))
	{
		tmp_total = current->total;
		tmp_path = current->path;
		tmp_name = current->name;
		tmp = current->info;
		current->total = current->next->total;
		current->path = current->next->path;
		current->name = current->next->name;
		current->info = current->next->info;
		current->next->total = tmp_total;
		current->next->path = tmp_path;
		current->next->name = tmp_name;
		current->next->info = tmp;
		return (true);
	}
	return (false);
}

void				sorting(bool (*ft_sort)(t_argvs *), t_argvs *curr)
{
	t_argvs			*current;
	t_argvs			*head;
	int				sorted;

	current = curr;
	head = current;
	while (true)
	{
		sorted = 1;
		while (current && current->next)
		{
			if (ft_swap(ft_sort, current))
				sorted = 0;
			current = current->next;
		}
		current = head;
		if (sorted)
		{
			if (ft_sort == check_time_r)
				reverse_time(current);
			return ;
		}
	}
}

t_argvs				*reverse_time(t_argvs *curr)
{
	t_argvs			*head;
	t_argvs			*tmp;
	t_argvs			*last;
	t_argvs			*new;

	head = curr->next;
	tmp = curr;
	new = NULL;
	while (head)
	{
		head->prev = tmp;
		tmp = head;
		new = head;
		head = head->next;
	}
	while (tmp)
	{
		last = tmp;
		last->next = tmp->prev;
		tmp = tmp->prev;
	}
	return (curr);
}
