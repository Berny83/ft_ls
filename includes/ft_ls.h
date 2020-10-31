/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:29:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/31 20:12:06 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

// #include <stdlib.h>
// #include <sys/types.h> // opendir clossedir readdir stat lstat getpwuid getgrgid listxattr getxattr
#include <sys/stat.h> //??? for some stat defines
#include <dirent.h>
// #include <unistd.h> // readlink
#include <stdio.h> // printf
#include "../libft/includes/ft_printf.h"
#include <errno.h> // perror errno
// #include <string.h> // strerror
#include <time.h> // time ctime
#include <sys/ioctl.h> // ioctl for multiple columns
#include <stdbool.h>
#include "../libft/includes/libft.h"

#define FLAGGS "-lRart"
#define SYMSIZE 1024

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
	char			sym[SYMSIZE + 1];
	bool			one;
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
	int				ac;
	char			**av;
	t_flags			optns;
	t_argvs			*info_av;
	bool			(*ft_sort)(t_argvs *mp);
}					t_ls;

typedef struct		s_len
{
	int				len_hlnk;
	int				len_uname;
	int				len_gname;
	int				len_size;
	int				len_time;
}					t_len;

// -------------main--------------------
void				validate(t_ls *doll);
void				ft_ls(t_argvs *example);
void				display_ls(t_ls *doll);

// ------------validate-----------------
t_argvs				*initiate_argvs(void);
void				parse_arguments(t_ls *doll);
t_argvs				*get_path_name(t_argvs *avv, char *path, char *nam);

// --------------sort-------------------
void				flags_sort(t_ls *doll);
void				ft_sorting(bool (*ft_sort)(t_argvs *), t_argvs *cur_struct);
bool				ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *current);
bool				check_alpha(t_argvs *current);
bool				check_alpha_r(t_argvs *current);
bool				check_time(t_argvs *current);
bool				check_time_r(t_argvs *current);

// -------------display-----------------
void				display_no_file(t_ls *doll);
bool				display_file(t_ls *doll);
void				ft_print_content(t_argvs *current, t_flags *fl);
void				display_dir(t_ls *doll);
void				loopfol(t_argvs *curr, bool (*ft_sort)(t_argvs *), t_flags *fl, int ac);
t_argvs				*ft_get_content_dir(t_argvs *info_av, t_flags *fl);
void				ft_print_content_dir(t_argvs *current, t_flags *fl);
// t_argvs				*ft_get_content_dir(t_argvs *info_av);

// -------------ls_error----------------
void				ls_error(int err);
void				free_list(t_argvs *content_av);

// -------------display_ls--------------
void				display_mode(t_argvs *content, t_len *get_len);

// -------------get_length--------------

t_len				initiate_len(void);
void				get_max_len(t_argvs *curr, t_len *get_len);

#endif
