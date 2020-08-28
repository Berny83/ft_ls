/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:10:50 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/26 19:06:06 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"
#include <pwd.h>
#include <grp.h>

static t_type		get_type_file(struct stat *file)
{
	t_type			result;
	
	// printf("%o\n", file->st_mode);
	// printf("%o\n", __S_IFDIR);
	if ((file->st_mode & __S_IFREG) == __S_IFREG)
		result.ireg = 1;
	else if ((file->st_mode & __S_IFDIR) == __S_IFDIR)
		result.idir = 1;
	else if ((file->st_mode & __S_IFLNK) == __S_IFLNK)
		result.ilnk = 1;
	else if ((file->st_mode & __S_IFBLK) == __S_IFBLK)
		result.iblk = 1;
	else if ((file->st_mode & __S_IFCHR) == __S_IFCHR)
		result.ichr = 1;
	else if ((file->st_mode & __S_IFIFO) == __S_IFIFO)
		result.ifif = 1;
	else if ((file->st_mode & __S_IFSOCK) == __S_IFSOCK)
		result.isck = 1;
	// ft_printf("%i\n", result.idir);
	return(result);
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
	within->total += file->st_blocks;
	within->info.mode = file->st_mode;
	within->info.fruit = get_type_file(file);
	within->info.hlnk = file->st_nlink;
	get_user_group_name(within, file);
	within->info.size = file->st_size;
	within->info.ltime_mod = file->st_ctime;
}

void				ft_ls(t_ls *doll)
{
	t_argvs			*within;
	struct stat		file;

	within = doll->info_av;
	while (within)
	{
		if (!lstat(within->path, &file))
			get_fields(&file, within);
		else
			doll->not_exist = 1;
		within = within->next;
	}
	// printf("d");
}