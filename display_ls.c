/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:55:47 by aagrivan          #+#    #+#             */
/*   Updated: 2020/10/29 22:53:50 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void				display_ls(t_ls *doll)
{
	display_no_file(doll);
	flags_sort(doll);
	if (display_file(doll))
		ft_printf("\n");
	display_dir(doll);
}
