/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 10:33:42 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 12:44:18 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//going to set my struct with the information of flags and something else to 0,
//but only one time to pos_str(position of string) and return_len(the len of my string).
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
	flags->blank = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->sinal_int = 0;
}

//if there is no type before "%", print the quantity of my width based on flags that are ON
static void	only_width(t_flags *flag, char c)
{
	//goig to add this quantity in my return_len
	//if my width does not exist, will add only one in my return, because the char probably is a "%" or any other type that i didn't treat yet.
	if (flag->width > 1)
	{
		flag->return_len += flag->width;
		flag->width--;
	}
	else
		flag->return_len++;
	if (flag->sinal)
	{
		ft_putchar_fd(c, 1);
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (flag->zero)
	{
		while (flag->width-- > 0)
			ft_putchar_fd('0', 1);
		ft_putchar_fd(c, 1);
	}
	else
	{
		while (flag->width-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(c, 1);
	}
}

//will verify the char after"%" or the flags, and check if match with any type that already treated.
//if the char don't match, will call the function above (only_width).
static void	verify_type(va_list list, t_flags *flag)
{
	char	c;

	pupulate_flags(list, flag);
	c = flag->str[flag->pos_str];
	if (c == 'c')
		set_char(list, flag);
	else if (c == 's')
		set_string(list, flag);
	else if (c == 'd' || c == 'i')
		set_integer(list, flag);
	else if (c == 'u' || c == 'x' || c == 'X')
		set_unsigned(list, flag);
	else if (c == 'p')
		set_pointer(list, flag);
	else
		only_width(flag, c);
	set_flags(flag, 1);
}

//will print a string "str" with the variables, if there is any type in my string "str", (ex: %i, %p ...).
//return the length of "str" with the modifications.
int	ft_printf(const char *str, ...)
{
	va_list	list;
	t_flags	flags;

	//sets my flags to 0, included the pos_str and return_len, that variables will be set only one time.
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
		{
			ft_putchar_fd(flags.str[flags.pos_str], 1);
			flags.return_len++;
		}
		flags.pos_str++;
	}
	va_end(list);
	free(flags.str);
	return (flags.return_len);
}
