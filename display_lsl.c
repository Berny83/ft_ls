/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lsl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 16:40:21 by aagrivan          #+#    #+#             */
/*   Updated: 2020/09/08 20:14:48 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		gt_type_file(t_type type)
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

char		*gt_rigths(int i)
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
	return ("error");
}

void		display_mode(t_argvs *content)
{
	char	*s;
	int		i;

	i = 3;
	ft_printf("%c", gt_type_file(content->info.fruit));
	while (i--)
	{
		s = gt_rigths(((content->info.mode >> 3 * i) & 7)); //0 3 6 16bits, last 9 - user(rwx) group(rwx) other(rwx)
		ft_printf("%s", s);
	}
	ft_printf(" %i %s %s\n", content->info.hlnk, content->info.uname, content->info.gname);
	//need to find length and columns to write size/data
}