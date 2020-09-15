/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:03:00 by rcross            #+#    #+#             */
/*   Updated: 2019/06/27 17:16:33 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static char		*check_str(t_printf *data, char *str)
{
	char	*result;

	if (data->conversion == 'S')
		result = ft_str_to_upper(str);
	else
		result = str;
	return (result);
}

void			convert_s(t_printf *data)
{
	char	*str;
	int		len;

	str = va_arg(data->ap, char *);
	if (data->precision > -1 && str)
		str = ft_strndup(str, data->precision);
	else if (data->precision == -1 && str)
		str = ft_strdup(str);
	else if (data->precision > -1 && !str)
		str = ft_strndup("(null)", data->precision);
	else if (data->precision == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	data->len += len;
	if (data->flag[3] == '0' && data->flag[0] != '-')
		padding(data, '0', data->field_width - len, 1);
	else if (data->flag[0] != '-')
		padding(data, ' ', data->field_width - len, 1);
	str = check_str(data, str);
	ft_putstr(str);
	if (data->flag[0] == '-')
		padding(data, ' ', data->field_width - len, 1);
	free(str);
}
