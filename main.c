/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:28:03 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/16 18:13:07 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int			main(int ac, char **av)
{
	DIR		*dirc;
	struct dirent *entry;
	
	dirc = opendir(".");
	if (!dirc)
	{
		perror("dir_open_error");
		exit(1);
	}
	if (ac == 1)
	{
		while ((entry = readdir(dirc)))
			ft_printf("%d - %s [%d] %d\n", entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
	}
	else
	{

	}
	closedir(dirc);
	return(0);
}