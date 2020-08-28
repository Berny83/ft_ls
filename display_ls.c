/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:16:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/26 21:45:49 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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

bool			ft_swap(t_ls *doll, t_argvs *current)
{
	t_data			tmp;
	int				tmp_total;
	char			*tmp_name;
	char			*tmp_path;

	// printf("test3\n");
	if (doll->ft_sort(current))
	{
		// printf("test4\n");
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
	// printf("test5\n");
	return (false);
}

void			ft_sorting(t_ls *doll, t_argvs *cur_struct)
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
			if (ft_swap(doll, current))
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
	ft_sorting(doll, doll->info_av);
}

static t_argvs			*initiate_argvs(void)
{
	t_argvs		*argvv;

	if (!(argvv = (t_argvs*)malloc(sizeof(t_argvs))))
		return(NULL);
	ft_memset(argvv, 0, sizeof(argvv));
	argvv->next = NULL;
	// printf("test_entry2\n");
	return(argvv);
}

void				ft_get_content_dir(t_ls *doll)//it's one chain for all directories so sorting do for all files
{
	t_argvs			*tmp_con;
	t_argvs			*tmp_content;
	
	while (doll->info_av)
	{
		doll->dirc = opendir(doll->info_av->path);
		printf("opendir = %s\n", doll->info_av->path);
		if (!doll->dirc)
		{
			perror("dir_open_error");
			exit(1);
		}
		while ((doll->entry = readdir(doll->dirc)))
		{
			// printf("test_entry\n");
			if (!(tmp_content = initiate_argvs()))
				ls_error(0);
			get_path_name(tmp_content, doll->info_av->path, doll->entry->d_name);
			if (!doll->content_av)
				doll->content_av = tmp_content;
			else
				tmp_con->next = tmp_content;
			tmp_con = tmp_content;
		}
		// 	ft_printf("%s  ", doll->entry->d_name);
		// ft_printf("\n");
		closedir(doll->dirc);
		doll->info_av = doll->info_av->next;
	}
}

void				ft_print_content(t_ls *doll)
{
	while (doll->content_av)
	{
		ft_sorting(doll, doll->content_av);
		ft_printf("%s  ", doll->content_av->name);
		ft_printf("\n");
		doll->content_av = doll->content_av->next;
	}
}

void			display_ls(t_ls *doll)
{
	// printf("test1\n");
	flags_sort(doll);
	ft_get_content_dir(doll);
	ft_print_content(doll);
}
