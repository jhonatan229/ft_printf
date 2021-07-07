/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:33 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/07 18:13:48 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	print_dif(int dif, char c, int sinal, int pos_or_neg)
{
	if (pos_or_neg == 1)
	{
		if (sinal == 1)
			ft_putchar_fd('+', 1);
		while (dif-- > 0)
			ft_putchar_fd(c, 1);
		if (sinal == 2)
			ft_putchar_fd('+', 1);
	}
	else if (pos_or_neg == 2)
	{
		if (sinal == 1)
			ft_putchar_fd('-', 1);
		while (dif-- > 0)
			ft_putchar_fd(c, 1);
		if (sinal == 2)
			ft_putchar_fd('-', 1);
	}
	else if (pos_or_neg == 3)
	{
		if (sinal == 1)
			ft_putchar_fd(' ', 1);
		while (dif-- > 0)
			ft_putchar_fd(c, 1);
		if (sinal == 2)
			ft_putchar_fd(' ', 1);
	}
	else 
		while (dif-- > 0)
			ft_putchar_fd(c, 1);
}

static void	print_negative(int num, int len, int wid, t_flags *flag)
{
	int	press;

	press = flag->presition - len;
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		ft_putchar_fd('-', 1);
		if (press > 0)
			print_dif(press, '0', 0, 2);
		count_print_int(num, BASE_DESC, 1, len);
		print_dif(wid, ' ', 0, 2);
		return ;
	}
	if (flag->zero && !flag->dot)
		print_dif(wid, '0', 1, 2);
	else
		print_dif(wid, ' ', 2, 2);
	if (press > 0)
		print_dif(press, '0', 0, 2);
	count_print_int(num, BASE_DESC, 1, len);
}

static void	print_positive(int num, int len, int wid, t_flags *flag)
{
	int	press;

	press = flag->presition - len;
	if (flag->plus || flag->blank)
		wid--;
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		if (flag->plus)
			ft_putchar_fd(flag->sinal_int, 1);
		if (press > 0)
			print_dif(press, '0', 0, flag->plus);
		count_print_int(num, BASE_DESC, 1, len);
		print_dif(wid, ' ', 0, flag->plus);
		return ;
	}
	if (flag->zero && !flag->dot)
		print_dif(wid, '0', 1, flag->plus);
	else
		print_dif(wid, ' ', 2, flag->plus);
	if (press > 0)
		print_dif(press, '0', 0, flag->plus);
	count_print_int(num, BASE_DESC, 1, len);
}

static void	print_num(int num, int sinal, int len, t_flags *flag)
{
	int	wid;

	wid = 0;
	if ((flag->width > 0 && flag->width > len) || flag->presition > len)
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
		if (flag->width > flag->presition && flag->width > len)
			flag->return_len--;
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
		if (!flag->plus && !flag->blank)
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
	if ((flag->plus || flag->blank)&& flag->width <= len)
		flag->return_len++;
	if (!flag->plus && flag->blank)
		flag->plus = 3;
	print_num(num, sinal, len, flag);
}
