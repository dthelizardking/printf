/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 22:54:34 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 22:54:36 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** checks if character is alphanumeric
*/

int		ft_isalnum(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	else if ((c >= 'A') && (c <= 'Z'))
		return (1);
	else if ((c >= 'a') && (c <= 'z'))
		return (1);
	return (0);
}
