/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/23 10:50:07 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	init_funcs(int	(*con[NO_OF_FLAGS])(char*, int, va_list))
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
**	this function initializes an array of strings representing modifiers, get()
**	compares strlen(mod[x]) bytes between mod[x] && stuff->format[pos] and returns 
**	-1 * (x + 1) for a true comparsion (I've researved negative numbers for modifiers
**	and 0 for error;
*/

void	init_mods(char	*mods[NO_OF_MODS])
{
	mods[0] = "hh";
	mods[1] = "h";
	mods[2] = "l";
	mods[3] = "ll";
	mods[4] = "j";
	mods[5] = "z";
}

/*
**	this function returns a unique code for every flag and modifier that is used to 
**	that convert() will use to access the propper index in an array of function 
**	pointers to handel the conversion. 
*/

int		is(t_stuff *stuff)
{
	char	*flags;
	char	*mods[NO_OF_MODS];
	int		i;

	init_mods(mods);
	flags = FLAGS;
	i = -1;
	while (++i < NO_OF_FLAGS)
	{
		if(stuff->format[pos] == flags[i])
		{
			pos++;
			return (i + 1);
		}
	}
	i = -1;
	while (++i < NO_OF_MODS)
	{
		if(!ft_strncmp(mods[i], stuff->format[pos], ft_strlen(mods[i])))
		{
			pos += ft_strlen(mods[i]);
			return (-1 * (i + 1));
		}
	}
	return (0);
}

/*
**	this function initializes the stuff I need in order to copy, get, and convert 
**	stuff
*/

void	init(t_stuff *stuff, char *format)
{
	stuff->bytes = 0;
	stuff->pos = 0;
	stuff->format = format;
	stuff->buf = ft_strnew(MAX);
}

/*
**	this function calls the appropriate function to handel a conversion, given the 
**	modifiers form get();
*/

int		convert(t_stuff *stuff)
{
	static int		mod;
	static int		(*con[NO_OF_FLAGS + 1])(char*, int, va_list);
	
	bytes = 0;
	if (!*con)
		init_funcs(con);
	if (!stuff->flag)
		return(0);
	else
		bytes = con[code - 1](stuff->buf, stuff->mods, stuff->args);
	mod = 0;
	stuff->bytes += bytes;
}

/*
**	once a percent sign is encoutered, in cpy(), this function grabs and stores codes
**	for the modifiers and flags that follow.
*/

int		get(t_stuff *stuff)
{
	int		f;
	int		i;

	mod = (int*)ft_memalloc(sizeof(int) * 4);
	ft_bzero(mod);
	i = -1;
	f = 0;
	while ((f = is(stuff)) < 0)
		mod[++i] = f;
	if (!f)
		ft_memdel((void**)&mod);
	stuff->mod = mod;
	if ((f = is(stuff)) > 0)
		stuff->flag = f;
	else
		stuff->flag = 0;
	return ((f) ? 1 : 0);
}

/*
**	this function copies the format string to the buffer byte by byte until it 
**	either terminates, a '%' is encountered, or there is no more space in the buffer. 
*/

int		cpy(t_stuff *stuff)
{
	format = stuff->format;
	i = stuff->pos;
	j = stuff->bytes;
	while (format[i] && format[i] != '%' && j < MAX)
		stuff->buf[j++] = format[i++];
	stuff->pos = i;
	stuff->bytes = j;
	return ((format[i] == '%') 1 : 0);
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
	t_stuff		*stuff;

	stuff = (t_stuff*)ft_memalloc(sizeof(t_stuff));
	va_start(stuff->ap, format);
	init(stuff, format);
	while (cpy(stuff))
		if (get(stuff))
			convert(stuff);
	put(stuff);
	dstry(stuff)
	return (0);
}
