/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:47:42 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/23 15:28:52 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert(t_param *p, const char *str, size_t *i)
{
	if (is_conv(str[*i]))
	{
		p->conv = str[*i];
		(*i)++;
		return (0);
	}
	return (1);
}

int		access(t_param *p, const char *str, size_t *i)
{
	int	accs;
	int	t;

	t = *i;
	if (!ft_isdigig(str[*i]))
		return (0);
	if (pf_atoi(str, 0, &accs, i) || str[*i] != 's')
	{
		*i = t;
		return (0);
	}
	(*i)++;
	param->accs = accs;
	return (0);
}

int		flgs(t_param *p, const char s, size_t *i)
{
	char c;
	while (*i < p->form.len)
	{
		if (is_flag(c))
		{
			if (c == '#')
				p->flgs |= HASH;
			else if (c == '0')
				p->flgs |= ZERO;
			else if (c == ' ')
				p->flgs |= SPACE;
			else if (c == '+')
				p->flgs |= PLUS;
			else if (c == '-')
				p->flgs |= MINUS;
		}
		else 
			return(0);
		(*i++);
	}
	return (1);
}

int		width(t_param *p, const char s, size_t *i)
{
	int w;
	int pos;
	if (pos = (str[*i] == '*'))
		(*i)++;
	if (get_num(str, 0, &w, i) && !pos)
		return (1);
	if (pos)
	{
		if (str[*i] == '$')
			(*i)++;
		else
			return (1);
		p->wdth_accs = w;
	}
	else
		p->wdth = w;
	return (0);
}

int		mods(t_param *p, const char s, size_t *i)
{
	t_mod m;

	n = NA;
	if (!is_mod(str[*i]))
		return (0);
	if (str[*i] = 'l')
		if (str[*i + 1] == 'l' && ++(*i))
			m = LL;
		else
			m = L;
	else if (str[*i] = 'h')
		if (str[*i + 1] == 'l' && ++(*i))
			m = HH;
		else
			m = H;
	else if (str[*i] == 'j')
		m = J;
	else if (str[*i] == 'z')
		m = Z;
	p->mods = m;
	return ((*i)++ & 0);
}

int		precision(t_param *p, const char s, size_t *i)
{
	int p;
	
	p->prcs = -1;
	if (str[*i] != '.')
		return (0);
	p->prcs = = 0;
	if (get_num(s, 0, &p, i))
		return (1);
	p->prcs = p;
	return (0);
}
