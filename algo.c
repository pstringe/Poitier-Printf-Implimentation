/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:02:57 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/27 19:17:00 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	runs the given conversion given the placeholder data
*/

int		convert(t_m *m, char buf[MAX])
{
	static int	(*con[NO_OF_TYPES])(t_m*, char buf[MAX]);
	
	if (!*con)
		init_funcs(con);
	m->pos_b += con[m->place->type](m, buf);
	ft_memdel((void**)&m->place);
	return (1);
}

/*
**	once a percent sign is encoutered, in cpy(), this function grabs and stores codes
**	for the modifiers and flags that follow.
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
**	either terminates, a '%' is encountered, or there is no more space in the buffer. 
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
