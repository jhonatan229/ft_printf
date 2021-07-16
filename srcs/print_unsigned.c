/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:23:49 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 18:20:39 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//print the number, with base on my length of char "base", that is a numeric base
//print only the first (len) places
static int	print_places(unsigned int num, char *base, int len, t_flags *flag)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += print_places(num / len_base, base, len, flag);
	if (count <= len)
		ft_putchar_fd(base[num % len_base], 1);
	return (count);
}

//will print the number, depending of the signal that is coming in the parameter
static void	print_hashtag(int numb, int len_numb, t_flags *flag, int sinal)
{
	int	press;

	press = (flag->precision - len_numb);
	if (sinal == 1)
	{
		print_hash_hexa(numb, sinal, flag, len_numb);
		print_places(numb, BASE_DESC, len_numb, flag);
	}
	else if (sinal == 2)
	{
		print_hash_hexa(numb, sinal, flag, len_numb);
		print_places(numb, BASE_LOWER_HEXA, len_numb, flag);
	}
	else if (sinal == 3)
	{
		print_hash_hexa(numb, sinal, flag, len_numb);
		print_places(numb, BASE_UPPER_HEXA, len_numb, flag);
	}
}

static void	print_aling_rigth(char c, int len_numb, int numb, t_flags *flag)
{
	int	len;
	int	press;

	//the press will receive precision if it is bigger than length numb
	if (flag->precision > len_numb)
		press = flag->precision;
	else
		press = len_numb;
	//if the width is bigger than length of number plus flag hashtag(in case, if ON, will value 2(equivalent of "0x"))
	//if true, the return_len receive this value
	//the difference(len) receive width minus length of number plus flag hashtag
	if (flag->width > press + flag->hashtag)
	{
		flag->return_len += flag->width;
		len = flag->width - (press + flag->hashtag);
		//this while will not work with c equals '0', because this will be treated in another function
		while (len-- > 0 && c != '0')
			ft_putchar_fd(c, 1);
	}
	//otherwise, the return_len receive length of number plus flag hashtag
	else
		flag->return_len += (press + flag->hashtag);
	//will print the numb depending of type that is coming.
	if (flag->str[flag->pos_str] == 'u')
		print_hashtag(numb, len_numb, flag, 1);
	else if (flag->str[flag->pos_str] == 'x')
		print_hashtag(numb, len_numb, flag, 2);
	else if (flag->str[flag->pos_str] == 'X')
		print_hashtag(numb, len_numb, flag, 3);
}

//will align to left and populate the places with the flag that is ON
static void	print_aling_left(char c, int len_numb, int numb, t_flags *flag)
{
	int	len;

	//will print the numb depending of type that is coming.
	if (flag->str[flag->pos_str] == 'u')
		print_hashtag(numb, len_numb, flag, 1);
	else if (flag->str[flag->pos_str] == 'x')
		print_hashtag(numb, len_numb, flag, 2);
	else if (flag->str[flag->pos_str] == 'X')
		print_hashtag(numb, len_numb, flag, 3);
	//the length numb will receive precision if it is bigger than it
	if (flag->precision > len_numb)
		len_numb = flag->precision;
	//if the width is bigger than length of number plus flag hashtag(in case, if ON, will value 2(equivalent of "0x"))
	//if true, the return_len receive this value
	//the difference(len) receive width minus length of number plus flag hashtag
	if (flag->width > len_numb + flag->hashtag)
	{
		flag->return_len += flag->width;
		len = flag->width - (len_numb + flag->hashtag);
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
	//otherwise, the return_len receive length of number plus flag hashtag
	else
		flag->return_len += (len_numb + flag->hashtag);
}

//will print a unsigned int, depending on my flags turned on.
void	set_unsigned(va_list list, t_flags *flag)
{
	int				len;
	unsigned int	numb;

	numb = va_arg(list, unsigned int);
	//will count the length of int depend of variable type
	if (flag->str[flag->pos_str] == 'u')
		len = count_unsigned(numb, BASE_DESC, flag);
	else if (flag->str[flag->pos_str] == 'x')
		len = count_unsigned(numb, BASE_LOWER_HEXA, flag);
	else if (flag->str[flag->pos_str] == 'X')
		len = count_unsigned(numb, BASE_UPPER_HEXA, flag);
	//disable the flag hashtag if the numb is 0;
	if (flag->hashtag && numb == 0)
		flag->hashtag = 0;
	//aligns right or left depending of wich flag is ON
	if (flag->zero && !flag->dot)
		print_aling_rigth('0', len, numb, flag);
	else if (flag->sinal)
		print_aling_left(' ', len, numb, flag);
	else
		print_aling_rigth(' ', len, numb, flag);
}
