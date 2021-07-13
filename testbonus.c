/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:55:43 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/13 17:28:22 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
	int t;
	int p;
	
	//printf("1: %i\n", printf("bala%nmel", &t));
	//printf("t: %i\n", t);
	//printf("1: %i\n", ft_printf("bala%nmel", &p));
	//printf("p: %i\n", p);
	//printf("2: %i\n", printf("%s%n", "tripouille"));
	//printf("3: %i\n", printf("%s%n42", "tripouille"));
	//printf("4: %i\n", printf("%s%i%n42", "tripouille", INT_MAX));
	//printf("5: %i\n", printf("%s%i%n42", "tripouille", INT_MIN));
	//printf("6: %i\n", printf("%s%x%n42", "tripouille", LONG_MAX));
	//printf("7: %i\n", printf("%s%x%n42", "tripouille", LONG_MIN));
	//printf("8: %i\n", printf("%s%x%n42", "", 0));
	//printf("9: %i\n", printf("n%.s%x%n ", "42", -1));
	//printf("10: %i\n", printf("%%n%.s%x%n ", "42", -1));
	//printf("11: %i\n", printf("%%n%.s%p%n ", "42", (void*)1));
	//printf("12: %i\n", printf("%.s%n", "12345"));
	//printf("13: %i\n", printf("%s%c42%n", "12345", 0));
	//printf("14: %i\n", printf("%s%c%i42%n", "12345", 0, 42));
	//printf("15: %i\n", printf("%s%c42%n", "12345", 'A'));
	//printf("16: %i\n", printf("%s%d42%n", "12345", -42));
	//printf("17: %i\n", printf("%s%X42%n", "12345", 42));

	//printf("2: %i\n", printf(" %+2d ", 4523));
	//printf("2: %i\n", ft_printf(" %+2d ", 4523));
	//printf("3: %i\n", printf(" %+02d ", 1));
	//printf("3: %i\n", ft_printf(" %+02d ", 1));
	//printf("4: %i\n", printf(" %+-03d ", 0));
	//printf("4: %i\n", ft_printf(" %+-03d ", 0));
	//printf("5: %i\n", printf(" %+-03.d ", 0));
	//printf("5: %i\n", ft_printf(" %+-03.d ", 0));
	//printf("6: %i\n", printf(" %+-03.1d ", 0));
	//printf("6: %i\n", ft_printf(" %+-03.1d ", 0));
	//printf("7: %i\n", printf(" %+-03.2d ", 0));
	//printf("7: %i\n", ft_printf(" %+-03.2d ", 0));
	//printf("8: %i\n", printf(" %+d ", -1));
	//printf("8: %i\n", ft_printf(" %+d ", -1));
	//printf("21: %i\n", printf(" %+.d ", 0));
	//printf("21: %i\n", ft_printf(" %+.d ", 0));

	//printf("1: %i\n", printf(" |% d| ", 253));
	//printf("1: %i\n", ft_printf(" |% d| ", 253));
	//printf("2: %i\n", printf(" |% 2d| ", 253));
	//printf("2: %i\n", ft_printf(" |% 2d| ", 253));
	//printf("3: %i\n", printf(" |% 02d ", 0));
	//printf("3: %i\n", ft_printf(" |% 02d ", 0));
	//printf("4: %i\n", printf(" |% -03d ", 0));
	//printf("4: %i\n", ft_printf(" |% -03d ", 0));
	//printf("5: %i\n", printf(" |% -03.d ", 0));
	//printf("5: %i\n", ft_printf(" |% -03.d ", 0));
	//printf("6: %i\n", printf(" |% -03.1d ", 0));
	//printf("6: %i\n", ft_printf(" |% -03.1d ", 0));
	//printf("7: %i\n", printf(" |% -03.2d ", 0));
	//printf("7: %i\n", ft_printf(" |% -03.2d ", 0));
	//printf("8: %i\n", printf(" |% d ", -1));
	//printf("8: %i\n", ft_printf(" |% d ", -1));
	//printf("9: %i\n", printf(" % 2d ", -1));
	//printf("9: %i\n", ft_printf(" % 2d ", -1));
	//printf("10: %i\n", printf(" % 02d ", -1));
	//printf("10: %i\n", ft_printf(" % 02d ", -1));
	//printf("11: %i\n", printf(" % 03d ", -1));
	//printf("11: %i\n", ft_printf(" % 03d ", -1));
	//printf("12: %i\n", printf(" % -03d ", -1));
	//printf("12: %i\n", ft_printf(" % -03d ", -1));
	//printf("13: %i\n", printf(" % -03.d ", -1));
	//printf("13: %i\n", ft_printf(" % -03.d ", -1));
	//printf("14: %i\n", printf(" % -03.1d ", -1));
	//printf("14: %i\n", ft_printf(" % -03.1d ", -1));
	//printf("15: %i\n", printf(" % -03.2d ", -1));
	//printf("15: %i\n", ft_printf(" % -03.2d ", -1));
	//printf("16: %i\n", printf(" % -03.3d ", -1));
	//printf("16: %i\n", ft_printf(" % -03.3d ", -1));
	//printf("17: %i\n", printf(" % 03.3d ", -1));
	//printf("17: %i\n", ft_printf(" % 03.3d ", -1));
	//printf("18: %i\n", printf(" % 010.3d ", -1));
	//printf("19: %i\n", printf(" % -010.3d ", -1));
	//printf("20: %i\n", printf(" % -010.*d ", 42, -1));
	//printf("21: %i\n", printf(" % .d ", 0));
	//printf("22: %i\n", printf(" % .1d ", 0));
	//printf("23: %i\n", printf(" % .2d ", 0));


	printf("1: %i\n", printf(" %#x ", 0));
	printf("1: %i\n", ft_printf(" %#x ", 0));
	printf("2: %i\n", printf(" %#2x ", 0));
	printf("2: %i\n", ft_printf(" %#2x ", 0));
	printf("3: %i\n", printf(" %#02x ", 0));
	printf("3: %i\n", ft_printf(" %#02x ", 0));
	printf("4: %i\n", printf(" %#-03x ", 0));
	printf("4: %i\n", ft_printf(" %#-03x ", 0));
	printf("5: %i\n", printf(" %#-03.x ", 0));
	printf("5: %i\n", ft_printf(" %#-03.x ", 0));
	printf("6: %i\n", printf(" %#-03.1x ", 0));
	printf("6: %i\n", ft_printf(" %#-03.1x ", 0));
	printf("7: %i\n", printf(" %#-03.2x ", 0));
	printf("7: %i\n", ft_printf(" %#-03.2x ", 0));
	printf("8: %i\n", printf(" %#-03.*x ", 2, 0));
	printf("8: %i\n", ft_printf(" %#-03.*x ", 2, 0));
	printf("9: %i\n", printf(" %#X ", 235));
	printf("9: %i\n", ft_printf(" %#X ", 235));
	printf("10: %i\n", printf(" %#2x ", 1));
	printf("10: %i\n", ft_printf(" %#2x ", 1));
	printf("11: %i\n", printf(" %#02x ", 1));
	printf("11: %i\n", ft_printf(" %#02x ", 1));
	printf("12: %i\n", printf(" %#-03x ", 1));
	printf("12: %i\n", ft_printf(" %#-03x ", 1));
	printf("13: %i\n", printf(" %#-03.x ", 1));
	printf("13: %i\n", ft_printf(" %#-03.x ", 1));
	printf("14: %i\n", printf(" %#-03.1x ", 1));
	printf("14: %i\n", ft_printf(" %#-03.1x ", 1));
	printf("15: %i\n", printf(" %#-03.2x ", 1));
	printf("15: %i\n", ft_printf(" %#-03.2x ", 1));
	printf("16: %i\n", printf(" %#-03.*x ", 2, 1));
	printf("16: %i\n", ft_printf(" %#-03.*x ", 2, 1));
	printf("17: %i\n", printf("%#05x", 43));
	printf("17: %i\n", ft_printf("%#05x", 43));
	printf("17: %i\n", printf("%#08.5x", 34));
	printf("17: %i\n", ft_printf("%#08.5x", 34));
}