/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:45:05 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/29 20:43:28 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	count_print_places(unsigned long int num, char *base, int sinal)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	if (num == 0)
		return (0);
	count = 1;
	if (num / len_base > 0)
		count += count_print_places(num / len_base, base, sinal);
	if (sinal == 1)
		ft_putchar_fd(base[num % len_base] , 1);
	return (count);
}

static void	print_pointer(unsigned long int numb, int s_dot)
{
	ft_putstr_fd("0x", 1);
	if (numb == 0)
	{
		if (s_dot == 0)
			ft_putchar_fd('0', 1);
	}
	else
		count_print_places(numb, BASE_LOWER_HEXA, 1);
}

static void print_right_left(int dif, unsigned long int numb, int sinal, int s_dot)
{
	if (sinal == 1)
	{
		print_pointer(numb, s_dot);
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
		print_pointer(numb, s_dot);
	}
}

void	set_pointer(va_list list, t_flags *flag)
{
	unsigned long int	numb;
	int	len_num;

	numb = va_arg(list, unsigned long int);
	len_num = count_print_places(numb, BASE_LOWER_HEXA, 0) + 2;
	if (flag->width > len_num)
	{
		flag->return_len += flag->width;
		if (flag->sinal)
			print_right_left(flag->width - len_num, numb, 1, flag->dot);
		else
			print_right_left(flag->width - len_num, numb, 0, flag->dot);
	}
	else
	{
		flag->return_len += len_num;
		print_pointer(numb, flag->dot);
	}
}
