/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:33 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 15:49:25 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//print the char 'c' (dif) times. Depending of pos_or_neg, print the signal that we need
static void	print_dif(int dif, char c, int sinal, int pos_or_neg)
{
	if (pos_or_neg == 1)
		set_diff_int(sinal, dif, c, '+');
	else if (pos_or_neg == 2)
		set_diff_int(sinal, dif, c, '-');
	else if (pos_or_neg == 3)
		set_diff_int(sinal, dif, c, ' ');
	else
		while (dif-- > 0)
			ft_putchar_fd(c, 1);
}

//treating negative numbers
//will set how the flags going to be print and the quantity of number places will be print
static void	print_negative(int num, int len, int wid, t_flags *flag)
{
	int	press;

	press = flag->precision - len;
	//if there is diference between precision and length number, join with the "wid"
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		//print the negative signal
		ft_putchar_fd('-', 1);
		//print N 0's if there is diference between precision and length number
		if (press > 0)
			print_dif(press, '0', 0, 2);
		//print the number
		count_print_int(num, BASE_DESC, 1, len);
		//print quantity (wid) of blank spaces, then return, for don't pass at rest of function
		print_dif(wid, ' ', 0, 2);
		return ;
	}
	//first, it will print the amount of spaces that flags need, prints the '-' at the right place
	if (flag->zero && !flag->dot)
		print_dif(wid, '0', 1, 2);
	else
		print_dif(wid, ' ', 2, 2);
	if (press > 0)
		print_dif(press, '0', 0, 2);
	//print the number
	count_print_int(num, BASE_DESC, 1, len);
}

//treating positive numbers
//will set how the flags going to be print and the quantity of number places will be print
static void	print_positive(int num, int len, int wid, t_flags *flag)
{
	int	press;

	press = flag->precision - len;
	//take one of "wid" that is equivalent of signal '+' or ' '
	if (flag->plus || flag->blank)
		wid--;
	//if there is diference between precision and length number, join with the "wid"
	if (press > 0)
		wid -= press;
	if (flag->sinal)
	{
		//if there is flag '+' or ' ' ON, print this signal
		if (flag->plus)
			ft_putchar_fd(flag->sinal_int, 1);
		//print N 0's if there is diference between precision and length number
		if (press > 0)
			print_dif(press, '0', 0, flag->plus);
		//print my number
		count_print_int(num, BASE_DESC, 1, len);
		//print quantity (wid) of blank spaces, then return, for don't pass at rest of function
		print_dif(wid, ' ', 0, flag->plus);
		return ;
	}
	//first, it will print the amount of spaces that flags need
	if (flag->zero && !flag->dot)
		print_dif(wid, '0', 1, flag->plus);
	else
		print_dif(wid, ' ', 2, flag->plus);
	if (press > 0)
		print_dif(press, '0', 0, flag->plus);
	//print number
	count_print_int(num, BASE_DESC, 1, len);
}

//will add the right number on return_len, depending on length of width, precision, and number
//will call print_negative if numb is negativel or print_positive if numb is positive
static void	print_num(int num, int sinal, int len, t_flags *flag)
{
	int	wid;

	wid = 0;
	//in this if, will add on "return_len" the bigger length (width, precision or number)
	//the variable "wid" will receive the diference between width and length of number.
	if ((flag->width > 0 && flag->width > len) || flag->precision > len)
	{
		if (flag->precision > flag->width)
			flag->return_len += flag->precision;
		else
			flag->return_len += flag->width;
		wid = flag->width - len;
	}
	else
		flag->return_len += len;
	if (sinal == 1 || num == -2147483648)
	{
		wid--;
		//will remove one of the "return_len" if my width is bigger than precision and length
		//this minus one is of the '-' sign, because it's a negative number.
		if (flag->width > flag->precision && flag->width > len)
			flag->return_len--;
		//if the number is MIN_INT, is go to function "print_positive", because there are i don't print the signal '-',
		//and this will be done in function count_print_int
		if (num != -2147483648)
			print_negative(num, len, wid, flag);
		else
			print_positive(num, len, wid, flag);
	}
	else
		print_positive(num, len, wid, flag);
}

//will print a integer number, depending on my flags turned on.
void	set_integer(va_list list, t_flags *flag)
{
	int	len;
	int	num;
	int	sinal;

	num = va_arg(list, int);
	sinal = 0;
	if (num < 0)
	{
		flag->sinal_int = '-';
		//the MIN INT is the only case that is treated separately
		if (num != -2147483648)
			sinal = 1;
	}
	//the len of number will be 0 only if my dot of precision is on and my precision is 0 or less, and my number is 0
	//otherwise will call my function that will count the number of places that there is in the number.
	if (flag->precision <= 0 && flag->dot && num == 0)
		len = 0;
	else
		len = count_print_int(num, BASE_DESC, 0, 0);
	//my return will add one if there is a flag sinal on ('+' or ' '), and my width is smaller than length of number
	if ((flag->sinal_int != 0) && flag->width <= len)
		flag->return_len++;
	//otherwise if my number is negative, my return received plus one.
	else if (flag->sinal_int == '-')
		flag->return_len++;
	//if my flag blank on and flag plus not, the flag plus will be 3, for more forward, print the rigth signal.
	if (!flag->plus && flag->blank)
		flag->plus = 3;
	print_num(num, sinal, len, flag);
}
