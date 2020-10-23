/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:16:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/23 20:12:51 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_ls				*ft_get_content_dir(t_ls *doll)
{
	t_ls			*new;
	t_argvs			*content;
	t_argvs			*tmp_con;

	new = initiate(doll->ac, doll->av);
	doll->dirc = opendir(doll->info_av->path);
	new->ft_sort = doll->ft_sort;
	new->optns = doll->optns;
	// if (doll->ac > 2)
	// 	ft_printf("%s:\n", doll->info_av->path);
	if (!doll->dirc)
	{
		perror("dir_open_error");
		exit(1);
	}
	while ((doll->entry = readdir(doll->dirc)))
	{
		if (!(content = initiate_argvs()))
			ls_error(0);
		// ft_printf("before path - %s:\n", doll->info_av->path);
		get_path_name(content, doll->info_av->path, doll->entry->d_name);
		if (!new->info_av->name)
			new->info_av = content;
		else
			tmp_con->next = content;
		tmp_con = content;
	}
	closedir(doll->dirc);
	return (new);
}

void				ft_print_content(t_ls *doll)//-a -l -R
{
	// while (doll->info_av)
	// {
		// ft_printf("test_ft_print_content\n");
		if (!doll->optns.l)
		{
			if (doll->info_av->name[0] == '.' && doll->optns.a == 1)
				ft_printf("%s  ", doll->info_av->name);
			else if (doll->info_av->name[0] != '.')
				ft_printf("%s  ", doll->info_av->name);
			// printf("dsplay_file = %s\n", doll->info_av->name);
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
		// printf("ft_print_content_file\n");
		// doll->info_av= doll->info_av->next;
	// }
}

void			ft_print_total(t_ls *doll)
{
	int			tog;

	tog = 0;
	while (doll->info_av)
	{
		tog += doll->info_av->total;
		doll->info_av = doll->info_av->next;
	}
	ft_printf("total %i\n", tog);
}

void			display_file(t_ls *doll)
{
	if (doll->info_av->not_exist)
		ft_printf("ft_ls: cannot access '%s': No such file or directory\n", doll->info_av->name);
	else
	{
		if (doll->optns.l)
			ft_print_total(doll);
		ft_print_content(doll);
	}
	// printf("done\n");
}

void			display_dir(t_ls *doll)
{
	t_ls		*dolly;
	t_argvs		*head;

	dolly = ft_get_content_dir(doll);
	// printf("before R = %s\n", doll->info_av->path);
	ft_ls(dolly->info_av);
	printf("before R = %s\n", dolly->info_av->path);
	if (doll->optns.l)
		ft_print_total(doll);
	ft_sorting(dolly, dolly->info_av);
	head = dolly->info_av;
	display_file(dolly); // -- loop???
	printf("before R = %s\n", doll->info_av->path);
	if (doll->optns.R)
	{
		//it must loop directories
		// printf("FOR R = %s\n", doll->info_av->path);
		dolly->info_av = head;
		while (dolly->info_av)
		{
			if (!ft_strcmp(doll->info_av->name, ".") && !ft_strcmp(doll->info_av->name, ".."))
				display_ls(dolly);
			dolly->info_av = dolly->info_av->next;
		}
	}
	free(dolly);
	free_list(head);
}

void			display_ls(t_ls *doll)
{
	flags_sort(doll);
	// printf("display_ls - entry\n");
	while (doll->info_av)
	{
		// printf("fruit idir = %i\n", doll->info_av->info.fruit.idir);
		// printf("display_ls - loop = %s\n", doll->info_av->path);
		if (!doll->info_av->info.fruit.idir)
			display_file(doll);
		else
			display_dir(doll);
		if (doll->info_av)
			doll->info_av = doll->info_av->next;
		if (doll->info_av)
			ft_printf("\n");
	}
	// printf("ft_print_content_file\n");
	/* if file - display_file else if dir - display_dir*/
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
