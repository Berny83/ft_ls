/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lsl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:40:21 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/31 20:02:09 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			gt_type_file(t_type type)
{
	if (type.iblk)
		return ('b');
	else if (type.ichr)
		return ('c');
	else if (type.idir)
		return ('d');
	else if (type.ifif)
		return ('p');
	else if (type.ilnk)
		return ('l');
	else if (type.ireg)
		return ('-');
	else if (type.isck)
		return ('s');
	return (' ');
}

static char			*gt_rigths(int i)
{
	if (i == 7)
		return ("rwx");
	else if (i == 6)
		return ("rw-");
	else if (i == 5)
		return ("r-x");
	else if (i == 4)
		return ("r--");
	else if (i == 3)
		return ("-wx");
	else if (i == 2)
		return ("-w-");
	else if (i == 1)
		return ("--x");
	return ("---");
}

static void			print_time(t_argvs *content)
{
	char			*str_time;
	time_t			time;

	time = content->info.ltime_mod;
	str_time = ctime(&time);
	ft_printf("%.12s ", str_time + 4);
}

static void			print_hlnk(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_hlnk;
	write(1, "  ", 2);
	while (i-- > (int)(ft_strlen(ft_itoa(content->info.hlnk))))
		write(1, " ", 1);
	ft_printf("%i", content->info.hlnk);
}

static void			print_uname(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_uname;
	write(1, " ", 1);
	while (i-- > (int)ft_strlen(content->info.uname))
		write(1, " ", 1);
	ft_printf("%s", content->info.uname);
}

static void			print_gname(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_gname;
	write(1, "  ", 2);
	while (i-- > (int)ft_strlen(content->info.gname))
		write(1, " ", 1);
	ft_printf("%s", content->info.gname);
}

static void			print_size(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_size;
	write(1, "  ", 2);
	while (i-- > (int)ft_strlen(ft_itoa(content->info.size)))
		write(1, " ", 1);
	ft_printf("%i ", content->info.size);
}

void				display_mode(t_argvs *content, t_len *get_len)
{
	char			*s;
	int				i;

	i = 3;
	ft_printf("%c", gt_type_file(content->info.fruit));
	while (i--)
	{
		s = gt_rigths(((content->info.mode >> 3 * i) & 7)); //0 3 6 16bits, last 9 - user(rwx) group(rwx) other(rwx)
		ft_printf("%s", s);
	}
	print_hlnk(content, get_len);
	print_uname(content, get_len);
	print_gname(content, get_len);
	print_size(content, get_len);
	print_time(content);
	ft_printf("%s", content->name);
	if (content->info.fruit.ilnk)
		ft_printf(" -> %s", content->info.sym);
}
