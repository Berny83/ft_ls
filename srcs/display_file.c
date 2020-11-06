/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:59 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/06 19:45:58 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_len			initiate_len(void)
{
	t_len		new;

	new.len_hlnk = 0;
	new.len_uname = 0;
	new.len_gname = 0;
	new.len_size = 0;
	new.len_time = 0;
	return (new);
}

static int		string_toint(int nb)
{
	char		*s;
	int			tmp;

	s = ft_itoa(nb);
	free(s);
	tmp = ft_strlen(s);
	return (tmp);
}

void			get_max_len(t_argvs *curr, t_len *get_len)
{
	int			tmp;

	tmp = 0;
	while (curr)
	{
		tmp = string_toint(curr->info.hlnk);
		if (get_len->len_hlnk < tmp)
			get_len->len_hlnk = tmp;
		tmp = ft_strlen(curr->info.uname);
		if (get_len->len_uname < tmp)
			get_len->len_uname = tmp;
		tmp = ft_strlen(curr->info.gname);
		if (get_len->len_gname < tmp)
			get_len->len_gname = tmp;
		tmp = string_toint(curr->info.size);
		if (get_len->len_size < tmp)
			get_len->len_size = tmp;
		tmp = ft_strlen(ctime(&curr->info.ltime_mod));
		if (get_len->len_time < tmp)
			get_len->len_time = tmp;
		curr = curr->next;
	}
}

void			ft_print_content(t_argvs *current, t_flags *fl, t_len *get_len)
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
			display_mode(current, get_len);
		else if (current->name[0] != '.')
			display_mode(current, get_len);
	}
}

bool			display_file(t_ls *doll)
{
	t_argvs		*curr;
	t_flags		fl;
	bool		done[2];
	t_len		get_len;

	done[0] = false;
	done[1] = false;
	get_len = initiate_len();
	curr = doll->info_av;
	get_max_len(doll->info_av, &get_len);
	fl = doll->optns;
	while (curr)
	{
		if (!curr->info.fruit.idir && !curr->info.not_exist)
		{
			ft_print_content(curr, &fl, &get_len);
			done[0] = true;
		}
		else if (curr->info.fruit.idir)
			done[1] = true;
		curr = curr->next;
	}
	return ((done[0] && done[1]) ? true : false);
}
