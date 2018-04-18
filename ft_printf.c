/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/18 15:16:49 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	init_funcs(void	(*con)(char*, void*, int*)[NO_OF_FLAGS])
{
	con[0] = &str;
	con[1] = &wid;
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

void	init_flags(char *flags[NO_OF_FLAGS])
{
	flags[0] = "s";
	flags[1] = "S";
	flags[2] = "p";
	flags[3] = "d";
	flags[4] = "D";
	flags[5] = "i";
	flags[6] = "o";
	flags[7] = "O";
	flags[8] = "u";
	flags[9] = "U";
	flags[10] = "x";
	flags[11] = "X";
	flags[12] = "c";
	flags[13] = "C";
	flags[14] = "%";
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

int		is_flag(char *f)
{
	char	*flags[NO_OF_FLAGS];
	char	*mods[NO_OF_MODS];
	int		i;

	init_flags(flags);
	i = -1;
	while (++i < NO_OF_FLAGS)
	{
		if(!ft_strnmp(flags[i], f, ft_strlen(flags[i])))
			return (i + 1);
	}
	i = -1;
	while (++i < NO_OF_MODS)
	{
		if(!ft_strcmp(mods[i], f, ft_strlen(mods[i])))
			return (-1 * (i + 1));
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	char 	buf[MAX];
	char	*flags[NO_OF_FLAGS];
	valist	args;
	int		bytes;

	init_flags(flags);
	flag = 0;
	va_start(args, str);
	bytes = 0;
	while (str && ++bytes < MAX)
	{
		if (buf[pos] == '%')
			convert(str, is_flag((str + 1)), &buf, &bytes);
		str++;
	}
	buf[bytes] = '\0';
	write(1, &buf, bytes)
	return (0);
}
