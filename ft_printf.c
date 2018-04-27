/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/26 17:03:23 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	init_funcs(int	(*con[NO_OF_TYPES])(t_m*, char buf[MAX]))
{
	con[0] = &str;
	con[1] = &str;
	con[2] = &poi;
	con[3] = &dig;
	con[4] = &dig;
	con[5] = &dig;
	con[6] = &oct;
	con[7] = &oct;
	con[8] = &usi;
	con[9] = &usi;
	con[10] = &hex;
	con[11] = &hex;
	con[12] = &uch;
	con[13] = &uni;
	con[14] = &not;
}	

void	init_lens(char	*lens[NO_OF_LENS])
{
	lens[0] = "hh";
	lens[1] = "h";
	lens[2] = "l";
	lens[3] = "ll";
	lens[4] = "j";
	lens[5] = "z";
}

void	init(t_m *m, const char *format, char buf[MAX])
{
	m->pos_b = 0;
	m->pos_f = 0;
	m->format = format;
	ft_bzero(buf, MAX);
	m->place = NULL;
}

int		convert(t_m *m, char buf[MAX])
{
	static int	(*con[NO_OF_TYPES])(t_m*, char buf[MAX]);
	
	if (!*con)
		init_funcs(con);
	m->pos_b += con[m->place->type](m, buf);
	ft_memdel((void**)&m->place);
	return (1);
}

int		is_flag(char c)
{
	int		i;
	char 	*flags;

	flags = FLAGS;
	i = -1;
	while (flags[++i])
		if (c == flags[i])
			return (i + 1);
	return (0);
}

int		get_flags(t_m *m)
{
	int	f;
	int	i;

	i = -1;
	while ((f = is_flag(m->format[m->pos_f])))
	{
		m->place->flags[++i] = f - 1;
		m->pos_f++;
	}
	return (1);
}

int		get_width(t_m *m)
{
	int 	w;
	int 	l;
	int		a;

	w = 0;
	if ((a = (m->format[m->pos_f] == '*')))
		m->place->width = (w = va_arg(m->ap, int));
	else if (m->format[m->pos_f] >= '0' && m->format[m->pos_f] <= '9')
		m->place->width = (w = ft_atoi(m->format + m->pos_f));
	else
		return (0);
	l = 1;
	while (w /= 10 && !a)
		l++;
	m->pos_f += l;
	return (l); 
}

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
	m->pos_f += l;
	return (l);
}

int		get_type(t_m *m)
{
	char *types;
	int	i;

	types = TYPES;
	i = -1;
	while (types[++i])
	if (m->format[m->pos_f] == types[i])
		m->place->type = i;
	m->pos_f++;
	return (i);
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

/*
**	prints the result
*/

void	put(t_m *m, char buf[MAX])
{
	write(1, buf, m->pos_b + 1);
}

/*
**	cleanup
*/

void	dstry(t_m *m)
{
	if (m->place)
		ft_memdel((void**)&m->place);
	va_end(m->ap);
	ft_memdel((void**)&m);
} 

/*
**	this is the main function that initializes the arguments, copies the format string
**	to a buffer until it encounters a '%'. Upon encountering a '%' will get the 
**	modifiers and format flags. It will then pass this information to the convert
**	function which will call the appropriate function to edit the buffer, Once the
**	all conversions have been carried out, or there is no more space in the buffer,
**	the buffer is printed to standard output and destroyed thereafter.
*/

int		ft_printf(const char *format, ...)
{
	t_m		*m;
	char	buf[MAX];

	m = (t_m*)ft_memalloc(sizeof(t_m));
	va_start(m->ap, format);
	init(m, format, buf);
	while (cpy(m, buf))
		if (get_placeholder(m))
			convert(m, buf);
	put(m, buf);
	dstry(m);
	return (0);
}
