/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:29:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/26 21:36:11 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

// #include <stdlib.h>
#include <sys/types.h> //opendir clossedir readdir stat lstat getpwuid getgrgid listxattr getxattr
#include <sys/stat.h> //??? for some stat defines
#include <dirent.h>
// #include <unistd.h> //readlink
#include <stdio.h>
#include "../../42printf/libftprintf/includes/ft_printf.h"

#include <errno.h> //perror errno
// #include <string.h> //strerror
#include <time.h> //time ctime
#include <sys/ioctl.h> //ioctl for multiple columns
#include <stdbool.h>

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
	unsigned char	not_exist: 1;
	t_flags			optns;
	t_argvs			*info_av; //occupied by arguments without sorting
	t_argvs			*content_av; //free
	// t_argvs			*last_av; //free
	bool			(*ft_sort)(t_argvs *mp);
}					t_ls;

void				ls_error(int err);
void				validate(t_ls *doll);
void				parse_arguments(t_ls *doll);
// t_argvs				*initiate_argvs(void);
void				get_path_name(t_argvs *avv, char *path, char *nam);
void				ft_ls(t_ls *doll);
void				get_fields(struct stat *file, t_argvs *within);

void				display_ls(t_ls *doll);
void				flags_sort(t_ls *doll);
void				ft_sorting(t_ls *doll, t_argvs *cur_struct);
bool				ft_swap(t_ls *doll, t_argvs *current);
void				ft_get_content_dir(t_ls *doll);
void				ft_print_content(t_ls *doll);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);

bool				check_alpha(t_argvs *current);
bool				check_alpha_r(t_argvs *current);
bool				check_time(t_argvs *current);
bool				check_time_r(t_argvs *current);

#endif
