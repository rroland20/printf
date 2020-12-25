/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 13:29:32 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 14:55:33 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	type_di(t_pf *pf)
{
	int t_di;
	int len;
	int len1;
	
	t_di = va_arg(pf->ap, int);
	len = ft_len(t_di, 10);
	if (pf->dot == 0 && t_di == 0)
		len--;
	if (pf->dot > len && t_di < 0)
		len1 = pf->dot + 1;
	else if(pf->dot > len)
		len1 = pf->dot;
	else
		len1 = len;
	if (t_di < 0 && pf->dot == -1 && pf->nul != -1)
		ft_putchar('-');
	while (pf->nul > len1)
	{
		if (pf->dot > -1)
			ft_putchar(' ');
		else
			ft_putchar('0');
		pf->nul--;
	}
	while (pf->num > len1)
	{
		ft_putchar(' ');
		pf->num--;
	}
	if (pf->dot > -1 && t_di < 0)
		len--;
	if (t_di < 0 && (pf->nul == -1 || pf->dot != -1))
		ft_putchar('-');
	while (pf->dot > len)
	{
		ft_putchar('0');
		pf->dot--;
	}
	if (!(pf->dot == 0 && t_di == 0))
		ft_putnbr(t_di, 10, 32);
	while (pf->minus > len1)
	{
		ft_putchar(' ');
		pf->minus--;
	}
}