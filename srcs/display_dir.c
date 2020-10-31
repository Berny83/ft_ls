/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:32:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/31 19:53:19 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ft_print_total(t_argvs *current)
{
	int				tog;

	tog = 0;
	while (current)
	{
		tog += current->total;
		current = current->next;
	}
	ft_printf("total %i\n", tog);
}

void				ft_print_content_dir(t_argvs *current, t_flags *fl)
{
	t_len		get_len;
	t_argvs		*head;

	get_len = initiate_len();
	head = current;
	get_max_len(current, &get_len);
	current = head;
	if (fl->l)
		ft_print_total(current);
	while (current)
	{
		if (!current->not_exist)
		{
			if (!fl->l)
			{
				if (current->name[0] == '.' && fl->a)
					ft_printf("%s\n", current->name);
				else if (current->name[0] != '.')
					ft_printf("%s\n", current->name);
			}
			else if (fl->l)
			{
				if (current->name[0] == '.' && fl->a)
				{
					display_mode(current, &get_len);
					ft_printf("\n");
				}
				else if (current->name[0] != '.')
				{
					display_mode(current, &get_len);
					ft_printf("\n");
				}
			}
		}
		current = current->next;
	}
}

t_argvs				*ft_get_content_dir(t_argvs *info_av, t_flags *fl)
{
	t_argvs			*content;
	t_argvs			*tmp_con;
	t_argvs			*new;
	DIR				*dirc;
	struct dirent 	*entry;

	new = initiate_argvs();
	if (!(dirc = opendir(info_av->path)))
	{
		ft_printf("ft_ls: cannot open directory '%s': Permission denied\n",\
		info_av->path);
		return (NULL);
	}
	while ((entry = readdir(dirc)))
	{
		if ((fl->a && ft_strcmp(entry->d_name, ".") && \
		ft_strcmp(entry->d_name, "..")) ||\
		(fl->a && entry->d_name[0] == '.') || (entry->d_name[0] != '.'))
		{
			if (!(content = initiate_argvs()))
				return (NULL);
			get_path_name(content, info_av->path, entry->d_name);
			if (!new->name)
				new = content;
			else
				tmp_con->next = content;
			tmp_con = content;
		}
	}
	closedir(dirc);
	return(new);
}

void				loopfol(t_argvs *curr, bool (*ft_sort)(t_argvs *), t_flags *fl, int ac)
{
	t_argvs			*head;
	t_argvs			*tmp;
	char			dirs;

	dirs = -2;
	if (!(head = ft_get_content_dir(curr, fl)))
		return ;
	ft_ls(head);
	tmp = head;
	if ((ac > 1 && !fl->R) || (fl->R))
	{
		while (head)
		{
			if (head->info.fruit.idir)
			{
				dirs++;
				if (dirs > 0 && fl->a)
					break ;
				else if (!fl->a && dirs > -2)
					break ;
			}			
			head = head->next;
		}
		head = tmp;
		if (curr->info.one && head->not_exist)
			return ;
		else if (curr->info.one && ((dirs > 0 && fl->a) || (dirs > -2 && !fl->a)))
			ft_printf("%s:\n", curr->path + 2);
		else if (!curr->info.one)
			ft_printf("\n%s:\n", curr->path + 2);
	}
	ft_sorting(ft_sort, head);
	tmp = head;
	if (!head->not_exist)
		ft_print_content_dir(head, fl);
	curr->info.one = false;
	if (fl->R)
	{
		head = tmp;
		while (head->name)
		{
			if (head->info.fruit.idir && ft_strcmp(head->name, ".") && \
			ft_strcmp(head->name, ".."))
			{
				loopfol(head, ft_sort, fl, ac);
			}
			head = head->next;
			if (!head)
				return ;
		}
	}
}

void				display_dir(t_ls *doll)
{
	t_argvs			*curr;

	curr = doll->info_av;
	curr->info.one = true;
	while (curr)
	{
		if (!curr->not_exist && curr->info.fruit.idir)
			loopfol(curr, doll->ft_sort, &doll->optns, doll->ac);
		curr = curr->next;
	}
}
