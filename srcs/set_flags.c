/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:33:45 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 18:43:58 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//transform the number "str" in a integer
//already populate flag width or precision depending if flag dot is on or not 
static void	get_number(t_flags *flag)
{
	char	*str;
	int		start;

	start = flag->pos_str;
	while (ft_isdigit(flag->str[flag->pos_str]) != 0)
		flag->pos_str++;
	str = ft_substr(flag->str, start, flag->pos_str);
	if (flag->dot)
		flag->precision = ft_atoi(str);
	else
		flag->width = ft_atoi(str);
	flag->pos_str--;
	free(str);
}

//set the front flags
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
	//will put a char of the signal if flag plus or blank is on
	//plus have priority
	if (flag->plus)
		flag->sinal_int = '+';
	else if (flag->blank)
		flag->sinal_int = ' ';
	//between flag '-' or '0', the '-' is priority
	if (flag->sinal && flag->zero)
		flag->zero = 0;
}

//will transform the width in positive if needed,
//and precision in 0 if needed
static void	set_stars(t_flags *flag)
{
	//if width is smaller than 0, the flag sinal turn on
	//width turn positive
	if (flag->width < 0)
	{
		flag->sinal = 1;
		flag->width *= -1;
	}
	//if precision is smaller than 0, the flag dot turn off
	//precision turn 0;
	if (flag->precision < 0)
	{
		flag->dot = 0;
		flag->precision = 0;
	}
}

//will put in my struct "flag", the flags that appears
void	pupulate_flags(va_list list, t_flags *flag)
{
	set_minus_zero(flag);
	//percour the string "str" and going add on the struct the characters '.' and the numbers that appears
	while (flag->str[flag->pos_str] != 0)
	{
		if (flag->str[flag->pos_str] == '.')
			flag->dot = 1;
		//this '*' will be convert by a number that coming in the parameter of the printf
		else if (flag->str[flag->pos_str] == '*')
		{
			if (flag->dot)
				flag->precision = va_arg(list, int);
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
