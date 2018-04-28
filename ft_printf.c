/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/27 19:24:10 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
