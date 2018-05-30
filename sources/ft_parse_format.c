/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:13:22 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:13:24 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*ft_parse_width(t_printf *p)
{
	if ('0' < *p->f && *p->f <= '9')
	{
		p->width = 0;
		while (ft_isdigit(*p->f))
			p->width = p->width * 10 + ((*p->f++) - '0');
	}
	return (p->f);
}

static char	*ft_parse_precision(t_printf *p)
{
	if (*p->f == '.')
	{
		p->prec = 0;
		p->f++;
		while (ft_isdigit(*p->f))
			p->prec = p->prec * 10 + ((*p->f++) - '0');
	}
	return (p->f);
}

static char	*ft_parse_size(t_printf *p)
{
	if (*p->f == 'h' && !ft_strchr("ljz", *p->size))
		p->size = (*(p->f + 1) == 'h' && ++p->f) ? "hh" : "h";
	else if (*p->f == 'l' && !ft_strchr("jz", *p->size))
		p->size = (*(p->f + 1) == 'l' && ++p->f) ? "ll" : "l";
	else if (*p->f == 'j' && !ft_strchr("z", *p->size))
		p->size = "j";
	else if (*p->f == 'z')
		p->size = "z";
	else if (!ft_strchr("hljz", *p->f) || *p->f == '\0')
		return (p->f);
	return (p->f + 1);
}

static char	*ft_parse_type(t_printf *p)
{
	int		i;
	char	*letter;

	i = 0;
	letter = "dDiOoUuXxCcSsp";
	if ((ft_strchr(letter, *p->f) || *p->f == '%') && *p->f != '\0')
	{
		p->type = *p->f;
		return (p->f + 1);
	}
	return (p->f);
}

char		*ft_parse_flags(t_printf *p)
{
	size_t	i;

	i = 0;
	while ((p->f[i] == '#' || p->f[i] == '0' || p->f[i] == '-'
	|| p->f[i] == '+' || p->f[i] == ' ') && p->f[i] != '\0')
		i++;
	if (i > 0)
		p->flags = ft_strncat_nocpy(p->flags, p->f, i);
	p->f += i;
	p->f = ft_parse_width(p);
	p->f = ft_parse_precision(p);
	p->f = ft_parse_size(p);
	p->f = ft_parse_type(p);
	return (p->f);
}
