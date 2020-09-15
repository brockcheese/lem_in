/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:38:27 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:51 by rcross           ###   ########.fr       */
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

static char					*make_binary0(unsigned long long number)
{
	int					size;
	unsigned long long	temp;
	char				*result;
	char				*binary_string;

	size = 1;
	temp = number;
	if (!number)
		return (ft_strdup("0"));
	while (temp /= 2)
		size++;
	MEM_CHK((result = malloc(sizeof(char) * size + 1)));
	binary_string = "01";
	result[size--] = '\0';
	while (number)
	{
		result[size] = binary_string[number % 2];
		number /= 2;
		size--;
	}
	return (result);
}

void						convert_b(t_printf *data)
{
	unsigned long long	num;
	char				*result;
	char				to_print;
	int					count;
	int					width;

	count = 0;
	num = get_num(data);
	result = make_binary0(num);
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
