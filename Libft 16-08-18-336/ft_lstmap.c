/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:08:26 by qduong            #+#    #+#             */
/*   Updated: 2021/06/11 23:28:27 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*newlist;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew((*f)(lst->content));
	if (!newlist)
		return (NULL);
	first = newlist;
	lst = lst->next;
	while (lst)
	{
		newlist -> next = ft_lstnew(f(lst->content));
		if (!newlist->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		newlist = newlist -> next;
		lst = lst->next;
	}
	newlist -> next = NULL;
	return (first);
}
