/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroland <rroland@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 12:57:14 by rroland           #+#    #+#             */
/*   Updated: 2020/12/25 14:09:48 by rroland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
	g_print++;
}

void		ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

void		ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && n != 0)
		{
			ft_putchar(s[i]);
			i++;
			n--;
		}
	}
}

void		ft_putnbr(long long nb, int num, char ch)
{
	unsigned long long nbr;

	if (nb < 0)
		nbr = nb * -1;
	else
	nbr = nb;
	if (nbr >= (unsigned long long)num)
		ft_putnbr(nbr / num, num, ch);
	if (num == 16)
	{
		if (nbr % 16 == 10)
			ft_putchar('a' - ch);
		else if (nbr % 16 == 11)
			ft_putchar('b' - ch);
		else if (nbr % 16 == 12)
			ft_putchar('c' - ch);
		else if (nbr % 16 == 13)
			ft_putchar('d' - ch);
		else if (nbr % 16 == 14)
			ft_putchar('e' - ch);
		else if (nbr % 16 == 15)
			ft_putchar('f' - ch);
		else
		ft_putchar(nbr % num + '0');
	}
	else
		ft_putchar(nbr % num + '0');
}

int		ft_atoi(const char *str)
{
	int result;
	char *ss;
	int i;
	int k;

	result = 0;
	ss = (char *)str;
	k = 1;
	i = 0;
	while (ss[i] >= '0' && ss[i] <= '9')
	{
		result = result * 10 + (ss[i] - '0');
		i++;
	}
	return (result * k);
}
