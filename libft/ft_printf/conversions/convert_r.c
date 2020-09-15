/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 01:54:12 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:16:08 by rcross           ###   ########.fr       */
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

static char					*make_roman_numeral(unsigned long long number)
{
	int					size;
	char				*result;
	int					*decimal;
	char				**symbol;
	int					i;

	decimal = get_roman_decimals();
	symbol = get_roman_symbols();
	size = 0;
	i = 0;
	if (!number)
		return (ft_strdup("0"));
	result = ft_strnew(1);
	while (number)
	{
		while (number / decimal[i])
		{
			result = ft_strcat(result, symbol[i]);
			number -= decimal[i];
		}
		i++;
	}
	free(decimal);
	ft_free_2d(symbol);
	return (result);
}

void						convert_r(t_printf *data)
{
	unsigned long long	num;
	char				*result;
	char				to_print;
	int					count;
	int					width;

	count = 0;
	num = get_num(data);
	result = make_roman_numeral(num);
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
