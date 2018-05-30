/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:13:42 by dkrause-          #+#    #+#             */
/*   Updated: 2018/03/02 23:13:44 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns a pointer to a new string which is a duplicate of string s
** memory obtained with malloc(3) and freed with free(3)
*/

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*string;

	i = 0;
	while (s1[i])
		i++;
	string = (char*)malloc(sizeof(char) * i + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
