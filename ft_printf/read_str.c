/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:15:57 by rroland           #+#    #+#             */
/*   Updated: 2020/12/24 18:51:55 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	read_str(t_pf *pf)
{
	int k;

	k = 0;
	while (pf->str[g_i] != '\0')
	{
		if (pf->str[g_i] == '%')
		{
			write(1, &pf->str[k], g_i - k);
			g_print += g_i - k ;
			g_i++;
			while (find_flags(pf) == 0)
				g_i++;
			if (find_flags(pf) == 1)
				find_type(pf);
			vanish(pf);
			k = g_i + 1;
		}
		g_i++;
		if (pf->str[g_i] == '\0')
		{
			write(1, &pf->str[k], g_i - k);
			g_print += g_i - k ;
		}
	}
}