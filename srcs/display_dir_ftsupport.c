/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dir_ftsupport.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:12:17 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/05 14:15:11 by aagrivan         ###   ########.fr       */
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

static void			print_fl(t_argvs *current, t_flags *fl, t_len *get_len)
{
	if (!current->info.not_exist)
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
				display_mode(current, get_len);
			else if (current->name[0] != '.')
				display_mode(current, get_len);
		}
	}
}

void				ft_print_content_dir(t_argvs *current, t_flags *fl)
{
	t_len			get_len;
	t_argvs			*head;

	get_len = initiate_len();
	head = current;
	get_max_len(current, &get_len);
	current = head;
	if (fl->l)
		ft_print_total(current);
	while (current)
	{
		print_fl(current, fl, &get_len);
		current = current->next;
	}
}

t_argvs				*rentry(t_argvs *info, t_argvs *new, t_flags *fl, DIR *dirc)
{
	struct dirent	*entry;
	t_argvs			*content;
	t_argvs			*tmp_con;

	while ((entry = readdir(dirc)))
	{
		if ((fl->a && ft_strcmp(entry->d_name, ".") && \
		ft_strcmp(entry->d_name, "..")) ||\
		(fl->a && entry->d_name[0] == '.') || (entry->d_name[0] != '.'))
		{
			if (!(content = initiate_argvs()))
				return (NULL);
			get_path_name(content, info->path, entry->d_name);
			if (!new)
				new = content;
			else
				tmp_con->next = content;
			tmp_con = content;
		}
	}
	return (new);
}

t_argvs				*ft_get_content_dir(t_argvs *info_av, t_flags *fl)
{
	t_argvs			*new;
	DIR				*dirc;

	new = NULL;
	if (!(dirc = opendir(info_av->path)))
	{
		ft_printf("ft_ls: cannot open directory '%s': Permission denied\n",\
		info_av->path);
		return (NULL);
	}
	new = rentry(info_av, new, fl, dirc);
	if (dirc && (new == NULL))
	{
		if (!(new = initiate_argvs()))
			return (NULL);
		new->info.not_exist = 1;
	}
	closedir(dirc);
	return (new);
}
