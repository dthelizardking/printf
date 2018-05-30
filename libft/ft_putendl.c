/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:25:04 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:25:06 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** outputs string s to the standard output followed by a newline
*/

void	ft_putendl(char const *s)
{
	int		i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
			i++;
		write(1, s, i);
		write(1, "\n", 1);
	}
}
