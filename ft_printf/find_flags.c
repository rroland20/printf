/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:44:38 by rroland           #+#    #+#             */
/*   Updated: 2020/12/24 19:38:48 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	transit(int len)
{
	while (len != 0)
	{	
		len = len / 10;
		g_i++;
	}
	g_i--;
}

int		find_flags(t_pf *pf)
{
	int valid;
	int len;

	valid = -1;
	if (pf->str[g_i] == 's' || pf->str[g_i] == 'c' || pf->str[g_i] == 'd'
		|| pf->str[g_i] == 'p' || pf->str[g_i] == 'i' || pf->str[g_i] == 'u'
	|| pf->str[g_i] == 'x' || pf->str[g_i] == 'X' || pf->str[g_i] == '%')
		valid = 1;
	else if (pf->str[g_i] == '-')
	{
			g_i++;
			pf->minus = ft_atoi(&pf->str[g_i]);
			len = pf->minus;
			transit(len);
			valid = 0;
	}
	else if (pf->str[g_i] == '.')
	{
		g_i++;
		if (pf->str[g_i] == '*')
		{
			pf->dot = va_arg(pf->ap, int);
			valid = 0;
		}
		else
		{
			pf->dot = ft_atoi(&pf->str[g_i]);
			len = pf->dot;
			transit(len);
			valid = 0;
		}
	}
	else if (pf->str[g_i] == '0')
	{
		g_i++;
		if(pf->str[g_i] == '*')
		{
			pf->nul = va_arg(pf->ap, int);
			valid = 0;
		}
		else 
		{
			pf->nul = ft_atoi(&pf->str[g_i]);
			len = pf->nul;
			transit(len);
			valid = 0;
		}
	}
	else if (pf->str[g_i] == '*')
	{
		pf->num = va_arg(pf->ap, int);
		valid = 0;
	}
	else if (pf->str[g_i] >= '1' && pf->str[g_i] <= '9')
	{
		pf->num = ft_atoi(&pf->str[g_i]);
		len = pf->num;
		transit(len);
		valid = 0;
	}
	return (valid);
}