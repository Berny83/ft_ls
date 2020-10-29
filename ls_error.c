/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:53:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/28 21:36:55 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ls_error(int err)
{
	if (err == 0)
		perror("malloc_error");
	else if (err == 1)
		perror("invalid option -- \'-\'");
	else if (err == 2)
		perror("get_content_dir_error");
	exit(1);
}


void		free_list(t_argvs *content_av)
{
	while(content_av)
	{
		content_av = content_av->next;
		free(content_av->path);
		free(content_av->name);
		free(content_av);
	}
	free(content_av);
}

// void		free_dolly(t_ls *dolly)
// {
	
// }