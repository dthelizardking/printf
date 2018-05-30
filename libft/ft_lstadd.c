/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:30:35 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:30:36 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** adds element "new" at start of list
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL)
		new->next = *alst;
	*alst = new;
}
