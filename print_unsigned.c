/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:23:49 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/13 18:15:50 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

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

static void	print_hashtag(int numb, int len_numb, t_flags *flag, int sinal)
{
	int	press;

	press = (flag->presition - len_numb);
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

	if (flag->presition > len_numb)
		press = flag->presition;
	else
		press = len_numb;
	if (flag->width > press + flag->hashtag)
	{
		flag->return_len += flag->width;
		len = flag->width - (press + flag->hashtag);
		while (len-- > 0 && c != '0')
			ft_putchar_fd(c, 1);
	}
	else
		flag->return_len += (press + flag->hashtag);
	if (flag->str[flag->pos_str] == 'u')
		print_hashtag(numb, len_numb, flag, 1);
	else if (flag->str[flag->pos_str] == 'x')
		print_hashtag(numb, len_numb, flag, 2);
	else if (flag->str[flag->pos_str] == 'X')
		print_hashtag(numb, len_numb, flag, 3);
}

static void	print_aling_left(char c, int len_numb, int numb, t_flags *flag)
{
	int	len;

	if (flag->str[flag->pos_str] == 'u')
		print_hashtag(numb, len_numb, flag, 1);
	else if (flag->str[flag->pos_str] == 'x')
		print_hashtag(numb, len_numb, flag, 2);
	else if (flag->str[flag->pos_str] == 'X')
		print_hashtag(numb, len_numb, flag, 3);
	if (flag->presition > len_numb)
		len_numb = flag->presition;
	if (flag->width > len_numb + flag->hashtag)
	{
		flag->return_len += flag->width;
		len = flag->width - (len_numb + flag->hashtag);
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
	else
		flag->return_len += (len_numb + flag->hashtag);
}

void	set_unsigned(va_list list, t_flags *flag)
{
	int				len;
	unsigned int	numb;

	numb = va_arg(list, unsigned int);
	if (flag->str[flag->pos_str] == 'u')
		len = count_unsigned(numb, BASE_DESC, flag);
	else if (flag->str[flag->pos_str] == 'x')
		len = count_unsigned(numb, BASE_LOWER_HEXA, flag);
	else if (flag->str[flag->pos_str] == 'X')
		len = count_unsigned(numb, BASE_UPPER_HEXA, flag);
	if (flag->hashtag && numb == 0)
		flag->hashtag = 0;
	if (flag->zero && !flag->dot)
		print_aling_rigth('0', len, numb, flag);
	else if (flag->sinal)
		print_aling_left(' ', len, numb, flag);
	else
		print_aling_rigth(' ', len, numb, flag);
}
