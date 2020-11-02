/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:53:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 16:37:19 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_error(int err)
{
	if (err == 0)
		ft_printf("usage: ft_ls [-lRart] [file ...]\n");
	else if (err == 1)
		perror("malloc_error");
	exit(1);
}

void		free_list(t_argvs *content_av)
{
	t_argvs	*tmp;

	while (content_av)
	{
		tmp = content_av->next;
		free(content_av->path);
		content_av->path = NULL;
		free(content_av->name);
		content_av->name = NULL;
		free(content_av->info.uname);
		content_av->info.uname = NULL;
		free(content_av->info.gname);
		content_av->info.gname = NULL;
		free(content_av);
		content_av = tmp;
	}
	free(content_av);
}
