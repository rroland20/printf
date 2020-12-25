/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:45:03 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 17:13:21 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	vanish(t_pf *pf)
{
	pf->dot = -1;
	pf->minus = -1;
	pf->nul = -1;
	pf->num = -1;
}

int		ft_printf(const char *str, ...)
{
	t_pf	*pf;

	g_i = 0;
	g_print = 0;
	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (0);
	vanish(pf);
	pf->str = (char *)str;
	va_start(pf->ap, str);
	read_str(pf);
	va_end(pf->ap);
	free(pf);
	return (g_print);
}

// int		main(void)
// {
// 	// char *str = "sd";
// 	printf("%d\n", printf("tak doljno bit - |%08.5d|\n", 34));
// 	printf("%d\n", ft_printf("ya dauniha     - |%08.d|\n", 34));
// 	return (0);
// }
