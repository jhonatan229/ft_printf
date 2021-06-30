/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:23:49 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/30 13:04:01 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	count_places(unsigned int num, char *base, t_flags *flag)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (flag->presition <= 0 && flag->dot && num == 0)
		return (0);
	if (num / len_base > 0)
		count += count_places(num / len_base, base, flag);
	return (count);
}

static int	print_places(unsigned int num, char *base, int len_print, t_flags *flag)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += print_places(num / len_base, base, len_print, flag);
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
		flag->return_len += flag->width;
		len = flag->width - len_numb;
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
	else
		flag->return_len += len_numb;
	while (press-- > 0)
		ft_putchar_fd('0', 1);
	if (flag->str[flag->pos_str] == 'u')
		print_places(numb, BASE_DESC, len_numb, flag);
	else if (flag->str[flag->pos_str] == 'x')
		print_places(numb, BASE_LOWER_HEXA, len_numb, flag);
	else if (flag->str[flag->pos_str] == 'X')
		print_places(numb, BASE_UPPER_HEXA, len_numb, flag);
}

static void	print_aling_left(char c, int len_numb, int numb, t_flags *flag)
{
	int len;
	int press;

	press = flag->presition - len_numb;
	while (press-- > 0)
		ft_putchar_fd('0', 1);
	if (flag->str[flag->pos_str] == 'u')
		print_places(numb, BASE_DESC, len_numb, flag);
	else if (flag->str[flag->pos_str] == 'x')
		print_places(numb, BASE_LOWER_HEXA, len_numb, flag);
	else if (flag->str[flag->pos_str] == 'X')
		print_places(numb, BASE_UPPER_HEXA, len_numb, flag);
	if (flag->presition > len_numb)
		len_numb = flag->presition;
	if (flag->width > len_numb)
	{
		flag->return_len += flag->width;
		len = flag->width - len_numb;
		while (len-- > 0)
			ft_putchar_fd(c, 1);
	}
	else
		flag->return_len += len_numb;
}

void	set_unsigned(va_list list, t_flags *flag)
{
	int	len;
	unsigned int numb;

	numb = va_arg(list, unsigned int);
	if (flag->str[flag->pos_str] == 'u')
		len = count_places(numb, BASE_DESC, flag);
	else if (flag->str[flag->pos_str] == 'x')
		len = count_places(numb, BASE_LOWER_HEXA, flag);
	else if (flag->str[flag->pos_str] == 'X')
		len = count_places(numb, BASE_UPPER_HEXA, flag);
	if (flag->zero && !flag->dot)
		print_aling_rigth('0', len, numb, flag);
	else if (flag->sinal)
		print_aling_left(' ', len, numb, flag);
	else
		print_aling_rigth(' ', len, numb, flag);
}