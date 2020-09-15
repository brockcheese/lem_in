/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:02:56 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:16:38 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static unsigned long long	get_num(t_printf *data)
{
	unsigned long long	num;

	if (ft_strcmp(data->length, "hh") == 0)
		num = (unsigned char)(va_arg(data->ap, unsigned int));
	else if (ft_strcmp(data->length, "h") == 0)
		num = (unsigned short)(va_arg(data->ap, unsigned int));
	else if (ft_strcmp(data->length, "ll") == 0)
		num = (unsigned long long)(va_arg(data->ap, unsigned long long));
	else if (ft_strcmp(data->length, "l") == 0)
		num = (unsigned long)(va_arg(data->ap, unsigned long));
	else
		num = (unsigned int)(va_arg(data->ap, unsigned int));
	return (num);
}

static char					*convert_u2(t_printf *data, unsigned long long num)
{
	int		len;
	char	*result;

	if (num == 0 && data->precision == 0)
		return (ft_strdup(""));
	len = ft_numlen(num);
	if (data->precision > len)
	{
		len = data->precision;
		result = ft_strnew(len);
		ft_intmove(result, len, num, 0);
		return (result);
	}
	result = ft_strnew(len);
	ft_intmove(result, len, num, 0);
	return (result);
}

void						convert_u(t_printf *data)
{
	int					count;
	int					width;
	char				*result;
	char				to_print;
	unsigned long long	num;

	count = 0;
	num = get_num(data);
	result = convert_u2(data, num);
	width = get_width(data, result, &to_print);
	if (data->flag[0] != '-')
		padding2(to_print, &count, width);
	ft_putstr(result);
	if (data->flag[0] == '-')
		padding2(to_print, &count, width);
	count += ft_strlen(result);
	data->len += count;
	free(result);
}
