/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:33:42 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/29 18:24:36 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	set_flags(t_flags *flags, int sinal)
{
	if (sinal == 0)
	{
		flags->pos_str = 0;
		flags->return_len = 0;
	}	
	flags->dot = 0;
	flags->presition = 0;
	flags->sinal = 0;
	flags->width = 0;
	flags->zero = 0;
}

static void	verify_type(va_list list, t_flags *flag)
{
	char	c;

	pupulate_flags(list, flag);
	if (flag->width > 0)
		flag->return_len += flag->width;
	else
		flag->return_len++;
	c = flag->str[flag->pos_str];
	if (c == 'c')
		set_char(list, flag);
	else if (c == 's')
		set_string(list, flag);
	else if (c == 'd' || c == 'i')
		set_integer(list, flag);
	else if (c == 'u' || c == 'x' || c == 'X')
		set_unsigned(list, flag);
	else if (c == '%')
		ft_putchar_fd('c', 1);
	else if (c == 'p')
		set_pointer(list, flag);
	set_flags(flag, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
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
		flags.return_len++;
		flags.pos_str++;
	}
	va_end(list);
	free(flags.str);
	return (flags.return_len - 1);
}
