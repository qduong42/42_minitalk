/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:13:42 by qduong            #+#    #+#             */
/*   Updated: 2021/06/09 03:07:29 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*current;

	current = lst;
	if (lst)
	{
		while (current->next != NULL)
		{
			(*f)(current->content);
			current = current ->next;
		}
		(*f)(current->content);
	}
	return ;
}
