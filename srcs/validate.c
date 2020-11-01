/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:57:39 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 00:15:19 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_options(char c, t_ls *doll)
{
	if (c == '-')
	{
		free(doll);
		ls_error(1);
	}
	else if (c == 'l')
		doll->optns.l = 1;
	else if (c == 'R')
		doll->optns.R = 1;
	else if (c == 'a')
		doll->optns.a = 1;
	else if (c == 'r')
		doll->optns.r = 1;
	else if (c == 't')
		doll->optns.t = 1;
}

static int		parse_options(t_ls *doll)
{
	int			count_av;

	count_av = 0;
	while (*doll->av)
	{
		if (**doll->av == '-')
		{
			(*doll->av)++;
			count_av++;
		}
		else
			return (count_av);
		while (**doll->av)
		{
			get_options(**doll->av, doll);
			(*doll->av)++;
		}
		doll->av++;
	}
	return (count_av);
}

t_argvs			*get_path_name(t_argvs *avv, char *path, char *nam)
{
	char		*route;

	if (!(avv->name = ft_strdup(nam)))
		ls_error(0);
	if (!(route = ft_strnew(ft_strlen(path) + ft_strlen(nam) + 1)))
		ls_error(0);
	route = ft_strcpy(route, path);
	if (route[ft_strlen(route) - 1] != '/')
		route = ft_strcat(route, "/");
	route = ft_strcat(route, nam);
	avv->path = route;
	return (avv);
}

void			parse_arguments(t_ls *doll)
{
	t_argvs		*avv;
	t_argvs		*tmp_av;

	if (!*doll->av)
	{
		if (!(doll->info_av = initiate_argvs()))
			ls_error(0);
		doll->info_av->name = ft_strdup(".");
		doll->info_av->path = ft_strdup("./.");
	}
	else
	{
		while (*doll->av)
		{
			if (!(avv = initiate_argvs()))
				ls_error(0);
			get_path_name(avv, ".", *doll->av);
			if (!doll->info_av)
				doll->info_av = avv;
			else
				tmp_av->next = avv;
			tmp_av = avv;
			doll->av++;
		}
	}
}

void			validate(t_ls *doll)
{
	int			count;

	count = 1;
	doll->av++;
	if (doll->ac > 1)
	{
		if (**doll->av == '-')
			count += parse_options(doll);
	}
	doll->ac -= count;
	parse_arguments(doll);
}
