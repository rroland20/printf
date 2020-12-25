/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sdicp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:40:20 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 13:30:17 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len(int len, int num)
{
	int i;

	i = 0;
	if (len < 0)
		i++;
	if (len == 0)
		i++;
	while (len != 0)
	{	
		len = len / num;
		i++;
	}
	return(i);
}
void	type_s(t_pf *pf)
{
	char *t_str;
	
	t_str = va_arg(pf->ap, char *);
	ft_putstr(t_str);
}

void	type_c(t_pf *pf)
{
	char t_c;
	
	t_c = va_arg(pf->ap, int);
	ft_putchar(t_c);
}

void	type_p(t_pf *pf)
{
	unsigned long long int t_p;

	t_p = va_arg(pf->ap, unsigned long long int);
	ft_putstr("0x");
	ft_putnbr(t_p, 16, 0);
}
