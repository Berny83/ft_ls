/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:59 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/29 22:32:44 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			ft_print_content(t_argvs *current, t_flags *fl)//-a -l -R
{
	if (!fl->l)
	{
		if (current->name[0] == '.' && fl->a)
			ft_printf("%s  ", current->name);
		else if (current->name[0] != '.')
			ft_printf("%s  ", current->name);
	}
	else if (fl->l)
	{
		if (current->name[0] == '.' && fl->a)
		{
			display_mode(current);
			ft_printf("\n");
		}
		else if (current->name[0] != '.')
		{
			display_mode(current);
			ft_printf("\n");
		}
	}
}

bool			display_file(t_ls *doll)
{
	t_argvs		*curr;
	t_flags		fl;
	bool		done;

	done = false;
	curr = doll->info_av;
	fl = doll->optns;
	while (curr)
	{
		if (!curr->info.fruit.idir && !curr->not_exist)
		{
			ft_print_content(curr, &fl);
			done = true;
		}
		curr = curr->next;
	}
	return ((done) ? true : false);
}
