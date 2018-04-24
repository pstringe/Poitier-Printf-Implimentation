/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:31:04 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/24 14:33:32 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

# define MAX 4096
# define FLAGS "sSpdDioOuUxXcC%"
# define NO_OF_FLAGS 15
# define NO_OF_MODS 6

typedef	struct	s_tuff
{
	const char	*format;
	char		*buf;
	int			*mods;
	int			bytes;
	int			pos;
	int			flag;
	va_list		ap;
}				t_stuff;

int		ft_printf(const char *str, ...);

int		str(t_stuff *stuff);
int		poi(t_stuff *stuff);
int		dig(t_stuff *stuff);
int		oct(t_stuff *stuff);
int		usi(t_stuff *stuff);
int		hex(t_stuff *stuff);
int		uch(t_stuff *stuff);
int		uni(t_stuff *stuff);
int		not(t_stuff *stuff);
#endif
