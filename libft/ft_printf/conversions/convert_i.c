/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:50:00 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:15:16 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static int64_t		get_num(t_printf *data)
{
	int64_t		num;

	if (ft_strcmp(data->length, "hh") == 0)
		num = (signed char)(va_arg(data->ap, int));
	else if (ft_strcmp(data->length, "h") == 0)
		num = (short)(va_arg(data->ap, int));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = (long long)(va_arg(data->ap, long long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = (long)(va_arg(data->ap, long));
	else
		num = va_arg(data->ap, int);
	return (num);
}

static int			get_width_i(t_printf *data, int64_t num, char *result,
													char *to_print)
{
	int		len;

	*to_print = (data->flag[3] == '0' && data->flag[0] != '-') ? '0' : ' ';
	len = ft_strlen(result) + ((num < 0 || data->flag[2] == ' ' ||
									data->flag[1] == '+') ? 1 : 0);
	return ((data->field_width > len) ? data->field_width - len : 0);
}

static void			put_sign(t_printf *data, int64_t num, int *count)
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

static char			*convert_i2(t_printf *data, int64_t number)
{
	unsigned long long	num;
	char				*result;
	int					len;

	if (number == 0 && data->precision == 0)
		return (ft_strdup(""));
	num = (number < 0) ? -number : number;
	len = ft_numlen(num);
	if (data->precision > len)
	{
		result = ft_strnew(data->precision);
		ft_memset(result, '0', data->precision);
		ft_intmove(result, data->precision, num, 0);
		return (result);
	}
	result = ft_strnew(len);
	ft_intmove(result, len, num, 0);
	return (result);
}

void				convert_i(t_printf *data)
{
	char		*result;
	char		to_print;
	int			width;
	int			count;
	int64_t		num;

	count = 0;
	num = get_num(data);
	result = convert_i2(data, num);
	width = get_width_i(data, num, result, &to_print);
	if (data->flag[0] != '-' && to_print == ' ')
		padding2(to_print, &count, width);
	put_sign(data, num, &count);
	if (data->flag[0] != '-' && to_print == '0')
		padding2(to_print, &count, width);
	ft_putstr(result);
	if (data->flag[0] == '-')
		padding2(to_print, &count, width);
	count += ft_strlen(result);
	data->len += count;
	free(result);
}
