/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/21 10:38:32 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	init_funcs(int	(*con[NO_OF_FLAGS])(char*, int, va_list))
{
	con[0] = &str;
	//con[1] = &wid;
	//con[2] = &poi;
	//con[3] = &dig;
	//con[4] = &dig;
	//con[5] = &dig;
	//con[6] = &oct;
	//con[7] = &oct;
	//con[8] = &usi;
	//con[9] = &usi;
	//con[10] = &hex;
	//con[11] = &hex;
	//con[12] = &uch;
	//con[13] = &uni;
	//con[14] = &not;
}	

void	init_mods(char	*mods[NO_OF_MODS])
{
	mods[0] = "hh";
	mods[1] = "h";
	mods[2] = "l";
	mods[3] = "ll";
	mods[4] = "j";
	mods[5] = "z";
}

int		is_flag(const char *f)
{
	char	*flags;
	char	*mods[NO_OF_MODS];
	int		i;

	flags = FLAGS;
	i = -1;
	while (++i < NO_OF_FLAGS)
		if(*f == flags[i])
			return (i + 1);
	i = -1;
	while (++i < NO_OF_MODS)
		if(!ft_strncmp(mods[i], f, ft_strlen(mods[i])))
			return (-1 * (i + 1));
	return (0);
}

int		convert(char *buf, int code, va_list args)
{
	int				bytes;
	static int		mod;
	static int		(*con[NO_OF_FLAGS + 1])(char*, int, va_list);
	
	bytes = 0;
	if (!*con)
		init_funcs(con);
	if (!code)
		return(0);
	else if (code < 0)
		mod = (code + 1) * -1;
	else if (code > 0)
	{
		bytes = con[code - 1](buf, mod, args);
		mod = 0;
	}
	return (bytes);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	char 			*buf;
	unsigned int	bytes;
	int				i;

	va_start(ap, format);
	bytes = 0;
	i = -1;
	buf = ft_strnew(MAX);
	while (format[++i] && bytes < MAX)
	{
		buf[bytes] = format[i];
		if (buf[bytes] == '%')
			bytes += convert((buf + bytes), is_flag((format + i + 1)), ap);
		else
			bytes++;
	}
	va_end(ap);
	buf[bytes] = '\0';
	write(1, buf, bytes);
	return (0);
}
