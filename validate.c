/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:57:39 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/26 21:41:04 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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

static void		parse_options(t_ls *doll)
{
	while (*doll->av)
	{
		if (**doll->av == '-')
			(*doll->av)++;
		else
			return ;
		while(**doll->av)
		{
			get_options(**doll->av, doll);
			(*doll->av)++;
		}
		doll->av++;
	}
}

static t_argvs			*initiate_argvs(void)
{
	t_argvs		*argvv;

	if (!(argvv = (t_argvs*)malloc(sizeof(t_argvs))))
		return(NULL);
	ft_memset(argvv, 0, sizeof(argvv));
	argvv->next = NULL;
	return(argvv);
}

void			get_path_name(t_argvs *avv, char *path, char *nam)
{// . ./ ./includes ./includes/
	char		*route;
	char		*preroute;

	if (!(avv->name = ft_strdup(nam)))
		ls_error(0);
	if (!(route = ft_strnew(ft_strlen(path) + ft_strlen(nam) + 1)))
	 	ls_error(0);
	if (!ft_strcmp(path, nam))
	{
		if (!(preroute = ft_strdup("./")))
			ls_error(0);
	}
	route = ft_strcpy(route, nam);
	// ft_printf("strcpy = %s\n", route);
	if (!ft_strcmp(path, nam))
		route = ft_strcat(preroute, route);
	// ft_printf("strcpy = %s\n", route);
	avv->path = route;
	// ft_printf("fin = %s\n", avv->info.path);
}

void			parse_arguments(t_ls *doll)
{
	t_argvs		*avv;
	t_argvs		*tmp_av;
	
	if (!*doll->av)
	{
		// printf("current directory\n");
		if (!(doll->info_av = initiate_argvs()))
			ls_error(0);
		doll->info_av->name = ft_strdup(".");
		doll->info_av->path = ft_strdup(".");
	}
	else
	{
		while (*doll->av)
		{
			// printf("another directory\n");
			if (!(avv = initiate_argvs()))
				ls_error(0);
			get_path_name(avv, ".", *doll->av);
			if (!doll->info_av)
				doll->info_av = avv;
			else
				tmp_av->next = avv;
			tmp_av = avv;
			// ft_printf("fin = %s\n", *doll->av);
			doll->av++;
		}
	}
}

void			validate(t_ls *doll)
{
	doll->av++;
	if (doll->ac > 1)
	{
		if (**doll->av == '-')
			parse_options(doll);
	}
	ft_printf("a = %i\n", doll->optns.a);
	ft_printf("l = %i\n", doll->optns.l);
	ft_printf("R = %i\n", doll->optns.R);
	ft_printf("r = %i\n", doll->optns.r);
	ft_printf("t = %i\n", doll->optns.t);
	// ft_printf("before arguments = %s\n", *doll->av);
	// printf("\n");
	parse_arguments(doll);
	printf("\n");
	// while (doll->info_av)
	// {
	// 	ft_printf("info_av.name = %s\n", doll->info_av->name);
	// 	ft_printf("info_av.path = %s\n", doll->info_av->path);
	// 	doll->info_av = doll->info_av->next;
	// }
}