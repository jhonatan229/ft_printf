/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:55:43 by jestevam          #+#    #+#             */
/*   Updated: 2021/07/07 15:29:09 by jestevam         ###   ########.fr       */
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
	ft_putchar_fd('', 1);
	printf("1: %i\n", printf("bala%nmel", &t));
	printf("t: %i\n", t);
	printf("1: %i\n", ft_printf("bala%nmel", &p));
	printf("p: %i\n", p);
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
}