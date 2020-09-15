/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:39 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:15:53 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static void		print_0x(int *count)
{
	ft_putstr("0x");
	*count += 2;
}

static char		*make_hex0(unsigned long long number)
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

void			convert_p(t_printf *data)
{
	int			width;
	int			count;
	char		*result;
	char		to_print;
	intptr_t	num;

	num = va_arg(data->ap, intptr_t);
	result = make_hex0(num);
	width = get_width(data, result, &to_print);
	if (data->flag[0] != '-')
		padding2(to_print, &count, width);
	print_0x(&count);
	ft_putstr(result);
	if (data->flag[0] == '-')
		padding2(to_print, &count, width);
	count += ft_strlen(result);
	data->len += count;
	free(result);
}
