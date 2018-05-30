/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:26:27 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:26:28 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** outputs string s to fd followed by a newline
*/

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		write(fd, s, i);
		write(fd, "\n", 1);
	}
}
