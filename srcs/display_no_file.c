/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_no_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:18:01 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/02 17:01:36 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_no_file(t_ls *doll)
{
	t_argvs	*curr;

	curr = doll->info_av;
	while (curr)
	{
		if (curr->info.not_exist)
			ft_printf("ft_ls: %s: No such file or directory\n", curr->name);
		curr = curr->next;
	}
}
