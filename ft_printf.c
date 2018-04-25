/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/25 08:22:45 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	init_funcs(int	(*con[NO_TYPES])(t_stuff*))
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

/*
**	this function initializes the stuff I need in order to copy, get, and convert 
**	stuff
*/

void	init(t_stuff *stuff, const char *format)
{
	stuff->bytes = 0;
	stuff->pos = 0;
	stuff->format = format;
	stuff->buf = ft_strnew(MAX);
}


/*
**	this function initializes an array of strings representing modifiers, get()
**	compares strlen(mod[x]) bytes between mod[x] && stuff->format[pos] and returns 
**	-1 * (x + 1) for a true comparsion (I've researved negative numbers for modifiers
**	and 0 for error;
*/

void	init_lens(char	*mods[NO_OF_LENS])
{
	mods[0] = "hh";
	mods[1] = "h";
	mods[2] = "l";
	mods[3] = "ll";
	mods[4] = "j";
	mods[5] = "z";
}

/*
**	retrieves the precision when is stuff encounters a '.'. If the next, charachter in
**	the format string is a '*', the next argument is fetched and used as the precision.
**	Otherwise, the following characters are parsed as a number and the position in the 
**	format string is incremented.
*/

int		get_p(t_stuff *stuff, int i)
{
	int x;

	x = ft_atoi((stuff->format + stuff->pos + 1));
	stuff->p = x;
	if (x)
		while (x /= 10)
			stuff->pos++;
	else if (stuff->format[stuff->pos + 1] == '*')
		stuff->p = va_arg(stuff->ap, int);
	return (-1 * (i + 1));
}

/*
**	this function calls the appropriate function to handel a conversion, given the 
**	modifiers form get();
*/

int		convert(t_stuff *stuff)
{
	static int	(*con[NO_OF_FLAGS + 1])(t_stuff *stuff);
	
	if (!*con)
		init_funcs(con);
	if (!stuff->flag)
		return(0);
	else
		stuff->bytes += con[stuff->flag - 1](stuff);
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
	while ((f = is_flag(m->format[m->pos_f++])))
		m->place->flag[++i] = f - 1;
	return (1);
}

int		get_width(t_m *m)
{
	int w;
	int l;

	w = 0;
	if (m->format[m->pos_f] >= '0' && m->format[m->posf] <= '9')
		m->place->width = (w = ft_atoi(m->format + m->posf));
	l = 1;
	while (w /= 10)
		l++;
	m->pos_f += l;
	return (l); 
}

int		get_precision(t_m *m)
{
	int	p;
	int	l;

	w = 0;
	if (m->format[m->pos_f] == '.')
		m->place->precision = (m->format[++m->pos_f] == '*') ? va_arg(m->ap, int) : (p = ft_atoi(m->format[m->pos_f]));
	l = 1;
	while (w /= 10)
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
		if (!strncmp(m->format[m->pos_f], lens[i], (l = ft_strlen(lens[i]))))
			m->place->len = lens[i];
	m->pos_f += l;
	return (l)
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

int		cpy(t_m *m)
{
	int			i;
	int			j;
	const char	*format;

	format = m->format;
	i = m->pos_f;
	j = m->pos_b;
	while (format[i] && format[i] != '%' && j < MAX)
		stuff->buf[j++] = format[i++];
	m->pos_f = i;
	m->pos_b = j;
	return ((format[i] == '%') ? 1 : 0);
}

/*
**	prints the result
*/

void	put(t_stuff *stuff)
{
	write(1, stuff->buf, stuff->bytes + 1);
}

/*
**	cleanup
*/

void	dstry(t_stuff *stuff)
{
	ft_memdel((void**)&stuff->buf);
	ft_memdel((void**)&stuff->mods);
	va_end(stuff->ap);
	ft_memdel((void**)&stuff);
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

	m = (t_m*)ft_memalloc(sizeof(t_m));
	va_start(m->ap, format);
	init(m, format);
	while (cpy(m))
		if (get_placeholder(m))
			convert(m);
	put(m);
	dstry(m);
	return (0);
}
