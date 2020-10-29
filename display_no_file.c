/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_no_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:18:01 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/28 20:21:10 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		display_no_file(t_ls *doll)
{
	t_argvs	*curr;
	
	curr = doll->info_av;
	while (curr)
	{
		if (curr->not_exist)
			ft_printf("ft_ls: cannot access '%s': No such file or directory\n", curr->name);
		curr = curr->next;
	}
}