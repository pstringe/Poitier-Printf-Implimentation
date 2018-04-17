/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/16 18:40:50 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	flags[15] = "hh";
	flags[16] = "h";
	flags[17] = "l";
	flags[18] = "ll";
	flags[19] = "j";
	flags[20] = "z";
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
