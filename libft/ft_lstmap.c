/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:55 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:30:56 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** repeats a list first and applies function f to each link to make a new list
** using malloc(3) resulting from the repeated applications of f.
** allocation failure results in NULL return
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*list_first;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = f(lst);
	list_first = list;
	while (lst->next)
	{
		lst = lst->next;
		list->next = f(lst);
		list = list->next;
	}
	return (list_first);
}
