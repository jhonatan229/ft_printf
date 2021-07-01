/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:33 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/01 20:08:49 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	count_print_int(int num, char *base, int sinal, int len_print)
{
	int	len_base;
	int	count;

	count = 1;
	len_base = ft_strlen(base);
	if (num < 0 )
	{
		if (num == -2147483648)
		{
			if (sinal == 1)
				ft_putnbr_fd(-2147483648, 1);
			return(10);
		}
		num *= -1;
	}
	if (num / len_base > 0)
		count += count_print_int(num / len_base, base, sinal, len_print);
	if (count <= len_print && sinal == 1)
		ft_putchar_fd(base[num % len_base] , 1);
	return (count);
}

static void print_negative(int num, int len, int wid, t_flags *flag)
{
	int press;

	press = flag->presition - len;
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		ft_putchar_fd('-', 1);
		if (press > 0)
			while (press-- > 0 )
				ft_putchar_fd('0', 1);
		count_print_int(num, BASE_DESC, 1, len);
		while (wid-- > 0)
			ft_putchar_fd(' ', 1);
		return ;
	}
	else if (flag->zero && !flag->dot)
	{
		ft_putchar_fd('-', 1);
		while (wid-- > 0)
			ft_putchar_fd('0', 1);
	}
	else
	{
		while (wid-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('-', 1);
	}
	if (press > 0)
		while (press-- > 0 )
			ft_putchar_fd('0', 1);
	count_print_int(num, BASE_DESC, 1, len);
}

static void print_positive(int num, int len, int wid, t_flags *flag)
{
	int	press;

	press = flag->presition - len;
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		if (press > 0)
			while (press-- > 0 )
				ft_putchar_fd('0', 1);
		count_print_int(num, BASE_DESC, 1, len);
		while (wid-- > 0)
			ft_putchar_fd(' ', 1);
		return ;
	}
	if (flag->zero && !flag->dot)
		while (wid-- > 0)
			ft_putchar_fd('0', 1);
	else
		while (wid-- > 0)
			ft_putchar_fd(' ', 1);
	if (press > 0)
		while (press-- > 0 )
			ft_putchar_fd('0', 1);
	count_print_int(num, BASE_DESC, 1, len);
}

static void	print_num(int num, int sinal, int len, t_flags *flag)
{
	int	wid;

	wid = 0;
	if ((flag->width > 0 && flag->width > len)|| flag->presition > 0)
	{
		if (flag->presition > flag->width)
			flag->return_len += flag->presition;
		else
			flag->return_len += flag->width;
		wid = flag->width - len;
	}
	else
		flag->return_len += len;
	if (sinal == 1 || num == -2147483648)
	{
		wid--;
		if (num != -2147483648)
			print_negative(num, len, wid, flag);
		else 
			print_positive(num, len, wid, flag);
	}
	else
		print_positive(num, len, wid, flag);
}

void	set_integer(va_list list, t_flags *flag)
{
	int	len;
	int	num;
	int	sinal;

	num = va_arg(list, int);
	if (num < 0)
	{
		flag->return_len++;
		if (num != -2147483648)
			sinal = 1;
	}
	else
		sinal = 0;
	if (flag->presition <= 0 && flag->dot && num == 0)
		len = 0;
	else 
		len = count_print_int(num, BASE_DESC, 0, 0);
	print_num(num, sinal, len, flag);
}
