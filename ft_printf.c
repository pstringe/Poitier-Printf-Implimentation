/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/22 14:37:31 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_param 	get_param(const char *str, size_t l)
{
	t_param		p;
	t_form 		f;

	f.str = str;
	f.len = l;
	p.accs = 0;
	p.flgs = 0;
	p.wdth = 0;
	p.prcs = 0;
	p.mods = NA;
	p.conv = 0;
	p.erro = 0;
	return (p);
}

t_param		len_mod_convert(t_param p)
{
	if (p.conv == 'D' || p.conv == 'S' || p.conv == 'C' || p.conv == 'O'
			|| p.conv == 'U')
		p.mods = L;
	if (p.conv == 'D')
		p.conv = 'd';
	else if (p.conv == 'S')
		p.conv = 's';
	else if (p.conv == 'C')
		p.conv = 'c';
	else if (p.cov == 'O')
		p.conv = 'o';
	else if (p.conv == 'U')
		p.conv == 'u';
	return (t_param);
}

int		is_mod(const char c)
{
	char mods = "hljz";

	while (*mods)
	{
		if (*mods == (char)c)
			return (1);
		mods++;
	}
	if ((char)c == '0')
		return (1);
	return (0);
}

int		is_flag()
{
	char flags = "#0-+";

	while (*mods)
	{
		if (*flags == (char)c)
			return (1);
		flags++;
	}
	if ((char)c == '0')
		return (1);
	return (0);
} 

int		is_prcs(const char c)
{

	char prcs = "$*.";

	while (*prcs)
	{
		if (*prcs == (char)c)
			return (1);
		prcs++;
	}
	if ((char)c == '0')
		return (1);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		va;
	int			ret;

	va_start(va, format);
	ret = ft_vprintf(ft_putchar, NULL, (size_t) - 1, format, va); 
	va_end(va);
	return (ret);
}
