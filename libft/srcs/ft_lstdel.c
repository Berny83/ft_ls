/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:22:26 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/23 15:22:24 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	if (alst && *alst && del)
	{
		lst = *alst;
		while (lst)
		{
			nxtlst = lst->next;
			(*del)(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		*alst = NULL;
	}
}
