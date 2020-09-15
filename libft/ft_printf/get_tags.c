/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:59:51 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:14:18 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		convert(t_printf *data)
{
	if (data->conversion == 'd' || data->conversion == 'i')
		convert_i(data);
	else if (data->conversion == 'c')
		convert_c(data);
	else if (data->conversion == 's' || data->conversion == 'S')
		convert_s(data);
	else if (data->conversion == 'u')
		convert_u(data);
	else if (data->conversion == 'x' || data->conversion == 'X')
		convert_x(data);
	else if (data->conversion == 'o')
		convert_o(data);
	else if (data->conversion == 'p')
		convert_p(data);
	else if (data->conversion == 'f')
		convert_f(data);
	else if (data->conversion == 'e' || data->conversion == 'E')
		convert_e(data);
	else if (data->conversion == 'b')
		convert_b(data);
	else if (data->conversion == 'r')
		convert_r(data);
	else
		convert_percent(data);
}

/*
**	move over modulo, gather all the flags then begin conversions
*/

void			get_tags(t_printf *data)
{
	data->i++;
	parse_flags(data);
	parse_field_width(data);
	parse_precision(data);
	parse_length(data);
	parse_conversion(data);
	convert(data);
}
