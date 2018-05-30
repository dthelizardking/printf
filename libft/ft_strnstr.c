/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 05:15:28 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/05 05:15:30 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates first occurence of the null terminated
** str "little" in the null terminated str "big"
** chars that appear after a '\0' are not searched
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;

	b = ft_strstr(big, little);
	if ((b - big) + ft_strlen(little) > len)
		return (NULL);
	return (b);
}
