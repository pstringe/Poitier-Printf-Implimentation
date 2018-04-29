/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:45:41 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/28 17:26:48 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	checks for width parameter in placeholder or wildcard, and stores
*/

int		get_width(t_m *m)
{
	int 	w;
	int 	l;
	int		a;

	w = 0;
	if ((a = (m->format[m->pos_f + 1 ] == '*')))
		m->place->width = (w = va_arg(m->ap, int));
	else if (m->format[m->pos_f + 1] >= '0' && m->format[m->pos_f + 1] <= '9')
	{
		w = ft_atoi(m->format + m->pos_f + 1);
		m->place->width = w;
	}
	else
		return (0);
	l = 1;
	while ((w /= 10) && !a)
		l++;
	m->pos_f += l;
	return (l); 
}

/*
**	checks for flag and stores
*/

int		get_flags(t_m *m)
{
	int	f;
	int	i;
	int a;

	a = m->format[m->pos_f] == '%' ? 1 : 0;
	i = -1;
	while ((f = is_flag(m->format[m->pos_f + a])))
	{
		m->place->flags[++i] = f - 1;
		m->pos_f++;
	}
	return (1);
}

/*
**	checks for precision parameter or wildcard and stores
*/

int		get_precision(t_m *m)
{
	int	p;
	int	l;

	p = 0;
	if (m->format[m->pos_f + 1] == '.')
		if (m->format[++m->pos_f + 1] == '*')
		{
			m->place->precision = va_arg(m->ap, int);
			m->pos_f++;
		}
		else if (m->format[m->pos_f + 1] >= '0' && m->format[m->pos_f + 1] <= '9')
		{
			p = ft_atoi(m->format + m->pos_f + 1);
			m->place->precision = p;
		}
		else
			return (-1);
	else
		return (0);
	l = 1;
	while (p /= 10)
		l++;
	m->pos_f += l;
	return (l);
}

/*
**	checks for length modifier and stores
*/

int		get_len(t_m *m)
{
	char	*lens[NO_OF_LENS];
	int		i;
	int		l;

	init_lens(lens);
	i = -1;
	while (++i < NO_OF_LENS)
		if (!strncmp(m->format + m->pos_f, lens[i], (l = ft_strlen(lens[i]))))
			m->place->len = i;
		else
			l = 0;
	m->pos_f += l;
	return (l);
}

/*
**	checks for type and stores
*/

int		get_type(t_m *m)
{
	char *types;
	int	i;

	types = TYPES;
	m->pos_f = m->format[m->pos_f] == '%' || m->format[m->pos_f] == '*' ? m->pos_f + 1 : m->pos_f;
	i = -1;
	while (types[++i])
		if (m->format[m->pos_f] == types[i])
			m->place->type = i;
	m->pos_f++;
	return (i);
}


