/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:10:50 by aagrivan          #+#    #+#             */
/*   Updated: 2020/09/07 18:53:05 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <pwd.h>
#include <grp.h>

static void			get_type_file(struct stat *file, t_argvs *within)
{
	// printf("%o\n", file->st_mode);
	// printf("%o\n", __S_IFDIR);
	if ((file->st_mode & S_IFREG) == S_IFREG)
		within->info.fruit.ireg = 1;
	else if ((file->st_mode & S_IFDIR) == S_IFDIR)
		within->info.fruit.idir = 1;
	else if ((file->st_mode & S_IFLNK) == S_IFLNK)
		within->info.fruit.ilnk = 1;
	else if ((file->st_mode & S_IFBLK) == S_IFBLK)
		within->info.fruit.iblk = 1;
	else if ((file->st_mode & S_IFCHR) == S_IFCHR)
		within->info.fruit.ichr = 1;
	else if ((file->st_mode & S_IFIFO) == S_IFIFO)
		within->info.fruit.ifif = 1;
	else if ((file->st_mode & S_IFSOCK) == S_IFSOCK)
		within->info.fruit.isck = 1;
	// ft_printf("%i\n", result.idir);
}

static void			get_user_group_name(t_argvs *within, struct stat *file)
{
	struct passwd	*user;
	struct group	*grp;

	if ((user = getpwuid(file->st_uid)))
		within->info.uname = user->pw_name;
	else
		within->info.uname = ft_itoa_base(10, file->st_uid);
	if ((grp = getgrgid(file->st_gid)))
		within->info.gname = grp->gr_name;
	else
		within->info.gname = ft_itoa_base(10, file->st_gid);
}

void				get_fields(struct stat *file, t_argvs *within)
{
	ft_printf("dfdf<%s>\n", within->path);
	// doll->info_av->total += (file->st_blksize / 512);//change one step higher
	within->total = file->st_blocks;
	// ft_printf("%s ", within->path);
	ft_printf("file->st_blocks = %i\n", file->st_blocks);
	within->info.mode = file->st_mode;
	get_type_file(file, within);
	within->info.hlnk = file->st_nlink;
	get_user_group_name(within, file);
	within->info.size = file->st_size;
	within->info.ltime_mod = file->st_ctime;
}

// void				ft_ls(t_ls *doll)
void				ft_ls(t_argvs *example)
{
	t_argvs			*within;
	struct stat		file;

	within = example;
	while (within)
	{
		if (!lstat(within->path, &file))
			get_fields(&file, within);
		else
			within->not_exist = 1;
		// ft_printf("%s - ", within->path);
		// ft_printf("%i\n", file.st_blocks);
		// ft_printf("%i\n", file.st_blksize / 512);
		within = within->next;
	}
}