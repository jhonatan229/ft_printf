#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	ft_printf("----------------------------------------decimal_signed_integer---------------------------------------------\n");
	ft_printf("\n");
	int hex_neg = 0x2a;
	
	ft_printf("%-60s: |%d|","format identifier", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%d|","(hex) format identifier", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%-3d|", "with minimum field (3) width", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%5d|", "with minimum field (5) width", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%05d|", "with minimum field (5) width and 0 padding", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%5.3d|", "minimum field (5) width with 0's", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-5d|", "minimum field (5) left align", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%5.1d|", "precision (1) and minimum (5) field", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%.3d|", "precision (3) field", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%-.5d|", "precision (5) field left align", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%10.5d|", "minimum (10) and precision (5) field", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-10.5d|", "minimum (10) and precision (5) field left align", 42);
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*d|", "minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	ft_printf("\n");

	ft_printf("----------------------------------------original decimal_signed_integer---------------------------------------------\n");
	ft_printf("\n");
	
	printf("%-60s: |%d|","format identifier", 42);
	printf("\n");
	printf("%-60s: |%d|","(hex) format identifier", hex_neg);
	printf("\n");
	printf("%-60s: |%-3d|", "with minimum field (3) width", 42);
	printf("\n");
	printf("%-60s: |%5d|", "with minimum field (5) width", 42);
	printf("\n");
	printf("%-60s: |%05d|", "with minimum field (5) width and 0 padding", 42);
	printf("\n");
	printf("%-60s: |%5.3d|", "minimum field (5) width with 0's", 42);
	printf("\n");
	printf("%-60s: |%-5d|", "minimum field (5) left align", 42);
	printf("\n");
	printf("%-60s: |%5.1d|", "precision (1) and minimum (5) field", 42);
	printf("\n");
	printf("%-60s: |%.3d|", "precision (3) field", hex_neg);
	printf("\n");
	printf("%-60s: |%-.5d|", "precision (5) field left align", hex_neg);
	printf("\n");
	printf("%-60s: |%10.5d|", "minimum (10) and precision (5) field", 42);
	printf("\n");
	printf("%-60s: |%-10.5d|", "minimum (10) and precision (5) field left align", 42);
	printf("\n");
	printf("%-60s: |%-*.*d|", "minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	printf("\n");

	ft_printf("-----------------------------------------------integer--------------------------------------------------------\n");
	ft_printf("\n");
	ft_printf("%-60s: |%i|","format identifier", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%20i|", "with minimum field (20) width", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%020i|", "minimum field (20) width with 0's", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-20i|", "minimum field (20) left align", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%20.1i|", "precision (1) and minimum (20) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%.1i|", "precision (1) field", -42);
	ft_printf("\n");
	ft_printf("%-60s: |%-.1i|", "(hex_neg) precision (1) field left align", hex_neg);
	ft_printf("\n");
	ft_printf("%-60s: |%020.10i|", "minimum (20) and precision (10) field", -12345678);
	ft_printf("\n");
	ft_printf("%-60s: |%-20.10i|", "minimum (20) and precision (10) field left align", -12345678);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*i|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	ft_printf("\n");

	printf("-----------------------------------------------original integer--------------------------------------------------------\n");
	printf("\n");
	printf("%-60s: |%i|","format identifier", -42);
	printf("\n");
	printf("%-60s: |%20i|", "with minimum field (20) width", -42);
	printf("\n");
	printf("%-60s: |%020i|", "minimum field (20) width with 0's", -42);
	printf("\n");
	printf("%-60s: |%-20i|", "minimum field (20) left align", -42);
	printf("\n");
	printf("%-60s: |%20.1i|", "precision (1) and minimum (20) field", -42);
	printf("\n");
	printf("%-60s: |%.1i|", "precision (1) field", -42);
	printf("\n");
	printf("%-60s: |%-.1i|", "(hex_neg) precision (1) field left align", hex_neg);
	printf("\n");
	printf("%-60s: |%020.10i|", "minimum (20) and precision (10) field", -12345678);
	printf("\n");
	printf("%-60s: |%-20.10i|", "minimum (20) and precision (10) field left align", -12345678);
	printf("\n");
	printf("\n");
	printf("%-60s: |%-*.*i|", "(hex_neg) minimum (20) and precision (1) field left align", 20, 1, hex_neg);
	printf("\n");
	return (0);
}