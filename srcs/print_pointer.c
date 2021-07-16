/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:45:05 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 17:12:37 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//will treated if the pointer is 0 or not
static void	print_pointer(unsigned long int numb, int s_dot)
{
	//will print '0' if the number is equal 0 and the signal of  dot precision(flag->dot) is off
	if (numb == 0)
	{
		if (s_dot == 0)
			ft_putchar_fd('0', 1);
	}
	//otherwise print the pointer
	else
		count_print_pointer(numb, BASE_LOWER_HEXA, 1);
}

//will print an exact structure depending on the signal passed as a parameter.
static void	print_r_l(int dif, unsigned long int numb, int sinal, int s_dot)
{
	//this "if" will take one out of the "diff", because of the '0' that will be printed
	if (numb == 0 && s_dot == 0)
		dif--;
	if (sinal == 1)
	{
		ft_putstr_fd("0x", 1);
		print_pointer(numb, s_dot);
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (sinal == 2)
	{
		ft_putstr_fd("0x", 1);
		while (dif-- > 0)
			ft_putchar_fd('0', 1);
		print_pointer(numb, s_dot);
	}
	else
	{
		while (dif-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		print_pointer(numb, s_dot);
	}
}

//will align the pointer for left or right depending of the flags
static void	align_print(int len_num, unsigned long int numb, t_flags *flag)
{
	//my return_len will receive width if width bigger than len_numb
	if (flag->width > len_num)
	{
		flag->return_len += flag->width;
		//the pointer will be align for left or right depending if flag '-' is ON or not
		if (flag->sinal)
			print_r_l(flag->width - len_num, numb, 1, flag->dot);
		else
			print_r_l(flag->width - len_num, numb, 0, flag->dot);
	}
	//otherwise if my precision + 2(is the count "0x") is bigger than len_numb, this value will be add on retur_len
	//and this difference between precision and len_numb will be filled by '0', in front of the pointer
	else if ((flag->precision + 2) > len_num)
	{
		flag->return_len += flag->precision + 2;
		print_r_l((flag->precision + 2) - len_num, numb, 2, flag->dot);
	}
	//otherwise, will print the pointer only
	else
	{
		//this case is if my pointer is 0 and my dot of precision is off, then add one in the return_len,
		//because is e count of '0' that will be printed after 0x
		if (len_num == 2 && !flag->dot)
			flag->return_len++;
		//add the length of num in return_len
		flag->return_len += len_num;
		ft_putstr_fd("0x", 1);
		//print pointer
		print_pointer(numb, flag->dot);
	}
}

//will print a adress pointer, depending on my flags turned on.
void	set_pointer(va_list list, t_flags *flag)
{
	unsigned long int	numb;
	int					len_num;

	//is the count of "0x" that all pointer have
	len_num = 2;
	numb = va_arg(list, unsigned long int);
	//if my number is different of 0, will be count the number places in base hexadecimal (16)
	if (numb != 0)
		len_num += count_print_pointer(numb, BASE_LOWER_HEXA, 0);
	align_print(len_num, numb, flag);
}
