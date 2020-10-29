/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:16:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/24 20:11:50 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_argvs				*ft_get_content_dir(t_argvs *info_av)
{
	t_argvs			*content;
	t_argvs			*tmp_con;
	t_argvs			*new;
	DIR				*dirc;
	struct dirent 	*entry;

	dirc = opendir(info_av->path);
	new = initiate_argvs();
	ft_printf("%s:\n", info_av->path);
	if (!dirc)
	{
		perror("dir_open_error");
		exit(1);
	}
	while ((entry = readdir(dirc)))
	{
		if (!(content = initiate_argvs()))
			ls_error(0);
		get_path_name(content, info_av->path, entry->d_name);
		if (!new->name)
			new = content;
		else
			tmp_con->next = content;
		tmp_con = content;
	}
	closedir(dirc);
	return(new);
}

void				ft_print_content(t_argvs *current, t_flags *fl)//-a -l -R
{
	if (!fl->l)
	{
		if (current->name[0] == '.' && fl->a == 1)
			ft_printf("%s  ", current->name);
		else if (current->name[0] != '.')
			ft_printf("%s  ", current->name);
	}
	else if (fl->l)
	{
		if (current->name[0] == '.' && fl->a == 1)
			display_mode(current);
		else if (current->name[0] != '.')
			display_mode(current);
	}
}

void				ft_print_content_dir(t_ls *doll)//-a -l -R
{
	while (doll->info_av)
	{
		if (!doll->optns.l)
		{
			if (doll->info_av->name[0] == '.' && doll->optns.a == 1)
				ft_printf("%s  ", doll->info_av->name);
			else if (doll->info_av->name[0] != '.')
				ft_printf("%s  ", doll->info_av->name);
		}
		else if (doll->optns.l)
		{
			if (doll->info_av->name[0] == '.' && doll->optns.a == 1)
			{
				display_mode(doll->info_av);
			}
			else if (doll->info_av->name[0] != '.')
				display_mode(doll->info_av);
		}
		doll->info_av= doll->info_av->next;
	}
}

void			ft_print_total(t_argvs *current)
{
	int			tog;

	tog = 0;
	while (current)
	{
		tog += current->total;
		current = current->next;
	}
	ft_printf("total %i\n", tog);
}

void			display_file(t_argvs *current, t_flags *fl)
{
	if (current->not_exist)
		ft_printf("ft_ls: cannot access '%s': No such file or directory\n", current->name);
	else
	{
		if (fl->l)
			ft_print_total(current);
		ft_print_content(current, fl);
	}
}

void			display_dir(t_argvs *current, bool (*ft_sort)(t_argvs *), t_flags *fl)
{
	t_ls		*dolly;
	t_argvs		*head;
	
	
	dolly = initiate();
	dolly->info_av = ft_get_content_dir(current);
	dolly->ft_sort = ft_sort;
	dolly->optns = *fl;
	ft_ls(dolly->info_av);
	if (fl->l)
		ft_print_total(current);
	ft_sorting(dolly->ft_sort, dolly->info_av);
	head = dolly->info_av;
	ft_print_content_dir(dolly);
	printf("\n");//redo
	if (fl->R)
	{
		dolly->info_av = head;
		while (dolly->info_av)
		{
			if (dolly->info_av->info.fruit.idir)
			{
				if (ft_strcmp(dolly->info_av->name, ".") && ft_strcmp(dolly->info_av->name, ".."))
					display_dir(dolly->info_av, dolly->ft_sort, &dolly->optns);
			}
			dolly->info_av = dolly->info_av->next;
		}
	}
	free(dolly);
	free_list(head);
}

void			display_ls(t_ls *doll)
{
	flags_sort(doll);
	while (doll->info_av)
	{
		if (!doll->info_av->info.fruit.idir)
			display_file(doll->info_av, &doll->optns);
		else
			display_dir(doll->info_av, doll->ft_sort, &doll->optns);
		if (doll->info_av)
			doll->info_av = doll->info_av->next;
		if (doll->info_av)
			ft_printf("\n");
	}
}

/*Segmentation fault + can't read all dirs in .git = segmentation fault + smtms push to the list not directory, but the regular file*/
/* titles ./.git/folder/ must be .git/folder/

	delete content_av;
	do everything by info_av;

	отдельный ft_print_content для файлов и для папок
	./ft_ls display_ls.c ex.c lib

	print_content redo flags and conditions -a 

	./ft_ls -a lib/
	before R = ./lib/.
	.  before R = ./lib/
*/
