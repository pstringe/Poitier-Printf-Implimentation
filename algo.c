/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:02:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/24 08:01:58 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	transform(t_param, va_list list)
{
	static t_handle (handle[12]) = 
	{
		{.conv = 's', .handle = str},
		{.conv = 'S', .handle = str},
		{.conv = 'c', .handle = str},
		{.conv = 'C', .handle = str},
		{.conv = '%', .handle = none},
		{.conv = 'd', .handle = num},
		{.conv = 'o', .handle = num},
		{.conv = 'O', .handle = num},
		{.conv = 'u', .handle = num},
		{.conv = 'U', .handle = num},
		{.conv = 'x', .handle = num},
		{.conv = 'X', .handle = num},
		{.conv = 'c', .handle = chr},
		{.conv = 'C', .handle = chr}
	};
	int		i;

	if (p.err)
		return (0);
	i =-1;
	while (++i < 12)
		if (p.conv == h[i].conv)
			return (hp[i].handle(p, list));
	return (0);
}
/*
** get a parameter from the format string	
*/

t_param		get_param(const char s)
{
	static int	(*h[6])(t_param *, const char *, size_t *) = 
	{
		access, flags, width, precision, mods, conversion 
	}
	t_param p;
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	p = init_param(str, len);
	while (i < 6)
	{
		if ((*h[i])(&p, s + 1, &pos))
		{
			p.error = 1;
			break ;
		}
		i++;
	}
	if (p.conv == 'i')
		p.conv = 'd';
	if (p.c == 'p')
		p.mod = LL;
	return (big_conv(p));
}

/*
**	runs the given conversion given the placeholder data
*/

int		convert(t_m *m, char buf[MAX])
{
	static int	(*con[NO_OF_TYPES])(t_m*, char buf[MAX]);
	char		*types;

	types = TYPES;
	if (!*con)
		init_funcs(con);
	m->pos_b += con[m->place->type](m, buf);
	m->pos_f += m->format[m->pos_f] == types[m->place->type] ? 1 : 0;
	ft_memdel((void**)&m->place);
	return (1);
}

/*
**	once a percent sign is encoutered, in cpy(), this function grabs
**	and stores codes for the modifiers and flags that follow.
*/

int		get_placeholder(t_m *m)
{
	t_p *place;

	place = ft_memalloc(sizeof(t_p));
	m->place = place;
	get_flags(m);
	get_width(m);
	get_precision(m);
	get_len(m);
	get_type(m);
	return (1);
}

/*
**	this function copies the format string to the buffer byte by byte until it
**	either terminates, a '%' is encountered, or there is no more space.
*/

int		cpy(t_m *m, char buf[MAX])
{
	unsigned int	i;
	unsigned int	j;
	const char		*format;

	format = m->format;
	i = m->pos_f;
	j = m->pos_b;
	while (format[i] && format[i] != '%' && j < MAX)
	{
		buf[j] = format[i];
		i++;
		j++;
	}
	m->pos_f = i;
	m->pos_b = j;
	return ((format[i] == '%') ? 1 : 0);
}
