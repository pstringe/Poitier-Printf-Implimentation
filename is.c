/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:44:24 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/24 08:23:51 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		is_conv(const char c)
{
	char conv = "dDioOuUxXeEfFgGaAcCsSpn%";

	while (*conv)
	{
		if (*conv == (char)c)
			return (1);
		conv++;
	}
	if ((char)c == '0')
		return (1);
	return (0);
}

int		is_valid(const char c)
{
	return (is_conv(c) || is_mod(c) || is_flag(c) || is_digit(c) || is_prcs(c));
}
