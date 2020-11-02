/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:10:50 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 17:03:59 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <pwd.h>
#include <grp.h>

static void			get_type_file(struct stat *file, t_argvs *within)
{
	int				len_sym;

	if ((file->st_mode & S_IFMT) == S_IFLNK)
	{
		within->info.fruit.ilnk = 1;
		if ((len_sym = readlink(within->path, within->info.sym, SYMSIZE)) != -1)
			within->info.sym[len_sym] = '\0';
	}
	else if ((file->st_mode & S_IFMT) == S_IFSOCK)
		within->info.fruit.isck = 1;
	else if ((file->st_mode & S_IFMT) == S_IFREG)
		within->info.fruit.ireg = 1;
	else if ((file->st_mode & S_IFMT) == S_IFBLK)
		within->info.fruit.iblk = 1;
	else if ((file->st_mode & S_IFMT) == S_IFDIR)
		within->info.fruit.idir = 1;
	else if ((file->st_mode & S_IFMT) == S_IFCHR)
		within->info.fruit.ichr = 1;
	else if ((file->st_mode & S_IFMT) == S_IFIFO)
		within->info.fruit.ifif = 1;
}

static void			get_user_group_name(t_argvs *within, struct stat *file)
{
	struct passwd	*user;
	struct group	*grp;

	if ((user = getpwuid(file->st_uid)))
		within->info.uname = ft_strdup(user->pw_name);
	else
		within->info.uname = ft_itoa_base(10, file->st_uid);
	if ((grp = getgrgid(file->st_gid)))
		within->info.gname = ft_strdup(grp->gr_name);
	else
		within->info.gname = ft_itoa_base(10, file->st_gid);
}

static void			get_fields(struct stat *file, t_argvs *within)
{
	within->total = file->st_blocks;
	within->info.mode = file->st_mode;
	get_type_file(file, within);
	within->info.hlnk = file->st_nlink;
	get_user_group_name(within, file);
	within->info.size = file->st_size;
	within->info.ltime_mod = file->st_mtime;
	within->info.not_exist = 0;
}

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
			within->info.not_exist = 1;
		within = within->next;
	}
}
