/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:33:42 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/24 11:13:12 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void set_flags(t_flags *flags, int sinal)
{
	if (sinal == 0)
		flags->pos_str = 0;
	flags->dot = 0;
	flags->presition = 0;
	flags->sinal = 0;
	flags->width = 0;
	flags->zero = 0;
}

static void verify_type(va_list list, t_flags *flag)
{
	pupulate_flags(list, flag);
	if (flag->str[flag->pos_str] == 'c')
		set_char(list, flag);
	else if (flag->str[flag->pos_str] == 's')
		set_string(list, flag);
	else if (flag->str[flag->pos_str] == 'd' || flag->str[flag->pos_str] == 'i')
		set_integer(list, flag);
	set_flags(flag, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list list;
	t_flags	flags;

	set_flags(&flags, 0);
	flags.str = ft_substr(str, 0, ft_strlen(str));
	va_start(list, str);
	while (str[flags.pos_str] != 0)
	{
		if (str[flags.pos_str] == '%')
		{
			flags.pos_str++;
			verify_type(list, &flags);
		}
		else
			ft_putchar_fd(flags.str[flags.pos_str], 1);
		flags.pos_str++;
	}
	//printf("--------------\n count: %i\n dot: %i\n presition: %i\n sinal: %i\n width: %i\n zero: %i\n", flags.pos_str, flags.dot, flags.presition, flags.sinal, flags.width, flags.zero);
	va_end(list);
	return (flags.pos_str);
}
