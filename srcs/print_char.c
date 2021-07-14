/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 14:13:06 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/14 15:17:50 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	set_char(va_list list, t_flags *flag)
{
	int	point;

	point = 0;
	if (flag->width > 0)
	{
		flag->return_len += flag->width;
		if (flag->sinal)
		{
			ft_putchar_fd(va_arg(list, int), 1);
			point = 1;
			while (point++ < flag->width)
				ft_putchar_fd(' ', 1);
			return ;
		}
		else if (flag->zero)
			while (point++ < (flag->width - 1))
				ft_putchar_fd('0', 1);
		else
			while (point++ < (flag->width - 1))
				ft_putchar_fd(' ', 1);
	}
	else
		flag->return_len++;
	ft_putchar_fd(va_arg(list, int), 1);
}
