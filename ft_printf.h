/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:31:04 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/24 19:18:55 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define MAX 0xffffffff
# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "-+ 0#"
# define NO_OF_TYPES 14
# define NO_OF_LENS 6

typedef struct	s_p
{
	int		flags[4];
	int		width;
	int		precision;
	int		len;
	int		type;
}				t_p;

typedef	struct	s_m
{
	const char	*format;
	char		*buf;
	int			pos_f;
	int			pos_b;
	va_list		ap;
	struct s_p	place;
}				t_m;

int		ft_printf(const char *str, ...);

int		str(t_m *m);
int		poi(t_m *m);
int		dig(t_m *m);
int		oct(t_m *m);
int		usi(t_m *m);
int		hex(t_m *m);
int		uch(t_m *m);
int		uni(t_m *m);
int		not(t_m *m);
#endif
