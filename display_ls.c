/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:16:29 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/22 16:21:05 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void				ft_get_content_dir(t_ls *doll)
{
	t_argvs			*tmp_con;
	t_argvs			*tmp_content;

	doll->dirc = opendir(doll->info_av->path);
	if (doll->ac > 2)
		ft_printf("%s:\n", doll->info_av->path);
	if (!doll->dirc)
	{
		perror("dir_open_error");
		exit(1);
	}
	while ((doll->entry = readdir(doll->dirc)))
	{
		if (!(tmp_content = initiate_argvs()))
			ls_error(0);
		// ft_printf("before path - %s:\n", doll->info_av->path);
		// ft_printf("before path name - %s:\n", doll->entry->d_name);
		get_path_name(tmp_content, doll->info_av->path, doll->entry->d_name);
		if (!doll->content_av)
			doll->content_av = tmp_content;
		else
			tmp_con->next = tmp_content;
		tmp_con = tmp_content;
	}
	closedir(doll->dirc);
}

void				ft_print_content(t_ls *doll)//-a -l -R
{
	while (doll->content_av)
	{
		// ft_printf("test_ft_print_content\n");
		if (!doll->optns.l)
		{
			if (doll->content_av->name[0] == '.' && doll->optns.a == 1)
				ft_printf("%s  ", doll->content_av->name);
			else if (doll->content_av->name[0] != '.')
				ft_printf("%s  ", doll->content_av->name);
		}
		else if (doll->optns.l)
		{
			if (doll->content_av->name[0] == '.' && doll->optns.a == 1)
			{
				display_mode(doll->content_av);
			}
			else if (doll->content_av->name[0] != '.')
				display_mode(doll->content_av);
		}
		doll->content_av= doll->content_av->next;
	}
	ft_printf("\n");
}

void			ft_print_total(t_ls *doll)
{
	int			tog;

	tog = 0;
	while (doll->content_av)
	{
		tog += doll->content_av->total;
		doll->content_av = doll->content_av->next;
	}
	ft_printf("total %i\n", tog);
}

void			gt_directories(t_ls *dolly, t_ls *doll)
{
	t_argvs		*tmp_dolly;
	t_argvs		*nne;
	
	dolly->ft_sort = doll->ft_sort;
	dolly->optns = doll->optns;
	dolly->sizecol = doll->sizecol;
	dolly->colmn = doll->colmn;
	dolly->content_av = NULL;
	while (doll->content_av)
	{
		if (doll->content_av->info.fruit.idir == 1 && ft_strcmp(doll->content_av->name, ".") && ft_strcmp(doll->content_av->name, ".."))
		{
			if (!(tmp_dolly = initiate_argvs()))
				ls_error(0);
			printf("dolly2 = %s\n", doll->content_av->name);
			get_path_name(tmp_dolly, doll->content_av->path, "");
			if (!dolly->info_av->path)
				dolly->info_av = tmp_dolly;
			else
				nne->next = tmp_dolly;
			nne = tmp_dolly;
		}
		doll->content_av = doll->content_av->next;
	}
}

void			display_file(t_ls *doll)
{
	if (doll->optns.l)
		ft_print_total(doll);
	ft_print_content(doll);
}

void			display_dir(t_ls *doll)
{
	t_argvs		*head;
	t_ls		*dolly;
	
	ft_get_content_dir(doll);
	ft_ls(doll->content_av);
	head = doll->content_av;
	if (doll->optns.l)
		ft_print_total(doll);
	doll->content_av = head;
	ft_sorting(doll, doll->content_av);
	ft_print_content(doll);
	doll->content_av = head;
	// printf("before R = %s\n", doll->content_av->path);
	if (doll->optns.R)
	{
		// printf("testo\n");
		printf("FOR R = %s\n", doll->content_av->path);
		dolly = initiate(doll->ac, doll->av);
		gt_directories(dolly, doll);
		if (dolly->info_av->path)
			display_ls(dolly);
		free(dolly);
	}
	free_list(doll->content_av);
}

void			display_ls(t_ls *doll)
{
	flags_sort(doll);
	while (doll->info_av)
	{
		if (!doll->info_av->info.fruit.idir)
			display_file(doll);
		else
			display_dir(doll);
		doll->info_av = doll->info_av->next;
		if (doll->info_av)
			ft_printf("\n");
	}
	/* if file - display_file else if dir - display_dir*/
}

/*Segmentation fault + can't read all dirs in .git = segmentation fault + smtms push to the list not directory, but the regular file*/
/* titles ./.git/folder/ must be .git/folder/

	delete content_av;
	do everything by info_av;
*/
