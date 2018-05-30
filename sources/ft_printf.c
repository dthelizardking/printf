/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkrause- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:13:36 by dkrause-          #+#    #+#             */
/*   Updated: 2018/05/29 21:13:37 by dkrause-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_func	g_tab[] =
{
	{&mng_c, 'c'}, {&mng_lc, 'C'}, {&mng_s, 's'}, {&mng_ls, 'S'},
	{&mng_sb10, 'd'}, {&mng_sb10, 'i'}, {&mng_sb10, 'D'},
	{&mng_ub10, 'u'}, {&mng_ub10, 'U'}, {&mng_ub16_min, 'x'},
	{&mng_ub16_maj, 'X'}, {&mng_ub16_min, 'p'}, {&mng_ub8, 'o'},
	{&mng_ub8, 'O'}, {&mng_percent, '%'}, {NULL, -1}
};

static char	*cpy(char *format, t_printf *my_struc)
{
	size_t		i;
	char		*str;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	str = ft_strsub(format, 0, i);
	my_struc->len_arg = ft_strlen(str);
	return (str);
}

static char	*handle_args(va_list *arg, t_printf *p)
{
	int		i;
	char	*str;

	i = 0;
	while (g_tab[i].key != -1)
	{
		if (g_tab[i].key == p->type)
		{
			str = g_tab[i].ptrfunc(arg, p);
			str = handle_precision(str, p);
			return (str);
		}
		i++;
	}
	return (NULL);
}

static char	*analyse(va_list *arg, t_printf *p)
{
	char		*psbl;
	char		*str;

	if (*p->f == '\0')
		return (NULL);
	psbl = "cCsSdDioOuUxXp0#-+ .hljz%";
	while ((ft_strchr(psbl, *p->f) || ft_isdigit(*p->f)) && (*p->f != '\0'
	&& p->type == 0))
		p->f = ft_parse_flags(p);
	if (!p->type)
	{
		if (*p->f != '\0')
		{
			str = ft_strnew(1);
			*str = *p->f;
			str = handle_precision(str, p);
			p->f++;
		}
		else
			str = ft_strdup("");
		return (str);
	}
	str = handle_args(arg, p);
	return (str);
}

static char	*to_print(char *str, va_list *args, t_printf *p)
{
	char		*tmp;

	while (*p->f != '\0')
	{
		str = ft_memjoin(str, cpy(p->f, p), p->len_str, p->len_arg);
		p->len_str += p->len_arg;
		while (*p->f != '%' && *p->f != '\0')
			p->f++;
		if (*p->f == '%' && *(p->f + 1) != '\0')
		{
			p->f++;
			p = initialize_struct(p);
			tmp = analyse(args, p);
			str = ft_memjoin(str, tmp, p->len_str, p->len_arg);
			p->len_str += p->len_arg;
		}
		else if (*p->f == '%' && *(p->f + 1) == '\0')
			break ;
	}
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
	t_printf	*p;
	int			len;

	len = 0;
	if (!(p = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	p->f = ((char *)format);
	p->flags = NULL;
	p->len_str = 0;
	va_start(args, format);
	str = ft_strnew(0);
	str = to_print(str, &args, p);
	write(1, str, p->len_str);
	ft_strdel(&str);
	va_end(args);
	len = p->len_str;
	free_struc(p);
	return (len);
}
