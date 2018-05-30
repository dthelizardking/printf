/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:20:54 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:21:00 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** applies function f to each char of str passed as arg,
** and passes index ast 1st arg. each char passed by address to f
** to be modded if necessary
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
