/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:20 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:30:22 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** takes address of pointer to a link and frees memory of link and
** every child of link using del and free(3). The pointer to link
** that was freed will be set to NULL
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*save;
	t_list		*list;

	list = *alst;
	while (list)
	{
		save = list;
		del((save->content), save->content_size);
		free(save);
		list = list->next;
	}
	*alst = NULL;
}
