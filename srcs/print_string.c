/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:30:40 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/16 17:41:29 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//align str depending of the flags that are ON
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

//verify if will need print something more than "str"
static void	print_str(char *str, t_flags *flag)
{
	//will align the str if the width is bigger than length of "str"
	//if true, add width in the return length
	if (flag->width > (int)ft_strlen(str))
	{
		flag->return_len += flag->width;
		align_str(str, flag);
	}
	//otherwise, add the length of str in return_len and print str
	else
	{
		flag->return_len += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
}

//will print a string, depending on my flags turned on.
void	set_string(va_list list, t_flags *flag)
{
	char	*str;
	char	*aux;

	str = va_arg(list, char *);
	//case the variable passed on printf is NULL, will be create a string with "(null)" writed
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		//if there is precision, use substr for create another string with the length of precision (if is smaller than 6)
		if (flag->dot)
		{
			aux = ft_substr(str, 0, flag->precision);
			free(str);
			str = aux;
		}	
	}
	//otherwise if there is precision, use substr for create another string with the length of precision (if is smaller than length of the string)
	else if (flag->dot)
		str = ft_substr(str, 0, flag->precision);
	//otherwise put in "str" the value of variable received
	else
		str = ft_strdup(str);
	print_str(str, flag);
	free(str);
}
