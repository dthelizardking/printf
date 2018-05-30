/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:34:57 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:34:58 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates first occurence of the null terminated
** str "little" in the null terminated str "big"
*/

char	*ft_strstr(const char *big, const char *little)
{
	char	*next;
	char	*key;

	if (*big == '\0' && *little == '\0')
		return ((char*)big);
	while (*big)
	{
		next = (char*)big;
		key = (char*)little;
		while ((*big) && (*key) && (*big == *key))
		{
			big++;
			key++;
		}
		if (*key == '\0')
			return (next);
		big = next + 1;
	}
	return (0);
}
