/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uxX%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:07:03 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 18:00:14 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	treatment(t_pf *pf, int sys, int k, unsigned int t_value)
{
	int len;
	int len1;

	len = ft_len(t_value, sys);
	if (pf->dot == 0 && t_value == 0) 
		len--;
	if (pf->dot > len )
		len1 = pf->dot;
	else
		len1 = len;
	while (pf->nul > len1 && pf->nul--)
		if (pf->dot > -1)
			ft_putchar(' ');
		else
			ft_putchar('0');
	while (pf->num > len1 && pf->num--)
		ft_putchar(' ');
	while (pf->dot > len && pf->dot--)
		ft_putchar('0');
	if (!(pf->dot == 0 && t_value == 0))
		ft_putnbr(t_value, sys, k);
	while (pf->minus > len1 && pf->minus--)
		ft_putchar(' ');
}

void	type_u(t_pf *pf)
{
	unsigned int t_u;

	t_u = va_arg(pf->ap, unsigned int);
	treatment(pf, 10, 0, t_u);

}

void	type_x(t_pf *pf)
{
	unsigned int t_x;
	
	t_x = va_arg(pf->ap, unsigned int);
	treatment(pf, 16, 0, t_x);
}

void	type_X(t_pf *pf)
{
	unsigned int t_X;

	t_X = va_arg(pf->ap, unsigned int);
	treatment(pf, 16, 32, t_X);
}

void	type_per(t_pf *pf)
{
	ft_putchar(pf->str[g_i]);
}