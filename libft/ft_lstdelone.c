/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:04 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:30:08 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** uses link's pointer address and frees the link's memory content using del
** then frees the link's memory using free(3). memory of next must not be freed
** under any circumstance.
** Lastly the pointer of the freed link must be set to null
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;

	list = *alst;
	del((list->content), list->content_size);
	free(list);
	(*alst) = NULL;
}
