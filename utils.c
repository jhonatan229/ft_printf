/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:23:20 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/13 13:10:24 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	count_print_pointer(unsigned long int num, char *base, int sinal)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (num / len_base > 0)
		count += count_print_pointer(num / len_base, base, sinal);
	if (sinal == 1)
		ft_putchar_fd(base[num % len_base], 1);
	return (count);
}

int	count_unsigned(unsigned int num, char *base, t_flags *flag)
{
	int	count;
	int	len_base;

	len_base = ft_strlen(base);
	count = 1;
	if (flag->presition <= 0 && flag->dot && num == 0)
		return (0);
	if (num / len_base > 0)
		count += count_unsigned(num / len_base, base, flag);
	return (count);
}

int	count_print_int(int num, char *base, int sinal, int len_print)
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
			return (10);
		}
		num *= -1;
	}
	if (num / len_base > 0)
		count += count_print_int(num / len_base, base, sinal, len_print);
	if (count <= len_print && sinal == 1)
		ft_putchar_fd(base[num % len_base], 1);
	return (count);
}

void	set_diff_int(int mark, int diff, char c, char sinal)
{
	if (mark == 1)
		ft_putchar_fd(sinal, 1);
	while (diff-- > 0)
		ft_putchar_fd(c, 1);
	if (mark == 2)
		ft_putchar_fd(sinal, 1);
}
