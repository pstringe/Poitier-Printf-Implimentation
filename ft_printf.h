/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:31:04 by pstringe          #+#    #+#             */
/*   Updated: 2018/04/23 10:51:30 by pstringe         ###   ########.fr       */
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
	char	*format;
	char	*buf;
	int		*mods;
	int		bytes;
	int		pos;
	int		flag;
	va_list	ap;
}				t_stuff;

int		ft_printf(const char *str, ...);

int		str(char *buf, int *mods, va_list args);
int		poi(char *buf, int *mods, va_list args);
int		dig(char *buf, int *mods, va_list args);
int		oct(char *buf, int *mods, va_list args);
int		usi(char *buf, int *mods, va_list args);
int		hex(char *buf, int *mods, va_list args);
int		uch(char *buf, int *mods, va_list args);
int		uni(char *buf, int *mods, va_list args);
int		not(char *buf, int *mods, va_list args);
#endif
