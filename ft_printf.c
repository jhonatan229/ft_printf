/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:33:42 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/23 12:58:11 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void verify_type(va_list list, t_flags *flag)
{
	int n;

	n = pupulate_flags(flag);
}

static void set_flags(t_flags *flags)
{
	flags->dot = 0;
	flags->pos_str = 0;
	flags->presition = 0;
	flags->sinal = 0;
	flags->width = 0;
	flags->zero = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list list;
	t_flags	flags;

	set_flags(&flags);
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
	printf("--------------\n count: %i\n dot: %i\n presition: %i\n sinal: %i\n width: %i\n zero: %i\n", flags.pos_str, flags.dot, flags.presition, flags.sinal, flags.width, flags.zero);
	va_end(list);
	return (flags.pos_str);
}
