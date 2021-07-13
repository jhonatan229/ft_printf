/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:33:45 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/13 11:39:30 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_number(t_flags *flag)
{
	char	*str;
	int		start;

	start = flag->pos_str;
	while (ft_isdigit(flag->str[flag->pos_str]) != 0)
		flag->pos_str++;
	str = ft_substr(flag->str, start, flag->pos_str);
	if (flag->dot)
		flag->presition = ft_atoi(str);
	else
		flag->width = ft_atoi(str);
	flag->pos_str--;
	free(str);
}

static void	set_minus_zero(t_flags *flag)
{
	char	c;

	c = flag->str[flag->pos_str];
	while (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
	{
		if (flag->str[flag->pos_str] == '-')
			flag->sinal = 1;
		else if (flag->str[flag->pos_str] == '0')
			flag->zero = 1;
		else if (flag->str[flag->pos_str] == '+')
			flag->plus = 1;
		else if (flag->str[flag->pos_str] == ' ')
			flag->blank = 1;
		else if (flag->str[flag->pos_str] == '#')
			flag->hashtag = 2;
		flag->pos_str++;
		c = flag->str[flag->pos_str];
	}
	if (flag->plus)
		flag->sinal_int = '+';
	else if (flag->blank)
		flag->sinal_int = ' ';
	if (flag->sinal && flag->zero)
		flag->zero = 0;
}

static void	set_stars(t_flags *flag)
{
	if (flag->width < 0)
	{
		flag->sinal = 1;
		flag->width *= -1;
	}
	if (flag->presition < 0)
	{
		flag->dot = 0;
		flag->presition = 0;
	}
}

void	pupulate_flags(va_list list, t_flags *flag)
{
	set_minus_zero(flag);
	while (flag->str[flag->pos_str] != 0)
	{
		if (flag->str[flag->pos_str] == '.')
			flag->dot = 1;
		else if (flag->str[flag->pos_str] == '*')
		{
			if (flag->dot)
				flag->presition = va_arg(list, int);
			else
				flag->width = va_arg(list, int);
			set_stars(flag);
		}
		else if (ft_isdigit(flag->str[flag->pos_str]))
			get_number(flag);
		else
			break ;
		flag->pos_str++;
	}
}
