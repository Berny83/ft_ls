/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:28:03 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/31 20:03:57 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		*initiate(int argc, char **argv)
{
	t_ls		*new;

	if (!(new = (t_ls*)malloc(sizeof(t_ls))))
		ls_error(0);
	ft_memset(new, 0, sizeof(new));
	new->ac = argc;
	new->av = argv;
	new->optns.l = 0;
	new->optns.t = 0;
	new->optns.a = 0;
	new->optns.R = 0;
	new->optns.r = 0;
	if (!(new->info_av = (t_argvs*)malloc(sizeof(t_argvs))))
		return (NULL);
	ft_memset(new->info_av, 0, sizeof(t_argvs));
	return (new);
}

t_argvs			*initiate_argvs(void)
{
	t_argvs		*argvv;

	if (!(argvv = (t_argvs*)malloc(sizeof(t_argvs))))
		return (NULL);
	ft_memset(argvv, 0, sizeof(t_argvs));
	return (argvv);
}

int				main(int argc, char **argv)
{
	t_ls		*doll;
	
	doll = initiate(argc, argv);
	validate(doll);
	ft_ls(doll->info_av);
	display_ls(doll);
	free(doll);
	return (0);
}
