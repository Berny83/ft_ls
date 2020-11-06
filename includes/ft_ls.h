/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:29:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/06 19:47:08 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>
# include <dirent.h>
# include "../libft/includes/ft_printf.h"
# include <stdio.h>
# include <time.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# define FLAGGS "1lRart"
# define SYMSIZE 1024

typedef struct				s_flags
{
	unsigned char	l:		1;
	unsigned char	up_r:	1;
	unsigned char	a:		1;
	unsigned char	r:		1;
	unsigned char	t:		1;
}							t_flags;

typedef struct				s_type
{
	unsigned char	ireg:	1;
	unsigned char	idir:	1;
	unsigned char	ilnk:	1;
	unsigned char	iblk:	1;
	unsigned char	ichr:	1;
	unsigned char	ifif:	1;
	unsigned char	isck:	1;
}							t_type;

typedef struct				s_data
{
	t_type					fruit;
	mode_t					mode;
	int						hlnk;
	char					*uname;
	char					*gname;
	int						size;
	time_t					ltime_mod;
	char					sym[SYMSIZE + 1];
	bool					one;
	unsigned char			not_exist: 1;
}							t_data;

typedef struct				s_argvs
{
	int						total;
	char					*path;
	char					*name;
	t_data					info;
	struct s_argvs			*next;
	struct s_argvs			*prev;
}							t_argvs;

typedef struct				s_ls
{
	int						ac;
	char					**av;
	t_flags					optns;
	t_argvs					*info_av;
	bool					(*ft_sort)(t_argvs *mp);
}							t_ls;

typedef struct				s_len
{
	int						len_hlnk;
	int						len_uname;
	int						len_gname;
	int						len_size;
	int						len_time;
}							t_len;

void						validate(t_ls *doll);
void						ft_ls(t_argvs *example);
void						display_ls(t_ls *doll);
t_argvs						*initiate_argvs(void);
void						parse_arguments(t_ls *doll);
t_argvs						*get_path_name(t_argvs *avv, char *path, char *nam);
void						flags_sort(t_ls *doll);
void						sorting(bool (*ft_sort)(t_argvs *), t_argvs *curr);
bool						ft_swap(bool (*ft_sort)(t_argvs *), t_argvs *curr);
bool						check_alpha(t_argvs *current);
bool						check_alpha_r(t_argvs *current);
bool						check_time(t_argvs *current);
bool						check_time_r(t_argvs *current);
void						display_no_file(t_ls *doll);
bool						display_file(t_ls *doll);
void						ft_print_content(t_argvs *current,\
t_flags *fl, t_len *get_len);
void						display_dir(t_ls *doll);
void						loop(t_argvs *cur, bool (*ft_sort)(t_argvs *),\
t_flags *fl, int ac);
void						loop_up_r(t_argvs *head, \
bool (*ft_sort)(t_argvs *), t_flags *fl, int ac);
t_argvs						*ft_get_content_dir(t_argvs *info_av, t_flags *fl);
t_argvs						*rentry(t_argvs *info, t_argvs *new, \
t_flags *fl, DIR *dirc);
void						header(t_argvs *curr);
void						ft_print_content_dir(t_argvs *current, t_flags *fl);
void						ls_error(int err);
void						free_list(t_argvs *content_av);
void						display_mode(t_argvs *content, t_len *get_len);
t_len						initiate_len(void);
void						get_max_len(t_argvs *curr, t_len *get_len);
void						print_time(t_argvs *content);
void						print_hlnk(t_argvs *content, t_len *get_len);
void						print_uname(t_argvs *content, t_len *get_len);
void						print_gname(t_argvs *content, t_len *get_len);
void						print_size(t_argvs *content, t_len *get_len);
t_argvs						*reverse_time(t_argvs *pr);
t_argvs						*tmp_reverse(t_argvs *tmp, t_argvs *new,\
t_argvs *hd, t_argvs *lst);

#endif
