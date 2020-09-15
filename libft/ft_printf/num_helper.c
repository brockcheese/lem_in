/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:08:31 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:28 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void			ft_intmove(char *str, int len, unsigned long long number,
												int negative)
{
	len--;
	if (number == 0)
	{
		str[len] = '0';
		return ;
	}
	while (number > 0)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	if (negative == 1)
		str[len] = '-';
}

int				get_width(t_printf *data, char *result, char *to_print)
{
	int		len;

	*to_print = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	len = ft_strlen(result);
	return ((data->field_width > len) ? data->field_width - len : 0);
}

void			put_float(t_printf *data, long double number)
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
		num += 0.0000000000000001;
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
