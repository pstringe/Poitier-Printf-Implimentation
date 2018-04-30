/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:41:06 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/30 13:19:21 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_funcs(int (*con[NO_OF_TYPES])(t_m*, char buf[MAX]))
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

void	init_lens(char *lens[NO_OF_LENS])
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