/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:05:08 by pstringe          #+#    #+#             */
/*   Updated: 2018/05/12 10:48:24 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef	void	(*o_f_t)(char c, char *b, size_t i, size_t max);

typedef	struct	s_p
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	n;
	size_t			index;
}				t_p;

typedef struct	s_m
{
	char		*buf,
	const char	*format;
	va_list		*va;
	struct s_p	placeholder;
}				t_m;

int				ft_vprintf(void out_fct_type out, char *buf, const char* format, va_list va)
{
	t_m	*m;

	if (!buf)
		out = out_null;
	while (*format)
		if (*format != '%')
			if (get_placeholder())
				evaluate_specifier();
	out_buffer();
}

int				ft_printf(const char *format, ...)
{
	va_list		va;
	int			ret;

	va_start(va, format);
	ret = ft_vprintf(ft_putchar, NULL, (size_t) - 1, format, va); 
	va_end(va);
	return (ret);
}
