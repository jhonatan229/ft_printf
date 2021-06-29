/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:45:05 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/29 15:38:28 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static int	count_print_places(unsigned long int num, char *base, int sinal)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += count_print_places(num / len_base, base, sinal);
	if (sinal == 1)
		ft_putchar_fd(base[num % len_base] , 1);
	return (count);
}

static void	print_pointer(unsigned long int numb)
{
	ft_putstr_fd("0x", 1);
	count_print_places(numb, BASE_LOWER_HEXA, 1);
}

static void print_right_left(int dif, unsigned long int numb, int sinal)
{
	if (sinal == 1)
	{
		print_pointer(numb);
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else 
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
		print_pointer(numb);
}

void	set_pointer(va_list list, t_flags *flag)
{
	unsigned long int	numb;
	int	len_num;
	int diference;

	numb = va_arg(list, unsigned long int);
	if (numb == 0)
	{
		if (flag->dot)
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0x0", 1);
		return ;
	}
	len_num = count_print_places(numb, BASE_LOWER_HEXA, 0) + 2;
	if (flag->width > len_num)
	{
		diference = flag->width - len_num;
		if (flag->sinal)
			print_right_left(diference, numb, 1);
		else
			print_right_left(diference, numb, 0);
	}
	else
		print_pointer(numb);
}
