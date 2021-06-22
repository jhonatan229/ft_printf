/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:33:42 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/22 18:47:05 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void verify_type(va_list list, t_flags *flag)
{
	populate_flags(flag);
	if(s[count]== 's')
		ft_putstr_fd(va_arg(list, char*), 1);
	else if (s[count]== 'd' || s[count]== 'i')
		ft_putnbr_fd(va_arg(list, int), 1);
	else if (s[count]== 'c')
		ft_putchar_fd(s, 1);
	else if (s[count]== 'f')
		ft_printf(" ((working that)) ");
	
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

	set_flags(flags);
	ft_memcpy(flags->str, str, ft_strlen(str));
	va_start(list, str);
	while (str[flags->pos_str] != 0)
	{
		if (str[flags->pos_str] == '%')
		{
			flags->pos_str++;
			verify_type(str, list, flags->pos_str, flags);
		}
		else
			ft_putchar_fd(str[flags->pos_str], 1);
		flags->pos_str++;
	}
	va_end(list);
	return (flags->pos_str);
}
