/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:03:03 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:15:01 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static long double	get_num(t_printf *data)
{
	long double		num;

	if (ft_strcmp(data->length, "L") == 0)
		num = va_arg(data->ap, long double);
	else
	{
		num = va_arg(data->ap, double);
		return ((double)num);
	}
	return (num);
}

static int			get_len(t_printf *data, long double num)
{
	int					len;
	unsigned long long	whole;

	len = 0;
	num = (num < 0) ? -num : num;
	whole = (unsigned long long)num;
	len += (data->precision > 0 || data->flag[4] == '#') ? 1 : 0;
	len += data->precision;
	len += 1;
	return (len);
}

static int			get_width_e(t_printf *data, long double num, char *to_print,
								int count)
{
	int		len;

	*to_print = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	len = count + (((num < 0) || data->flag[1] == '+'
						|| data->flag[2] == ' ') ? 1 : 0);
	return ((data->field_width > len) ? data->field_width - len : 0);
}

static void			put_sign(t_printf *data, long double num, int *count)
{
	if (num < 0)
	{
		ft_putchar('-');
		*count += 1;
	}
	else if (num >= 0 && data->flag[1] == '+')
	{
		ft_putchar('+');
		*count += 1;
	}
	else if (num > 0 && data->flag[1] != '+' && data->flag[2] == ' ')
	{
		ft_putchar(' ');
		*count += 1;
	}
}

/*
** get_len handles the whole number, decimal and precision
** get_width handles everything else that needs to be printed
*/

void				convert_e(t_printf *data)
{
	long double		num;
	int				count;
	int				width;
	char			to_print;

	num = get_num(data);
	data->precision = data->precision == -1 ? 6 : data->precision;
	count = get_len(data, num);
	width = get_width_e(data, num, &to_print, count);
	if (data->flag[0] != '-' && to_print == ' ')
		padding2(to_print, &count, width);
	put_sign(data, num, &count);
	if (data->flag[0] != '-' && to_print == '0')
		padding2(to_print, &count, width);
	put_num_e(data, num, &count);
	if (data->flag[0] == '-')
		padding2(to_print, &count, width);
	data->len += count;
}
