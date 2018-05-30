/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:46 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:30:48 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** repeats the list 1st and applies function f to each link
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*list;

	list = lst;
	while (list)
	{
		(*f)(list);
		list = list->next;
	}
}
