/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstringe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:31:04 by pstringe          #+#    #+#             */
/*   Updated: 2018/06/02 19:39:41 by pstringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <assert.h>
# define MAX 4096
# define TYPES "sSpdDioOuUxXcC%"
# define FLAGS "-+ 0#"
# define NO_OF_TYPES 14
# define NO_OF_LENS 6

/*
**	define flags
*/

# define MINUS	1
# define PLUS	(1 << 1)
# define SPACE	(1 << 2)
# define ZERO	(1 << 3)
# define HASH	(1 << 4)

/*
**	define structs
*/

typedef struct 	s_num
{
	int		base;
	int		sign;
	int 	idx;
	char	b_conv[100];
	int 	neg;
	int		arg;
}				t_num;

typedef struct	s_p
{
	int				start;
	unsigned char	flags;
	int				width;
	int				precision;
	int				len;
	int				type;
}				t_p;

typedef	struct	s_m
{
	const char	*format;
	int			pos_f;
	int			pos_b;
	va_list		ap;
	struct s_p	*place;
}				t_m;

/*
**	main function
*/

int				ft_printf(const char *str, ...);

/*
**	functions essential for the main operation of printf
*/

int				cpy(t_m *m, char buf[MAX]);
int				get_placeholder(t_m *m);
int				convert(t_m *m, char buf[MAX]);

/*
**	initialization functions
*/

void			init_funcs(int	(*con[NO_OF_TYPES])(t_m*, char buf[MAX]));
void			init_lens(char	*lens[NO_OF_LENS]);
void			init(t_m *m, const char *format, char buf[MAX]);

/*
**	placeholder parsing functions
*/

int				get_width(t_m *m);
int				get_flags(t_m *m);
int				get_precision(t_m *m);
int				get_len(t_m *m);
int				get_type(t_m *m);

/*
**	conversion functions
*/

int				str(t_m *m, char buf[MAX]);
int				poi(t_m *m, char buf[MAX]);
int				dig(t_m *m, char buf[MAX]);
int				oct(t_m *m, char buf[MAX]);
int				usi(t_m *m, char buf[MAX]);
int				hex(t_m *m, char buf[MAX]);
int				uch(t_m *m, char buf[MAX]);
int				uni(t_m *m, char buf[MAX]);
int				not(t_m *m, char buf[MAX]);

/*
**	misc functions for checking, output, cleanup ect ...
*/

void			ft_spn(intmax_t nb, t_num *n, t_m *m);
void			ft_upn(uintmax_t nb, t_num *n, t_m *m);
int				is_flag(char c);
void			put(t_m *m, char buf[MAX]);
void			dstry(t_m *m);

#endif
