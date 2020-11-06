/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:45:21 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/06 19:25:22 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_time(t_argvs *content)
{
	char			*str_time;
	time_t			ttime;

	ttime = content->info.ltime_mod;
	str_time = ctime(&ttime);
	ttime = time(NULL);
	ft_printf("%3.3s ", str_time + 4);
	ft_printf("%2.2s ", str_time + 8);
	if (content->info.ltime_mod < 15778800 || content->info.ltime_mod > ttime)
		ft_printf("%5.4s ", str_time + 20);
	else
		ft_printf("%5.5s ", str_time + 11);
}

void				print_hlnk(t_argvs *content, t_len *get_len)
{
	int				i;
	char			*s;

	i = get_len->len_hlnk;
	write(1, "  ", 2);
	s = ft_itoa(content->info.hlnk);
	while (i-- > (int)(ft_strlen(s)))
		write(1, " ", 1);
	ft_printf("%i", content->info.hlnk);
	free(s);
}

void				print_uname(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_uname;
	write(1, " ", 1);
	while (i-- > (int)ft_strlen(content->info.uname))
		write(1, " ", 1);
	ft_printf("%s", content->info.uname);
}

void				print_gname(t_argvs *content, t_len *get_len)
{
	int				i;

	i = get_len->len_gname;
	write(1, "  ", 2);
	while (i-- > (int)ft_strlen(content->info.gname))
		write(1, " ", 1);
	ft_printf("%s", content->info.gname);
}

void				print_size(t_argvs *content, t_len *get_len)
{
	int				i;
	char			*s;

	i = get_len->len_size;
	s = ft_itoa(content->info.size);
	write(1, "  ", 2);
	while (i-- > (int)ft_strlen(s))
		write(1, " ", 1);
	ft_printf("%i ", content->info.size);
	free(s);
}
