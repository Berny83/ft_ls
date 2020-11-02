/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:28:03 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 16:39:50 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls		initiate(int argc, char **argv)
{
	t_ls		new;

	ft_memset(&new, 0, sizeof(new));
	new.ac = argc;
	new.av = argv;
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
	t_ls		doll;

	doll = initiate(argc, argv);
	validate(&doll);
	ft_ls(doll.info_av);
	display_ls(&doll);
	free_list(doll.info_av);
	return (0);
}
