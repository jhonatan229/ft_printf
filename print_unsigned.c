/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:23:49 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/29 17:27:13 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	count_places(unsigned int num, char *base)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += count_places(num / len_base, base);
	return (count);
}

static int	print_places(unsigned int num, char *base, int len_print)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += print_places(num / len_base, base, len_print);
	if (count <= len_print)
		ft_putchar_fd(base[num % len_base] , 1);
	return (count);
}

static void	print_aling_rigth(char c, int len_numb, int numb, t_flags *flag)
{
	int len;
	int press;

	press = flag->presition - len_numb;
	if (flag->presition > len_numb)
		len_numb = flag->presition;
	if (flag->width > len_numb)
	{
		len = flag->width - len_numb;
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
	while (press-- > 0)
		ft_putchar_fd('0', 1);
	if (flag->str[flag->pos_str] == 'u')
		print_places(numb, BASE_DESC, len_numb);
	else if (flag->str[flag->pos_str] == 'x')
		print_places(numb, BASE_LOWER_HEXA, len_numb);
	else if (flag->str[flag->pos_str] == 'X')
		print_places(numb, BASE_UPPER_HEXA, len_numb);
}

static void	print_aling_left(char c, int len_numb, int numb, t_flags *flag)
{
	int len;
	int press;

	press = flag->presition - len_numb;
	while (press-- > 0)
		ft_putchar_fd('0', 1);
	if (flag->str[flag->pos_str] == 'u')
		len = print_places(numb, BASE_DESC, len_numb);
	else if (flag->str[flag->pos_str] == 'x')
		len = print_places(numb, BASE_LOWER_HEXA, len_numb);
	else if (flag->str[flag->pos_str] == 'X')
		len = print_places(numb, BASE_UPPER_HEXA, len_numb);
	if (flag->presition > len_numb)
		len_numb = flag->presition;
	if (flag->width > len_numb)
	{
		len = flag->width - len_numb;
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
}

void	set_unsigned(va_list list, t_flags *flag)
{
	int	len;
	unsigned int numb;

	numb = va_arg(list, unsigned int);
	if (flag->str[flag->pos_str] == 'u')
		len = count_places(numb, BASE_DESC);
	else if (flag->str[flag->pos_str] == 'x')
		len = count_places(numb, BASE_LOWER_HEXA);
	else if (flag->str[flag->pos_str] == 'X')
		len = count_places(numb, BASE_UPPER_HEXA);
	if (flag->zero)
		print_aling_rigth('0', len, numb, flag);
	else if (flag->sinal)
		print_aling_left(' ', len, numb, flag);
	else
		print_aling_rigth(' ', len, numb, flag);
}