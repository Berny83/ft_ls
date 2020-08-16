/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:29:26 by aagrivan          #+#    #+#             */
/*   Updated: 2020/08/16 17:12:20 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include <stdlib.h>
#include <sys/types.h> //opendir clossedir readdir stat lstat getpwuid getgrgid listxattr getxattr
#include <dirent.h>
#include <unistd.h> //readlink
#include <stdio.h>
#include "../111111/includes/ft_printf.h"

#include <errno.h> //perror errno
#include <string.h> //strerror
#include <time.h> //time ctime

#define FLAGS "-lRart"

typedef struct		s_ls
{
	char			l;
	char			R;
	char			a;
	char			r;
	char			t;
}					t_ls;

#endif