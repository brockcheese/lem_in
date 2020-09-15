/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_helper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:17:55 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:11 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		put_floating_e(t_printf *data, int *count, long long e,
													int negative)
{
	if (data->conversion == 'e')
	{
		ft_putchar('e');
		if ((negative))
			ft_putchar('-');
		else
			ft_putchar('+');
		*count += 2;
	}
	else if (data->conversion == 'E')
	{
		ft_putchar('E');
		if (negative)
			ft_putchar('-');
		else
			ft_putchar('+');
		*count += 2;
	}
	if (e < 10)
	{
		ft_putchar('0');
		*count += 1;
	}
	ft_putnbr(e);
	*count += ft_numlen(e);
}

static void		put_float_e(t_printf *data, long double number)
{
	long double		num;
	long long		whole;

	num = (number < 0) ? -number : number;
	whole = (unsigned long long)num;
	if (num - whole >= 0.5 && data->precision == 0)
		whole += 1;
	num -= whole;
	ft_putnbr(whole);
	if (data->precision <= 15)
		num += 0.000000000000001;
	if (data->precision > 0 || data->flag[4] == '#')
		ft_putchar('.');
	if (data->precision != 0)
		while (data->precision)
		{
			num *= 10;
			whole = (unsigned long long)num;
			num -= whole;
			whole %= 10;
			ft_putchar(whole + '0');
			data->precision--;
		}
}

void			put_num_e(t_printf *data, long double number, int *count)
{
	long double		num;
	int				e;
	int				negative;

	num = (number < 0) ? -number : number;
	negative = (num < 1.0) ? 1 : 0;
	e = 0;
	while (num < 1.0 && negative)
	{
		num *= 10;
		e++;
	}
	while (num > 10.0 && !negative)
	{
		num /= 10;
		e++;
	}
	put_float_e(data, num);
	put_floating_e(data, count, e, negative);
}
