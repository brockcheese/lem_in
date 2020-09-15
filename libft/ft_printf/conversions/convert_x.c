/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:26 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:16:44 by rcross           ###   ########.fr       */
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

static char					*make_hex0(unsigned long long number)
{
	int					size;
	unsigned long long	temp;
	char				*result;
	char				*hex_string;

	size = 1;
	temp = number;
	if (!number)
		return (ft_strdup("0"));
	while (temp /= 16)
		size++;
	MEM_CHK((result = (char *)malloc(sizeof(char) * size + 1)));
	hex_string = "0123456789abcdef";
	result[size--] = '\0';
	while (number)
	{
		result[size] = hex_string[number % 16];
		number /= 16;
		size--;
	}
	return (result);
}

static void					print_0x(t_printf *data, int *count)
{
	if (data->flag[4] == '#' && data->conversion == 'x')
	{
		ft_putstr("0x");
		*count += 2;
	}
	if (data->flag[4] == '#' && data->conversion == 'X')
	{
		ft_putstr("0X");
		*count += 2;
	}
}

void						convert_x(t_printf *data)
{
	unsigned long long	num;
	char				*result;
	char				to_print;
	int					count;
	int					width;

	count = 0;
	num = get_num(data);
	result = make_hex0(num);
	if (data->conversion == 'X')
		result = ft_str_to_upper(result);
	width = get_width(data, result, &to_print);
	if (data->flag[0] != '-')
		padding2(to_print, &count, width);
	print_0x(data, &count);
	ft_putstr(result);
	if (data->flag[0] == '-')
		padding2(to_print, &count, width);
	count += ft_strlen(result);
	data->len += count;
	free(result);
}
