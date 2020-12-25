/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:57:48 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 17:50:31 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_pf
{
	char		*str;
	int			minus;
	int			dot;
	int			nul;
	int			num;
	va_list		ap;
}				t_pf;

int				g_print;
int				g_i;

void			ft_putnbr(long long nbr, int num, char ch);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int n);
int				ft_atoi(const char *str);
void			vanish(t_pf *pf);
int				ft_len(int len, int num);
void			type_s(t_pf *pf);
void			type_di(t_pf *pf);
void			type_c(t_pf *pf);
void			type_p(t_pf *pf);
void			type_u(t_pf *pf);
void			type_x(t_pf *pf);
void			type_X(t_pf *pf);
void			type_per(t_pf *pf);
void			read_str(t_pf *pf);
int				find_flags(t_pf *pf);
void			find_type(t_pf *pf);
void	treatment(t_pf *pf, int sys, int k, unsigned int t_value);

#endif