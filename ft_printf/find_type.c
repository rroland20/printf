/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 18:18:36 by rroland           #+#    #+#             */
/*   Updated: 2020/12/24 18:22:37 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void find_type(t_pf *pf)
{
	if (pf->str[g_i] == 's')
		type_s(pf);
	else if (pf->str[g_i] == 'd' || pf->str[g_i] == 'i')
		type_di(pf);
	else if (pf->str[g_i] == 'c')
		type_c(pf);
	else if (pf->str[g_i] == 'p')
		type_p(pf);
	else if (pf->str[g_i] == 'u')
		type_u(pf);
	else if (pf->str[g_i] == 'x')
		type_x(pf);
	else if (pf->str[g_i] == 'X')
		type_X(pf);
	else if (pf->str[g_i] == '%')
		type_per(pf);
}