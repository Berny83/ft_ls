/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:32:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/29 23:00:53 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

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

void				ft_print_content_dir(t_argvs *current, t_flags *fl)//-a -l -R
{
	if (fl->l)
		ft_print_total(current);
	while (current)
	{
		if (!current->not_exist)
		{
			if (!fl->l)
			{
				if (current->name[0] == '.' && fl->a)
					ft_printf("%s  ", current->name);
				else if (current->name[0] != '.')
					ft_printf("%s  ", current->name);
			}
			else if (fl->l)
			{
				if (current->name[0] == '.' && fl->a)
				{
					display_mode(current);
					ft_printf("\n");
				}
				else if (current->name[0] != '.')
				{
					display_mode(current);
					ft_printf("\n");
				}
			}
		}
		current = current->next;
	}
	ft_printf("\n");
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

	if (!(head = ft_get_content_dir(curr, fl)))
		return ;
	if ((ac > 2 && !fl->R) || (fl->R))
		(fl->R) ? ft_printf("%s:\n", curr->path + 2) : \
		ft_printf("\n%s:\n", curr->path + 2);
	ft_ls(head);
	ft_sorting(ft_sort, head);
	tmp = head;
	ft_print_content_dir(head, fl);
	if (fl->R)
	{
		head = tmp;
		while (head->name)
		{
			if (head->info.fruit.idir && ft_strcmp(head->name, ".") && \
			ft_strcmp(head->name, ".."))
			{
				// free_list(head);
				// printf("re = %i\n", head->info.fruit.idir);
				loopfol(head, ft_sort, fl, ac);
			}
			head = head->next;
			if (!head)
				return ;
		}
	}
	// else
	// {
	// 	free_list(head);
	// 	free_list(tmp);
	// }
}

void				display_dir(t_ls *doll)
{
	t_argvs			*curr;

	curr = doll->info_av;
	while (curr)
	{
		if (!curr->not_exist && curr->info.fruit.idir)
			loopfol(curr, doll->ft_sort, &doll->optns, doll->ac);
		curr = curr->next;
	}
}
