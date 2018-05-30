/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:16:38 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:16:44 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates with malloc(3) and returns a fresh string
** ending with "\0". Each char of str is started at '\0'
** Allocation failure returns NULL
*/

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(new, '\0', size + 1);
	return (new);
}
