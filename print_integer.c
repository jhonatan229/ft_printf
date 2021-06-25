/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:16:33 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/25 14:08:29 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static void	negative_str(char *str, char *buf, int pres, int count)
{
	int	len;

	buf[0] = '-';
	len = (pres - (ft_strlen(str) - 1));
	while (count < len + 1)
		buf[count++] = '0';
	while (count < pres + 1)
	{
		str++;
		buf[count++] = *str;
	}
}

static void	zero_str(char *str, char *buf, int pres, int count)
{
	int	len;

	if (count == 1)
		buf[0] = '-';
	len = (pres - ft_strlen(str));
	while (count < len + 1)
		buf[count++] = '0';
	while (count < pres)
	{
		str++;
		buf[count++] = *str;
	}
}

static char	*modify_str_pres(int count, char *str, int pres, t_flags *flag)
{
	char	*buf;
	int		len;

	buf = ft_calloc(pres + 1, sizeof(int));
	if (buf == NULL)
		return (NULL);
	if (count == 1)
	{
		if (flag->zero && !flag->dot)
			zero_str(str, buf, pres, count);
		else
			negative_str(str, buf, pres, count);
	}
	else
	{
		len = (pres - ft_strlen(str));
		while (count < len)
			buf[count++] = '0';
		while (count < pres)
		{
			buf[count++] = *str;
			str++;
		}
	}	
	return (buf);
}

static char	*set_presition(va_list list, t_flags *flag)
{
	char	*str;
	int		point;

	point = 0;
	if (flag->str[flag->pos_str] == 'u')
		str = ft_itoa(va_arg(list, unsigned int));
	else
		str = ft_itoa(va_arg(list, int));
	if (str[0] == '-')
	{
		point = 1;
		if (flag->presition > (ft_strlen(str) - 1))
			return (modify_str_pres(point, str++, flag->presition, flag));
		else if (flag->zero == 1 && flag->dot == 0)
			return (modify_str_pres(point, str++, flag->width, flag));
		return (str);
	}
	else if (flag->presition > ft_strlen(str))
		return (modify_str_pres(point, str, flag->presition, flag));
	else if (flag->zero && flag->dot == 0)
		return (modify_str_pres(point, str, flag->width, flag));
	return (str);
}

void	set_integer(va_list list, t_flags *flag)
{
	char	*str;
	int		len;

	str = set_presition(list, flag);
	len = ft_strlen(str);
	if (flag->sinal)
	{
		if (flag->width > ft_strlen(str))
		{
			ft_putstr_fd(str, 1);
			while (len++ < flag->width)
				ft_putchar_fd(' ', 1);
			return ;
		}
	}		
	if (flag->width > len)
	{
		len = flag->width - ft_strlen(str);
		while (len-- != 0)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
	}
	else
		ft_putstr_fd(str, 1);
	free(str);
}
