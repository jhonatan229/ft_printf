/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:30:40 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/14 15:20:39 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	align_str(char *str, t_flags *flag)
{
	int	len;

	len = ft_strlen(str);
	if (flag->sinal)
	{
		ft_putstr_fd(str, 1);
		while (len++ < flag->width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	len = flag->width - ft_strlen(str);
	if (flag->zero)
		while (len-- > 0)
			ft_putchar_fd('0', 1);
	else
		while (len-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	return ;
}

static void	print_str(char *str, t_flags *flag)
{
	if (flag->width > (int)ft_strlen(str))
	{
		flag->return_len += flag->width;
		align_str(str, flag);
	}
	else
	{
		flag->return_len += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
}

void	set_string(va_list list, t_flags *flag)
{
	char	*str;
	char	*aux;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		if (flag->dot)
		{
			aux = ft_substr(str, 0, flag->presition);
			free(str);
			str = aux;
		}	
	}	
	else if (flag->dot)
		str = ft_substr(str, 0, flag->presition);
	else
		str = ft_strdup(str);
	print_str(str, flag);
	free(str);
}
