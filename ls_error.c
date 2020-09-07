/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:53:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/09/02 19:08:29 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ls_error(int err)
{
	if (err == 0)
		perror("malloc_error");
	else if (err == 1)
		perror("invalid option -- \'-\'");
	exit(1);
}


void		free_list(t_argvs *content_av)
{
	while(content_av)
	{
		content_av = content_av->next;
		free(content_av);
	}
	free(content_av);
}