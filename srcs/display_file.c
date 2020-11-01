/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:21:59 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/01 23:09:24 by aagrivan         ###   ########.fr       */
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

void			get_max_len(t_argvs *curr, t_len *get_len)
{
	int			tmp;
	char		*s;

	tmp = 0;
	while (curr)
	{
		s = ft_itoa(curr->info.hlnk);
		tmp = ft_strlen(s);
		free(s);
		if (get_len->len_hlnk < tmp)
			get_len->len_hlnk = tmp;
		tmp = ft_strlen(curr->info.uname);
		if (get_len->len_uname < tmp)
			get_len->len_uname = tmp;
		tmp = ft_strlen(curr->info.gname);
		if (get_len->len_gname < tmp)
			get_len->len_gname = tmp;
		s = ft_itoa(curr->info.size);
		tmp = ft_strlen(s);
		free(s);
		if (get_len->len_size < tmp)
			get_len->len_size = tmp;
		tmp = ft_strlen(ctime(&curr->info.ltime_mod));
		if (get_len->len_time < tmp)
			get_len->len_time = tmp;
		curr = curr->next;
	}
}

void			ft_print_content(t_argvs *current, t_flags *fl)
{
	t_len		get_len;
	t_argvs		*head;

	get_len = initiate_len();
	head = current;
	if (!fl->l)
	{
		if (current->name[0] == '.' && fl->a)
			ft_printf("%s  ", current->name);
		else if (current->name[0] != '.')
			ft_printf("%s  ", current->name);
	}
	else if (fl->l)
	{
		get_max_len(current, &get_len);
		current = head;
		if (current->name[0] == '.' && fl->a)
		{
			display_mode(current, &get_len);
			ft_printf("\n");
		}
		else if (current->name[0] != '.')
		{
			display_mode(current, &get_len);
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
