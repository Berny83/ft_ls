/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:40:21 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 16:45:54 by aagrivan         ###   ########.fr       */
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

void				display_mode(t_argvs *content, t_len *get_len)
{
	char			*s;
	int				i;

	i = 3;
	ft_printf("%c", gt_type_file(content->info.fruit));
	while (i--)
	{
		s = gt_rigths(((content->info.mode >> 3 * i) & 7));
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
	ft_printf("\n");
}
