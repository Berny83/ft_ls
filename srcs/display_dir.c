/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:32:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/07 13:19:16 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				loop_up_r(t_argvs *head, bool (*ft_sort)(t_argvs *),\
t_flags *fl, int ac)
{
	t_argvs			*tmp;

	tmp = head;
	while (head)
	{
		if (head->info.fruit.idir && ft_strcmp(head->name, ".") && \
		ft_strcmp(head->name, ".."))
			loop(head, ft_sort, fl, ac);
		head = head->next;
	}
}

void				header(t_argvs *curr)
{
	if (curr->info.one && curr->next)
		ft_printf("%s:\n", curr->path + 2);
	else if (curr->info.one && !curr->next && curr->info.not)
		ft_printf("%s:\n", curr->path + 2);
	else if (!curr->info.one)
		ft_printf("\n%s:\n", curr->path + 2);
}

void				loop(t_argvs *curr, bool (*ft_sort)(t_argvs *),\
t_flags *fl, int ac)
{
	t_argvs			*head;
	t_argvs			*tmp;

	if (!(head = ft_get_content_dir(curr, fl)))
		return ;
	ft_ls(head);
	tmp = head;
	if ((ac > 1 && !fl->up_r) || (fl->up_r))
		header(curr);
	sorting(ft_sort, head);
	tmp = head;
	if (!head->info.not_exist)
		ft_print_content_dir(head, fl);
	curr->info.one = false;
	if (fl->up_r)
	{
		head = tmp;
		loop_up_r(head, ft_sort, fl, ac);
		free_list(head);
		return ;
	}
	free_list(head);
}

void				display_dir(t_ls *doll)
{
	t_argvs			*curr;
	bool			first;

	curr = doll->info_av;
	first = false;
	while (curr)
	{
		if (!curr->info.not_exist && curr->info.fruit.idir)
		{
			if (!first)
			{
				curr->info.one = true;
				first = true;
			}
			if (doll->not_dir)
				curr->info.not = 1;
			loop(curr, doll->ft_sort, &doll->optns, doll->ac);
		}
		curr = curr->next;
	}
}
