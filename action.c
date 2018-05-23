/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:47:42 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/22 15:55:49 by pstringe         ###   ########.fr       */
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

}
