/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:38:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/06 15:36:08 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

bool		ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *current)
{
	t_data	tmp;
	int		tmp_total;
	char	*tmp_name;
	char	*tmp_path;

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

void		sorting(bool (*ft_sort)(t_argvs *), t_argvs *curr)
{
	t_argvs	*current;
	t_argvs	*head;
	int		sorted;

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

static void	fl_swap(t_argvs *new, t_argvs *tmp)
{
	t_argvs	*t;
	t_data	td;
	int		total;
	char	*name;
	char	*path;

	td = tmp->info;
	total = tmp->total;
	name = tmp->name;
	path = tmp->path;
	t = tmp->next;
	tmp->info = new->info;
	tmp->total = new->total;
	tmp->name = new->name;
	tmp->path = new->path;
	tmp->next = new->next;
	new->info = td;
	new->total = total;
	new->name = name;
	new->path = path;
	new->next = t;
}

t_argvs		*tmp_reverse(t_argvs *tmp, t_argvs *new, t_argvs *hd, t_argvs *lst)
{
	while (tmp)
	{
		new = tmp;
		if (tmp->prev && tmp->prev->prev)
			new->next = tmp->prev;
		else if (tmp->prev)
			new->next = lst;
		else
		{
			hd = tmp;
			new->next = NULL;
		}
		tmp = tmp->prev;
	}
	new = hd;
	return (new);
}

t_argvs		*reverse_time(t_argvs *curr)
{
	t_argvs	*head;
	t_argvs	*tmp;
	t_argvs	*last;
	t_argvs	*new;

	head = curr->next;
	tmp = curr;
	last = NULL;
	new = NULL;
	while (head)
	{
		head->prev = tmp;
		tmp = head;
		last = head;
		head = head->next;
	}
	new = tmp_reverse(tmp, new, head, last);
	(last) ? fl_swap(new, last) : 0;
	return (curr);
}
