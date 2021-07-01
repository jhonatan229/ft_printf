/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:30:40 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/01 15:48:58 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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

void	set_string(va_list list, t_flags *flag)
{
	char	*str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = ft_strdup("");
	if (flag->dot)
		str = ft_substr(str, 0, flag->presition);
	else
		str = ft_strdup(str);
	if (flag->width > ft_strlen(str))
	{
		flag->return_len += flag->width;
		align_str(str, flag);
	}
	else
	{
		flag->return_len += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	free(str);
}
