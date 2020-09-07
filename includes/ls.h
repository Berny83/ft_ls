/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:29:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/09/05 14:55:03 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
#define LS_H

// #include <stdlib.h>
// #include <sys/types.h> //opendir clossedir readdir stat lstat getpwuid getgrgid listxattr getxattr
#include <sys/stat.h> //??? for some stat defines
#include <dirent.h>
// #include <unistd.h> //readlink
#include <stdio.h>
#include "../lib/includes/ft_printf.h"
#include <errno.h> //perror errno
// #include <string.h> //strerror
#include <time.h> //time ctime
#include <sys/ioctl.h> //ioctl for multiple columns
#include <stdbool.h>
#include "../lib/includes/libft.h"

#define FLAGGS "-lRart"

typedef struct		s_flags
{
	unsigned char	l:	1; //long
	unsigned char	R:	1; //recursive
	unsigned char	a:	1; //all
	unsigned char	r:	1; //reverse sort
	unsigned char	t:	1; //sort by time
}					t_flags; //битовые поля

typedef struct		s_type
{
	unsigned char	ireg: 1; //regular file
	unsigned char	idir: 1; //directory
	unsigned char	ilnk: 1; //soft link
	unsigned char	iblk: 1; //
	unsigned char	ichr: 1; //
	unsigned char	ifif: 1; //
	unsigned char	isck: 1; //socket
}					t_type;

typedef struct		s_data
{
	t_type			fruit; //type of file
	mode_t			mode;
	int				hlnk; //hard links
	char			*uname; //user name
	char			*gname; //group name
	int				size;
	time_t			ltime_mod;
}					t_data;

typedef struct		s_argvs
{
	int				total;
	char			*path;
	char			*name;
	unsigned char	not_exist: 1;
	t_data			info;
	struct s_argvs	*next;
}					t_argvs;

typedef struct		s_ls
{
	DIR				*dirc;
	struct dirent 	*entry;
	int				ac;
	char			**av;
	int				sizecol;
	unsigned char	colmn: 1;
	// int				total;
	t_flags			optns;
	t_argvs			*info_av; //occupied by arguments without sorting
	// t_argvs			*content_av; //directories content
	// t_argvs			*last; //free
	bool			(*ft_sort)(t_argvs *mp);
}					t_ls;

t_ls				*initiate(int argc, char **argv);
void				ls_error(int err);
t_argvs				*initiate_argvs(void);
void				validate(t_ls *doll);
void				parse_arguments(t_ls *doll);
void				get_path_name(t_argvs *avv, char *path, char *nam);
void				ft_ls(t_ls *doll);
void				get_fields(struct stat *file, t_argvs *within, t_ls *doll);

void				flags_sort(t_ls *doll);
void				ft_sorting(t_ls *doll, t_argvs *cur_struct);
bool				ft_swap(t_ls *doll, t_argvs *current);
void				ft_get_content_dir(t_ls *dolly, t_ls *doll);
void				ft_print_content(t_ls *dolly, t_ls *doll);
void				display_ls(t_ls *doll);
void				free_list(t_argvs *content_av);

bool				check_alpha(t_argvs *current);
bool				check_alpha_r(t_argvs *current);
bool				check_time(t_argvs *current);
bool				check_time_r(t_argvs *current);

#endif
