/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:34:03 by aagrivan          #+#    #+#             */
/*   Updated: 2019/09/23 15:31:10 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (lst && f)
	{
		while (lst)
		{
			new = (*f)(lst);
			new->next = ft_lstmap(lst->next, f);
			return (new);
		}
	}
	return (NULL);
}
