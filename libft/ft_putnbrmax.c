/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:26:38 by rcross            #+#    #+#             */
/*   Updated: 2019/05/16 18:26:51 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrmax(intmax_t n)
{
	if (n == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax(n / 10);
		ft_putchar((n % 10) + '0');
	}
}
