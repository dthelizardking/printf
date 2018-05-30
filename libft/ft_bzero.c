/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:38:03 by dkrause-          #+#    #+#             */
/*   Updated: 2018/02/21 21:38:05 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** writes zeros to erase data in the n byte memory pointed to by s
*/

void	ft_bzero(void *s, size_t n)
{
	char	*s1;

	s1 = s;
	while (n != 0)
	{
		*s1++ = 0;
		n--;
	}
}
