/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:14:11 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:14:12 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*mng_c(va_list *args, t_printf *p)
{
	char	*c;

	if (ft_strcmp(p->size, "l") == 0)
		c = mng_lc(args, p);
	else
	{
		c = ft_strnew(1);
		*c = va_arg(*args, int);
		if (*c == '\0')
			p->len_arg = 1;
		else
			p->len_arg = ft_strlen(c);
	}
	return (c);
}

char	*mng_lc(va_list *args, t_printf *p)
{
	wint_t	c;
	char	*c_unic;

	c = va_arg(*args, wint_t);
	c_unic = handle_unicode(c);
	if (*c_unic == '\0')
		p->len_arg = 1;
	else
		p->len_arg = ft_strlen(c_unic);
	return (c_unic);
}

char	*mng_s(va_list *args, t_printf *p)
{
	char	*str;

	if (ft_strcmp(p->size, "l") == 0)
		str = mng_ls(args, p);
	else
	{
		str = va_arg(*args, char *);
		if (str != NULL)
			str = ft_strdup(str);
		else if (str == NULL)
			str = ft_strdup("(null)");
	}
	return (str);
}

char	*mng_ls(va_list *args, t_printf *p)
{
	wchar_t	*arg;
	char	*tmp;
	char	*str_unic;
	int		i;
	int		len;

	i = 0;
	len = 0;
	arg = va_arg(*args, wchar_t*);
	if (arg == NULL)
	{
		str_unic = ft_strdup("(null)");
		return (str_unic);
	}
	str_unic = ft_strnew(0);
	while (arg[i] && (p->prec == -1 || len < p->prec))
	{
		tmp = handle_unicode(arg[i]);
		len += ft_strlen(tmp);
		ft_strdel(&tmp);
		if (p->prec == -1 || len <= p->prec)
			str_unic = ft_strjoin_free(str_unic, handle_unicode(arg[i]), 3);
		i++;
	}
	return (str_unic);
}

char	*mng_percent(va_list *args, t_printf *p)
{
	char *str;

	(void)(p);
	(void)(args);
	str = ft_strnew(1);
	*str = '%';
	return (str);
}
