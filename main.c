/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:28:03 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/26 19:04:08 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static t_ls			*initiate(int argc, char **argv)
{
	t_ls			*new;
	struct winsize	window;

	if (!(new = (t_ls*)malloc(sizeof(t_ls))))
		ls_error(0);
	ft_memset(new, 0, sizeof(new));
	new->ac = argc;
	new->av = argv;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window) == -1)
		new->colmn = 1;
	new->sizecol = window.ws_col;
	new->not_exist = 0;
	return(new);
}

int					main(int argc, char **argv)
{
	t_ls			*doll;
	
	doll = initiate(argc, argv);
	// ft_printf("%i", doll->optns.a);
	// printf("%i\n", doll->sizecol);
	// printf("%161s", "d");
	validate(doll);
	// doll->content_av = doll->info_av;
	// printf("s\n");
	ft_ls(doll);
	// printf("x\n");
	display_ls(doll);
	// free_all(doll);
	return(0);
}