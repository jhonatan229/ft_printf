#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("----------original------------\n");
    printf("original print:  %c\n", '0');
	ft_printf("my print:        %c\n", '0');
	printf("original print:  %c \n", '0');
	ft_printf("my print:        %c \n", '0');
	printf("original print:  10%c\n", '0');
	ft_printf("my print:        10%c\n", '0');
	printf("original print:  %10c\n", '0');
	ft_printf("my print:        %10c\n", '0');
	printf("original print:  -10%c\n", '0');
	ft_printf("my print:        -10%c\n", '0');
	printf("original print:  %-10c\n", '0');
	ft_printf("my print:        %-10c\n", '0');
	printf("original print:  %*c\n", 1, '0');
	ft_printf("my print:        %*c\n", 1, '0');
	printf("original print:  %*c\n", 0, '0');
	ft_printf("my print:        %*c\n", 0, '0');
	printf("original print:  %*c\n", 2, '0');
	ft_printf("my print:        %*c\n", 2, '0');
	printf("original print:  %*c\n", -2, '0');
	ft_printf("my print:        %*c\n", -2, '0');
	printf("original print:  %*c\n", 0, '0');
	ft_printf("my print:        %*c\n", 0, '0');
	printf("original print:  %*c\n", 10, '0');
	ft_printf("my print:        %*c\n", 10, '0');
	printf("original print:  %*c\n", -10, '0');
	ft_printf("my print:        %*c\n", -10, '0');
	printf("original print:  %*c%*c\n", -10, '0', 10, '1');
	ft_printf("my print:        %*c%*c\n", -10, '0', 10, '1');
	printf("original print:  *%c%*c\n", '0', 10, '1');
	ft_printf("my print:        *%c%*c\n", '0', 10, '1');
	printf("original print:  %*c%c*\n", -10, '0', '1');
	ft_printf("my print:        %*c%c*\n", -10, '0', '1');
	printf("original print:  %-10c*\n",'0');
	ft_printf("my print:        %-10c*\n",'0');
	printf("original print:  %-10c%*c%c*\n",'0', 10, '1', '2');
	ft_printf("my print:        %-10c%*c%c*\n",'0', 10, '1', '2');
	printf("original print:  %c%c%c*\n",'0', '1', '2');
	ft_printf("my print:        %c%c%c*\n",'0', '1', '2');
	printf("original print:  %-c%-c%c*\n", 1, '0', 0);
	ft_printf("my print:        %-c%-c%c*\n", 1, '0', 0);
	printf("original print:  %c\n", '0' - 256);
	ft_printf("my print:        %c\n", '0' - 256);
	printf("original print:  %c\n", '0' + 256);
	ft_printf("my print:        %c\n", '0' + 256);
	printf("original print:  %c\n", 0);
	ft_printf("my print:        %c\n", 0);
	printf("original print:  0%c\n", 0);
	ft_printf("my print:        0%c\n", 0);
	printf("original print:  %c\n", -129);
	ft_printf("my print:        %c\n", -129);
	printf("original print:  %c\n", 128);
	ft_printf("my print:        %c\n", 128);
	printf("original print:  %-*c\n", 10, '1');
	ft_printf("my print:        %-*c\n", 10, '1');
	printf("original print:  -%*c* -%-*c* \n", -2, 0, 2, 0);
	ft_printf("my print:        -%*c* -%-*c* \n", -2, 0, 2, 0);
	printf("original print:  -%-*c* -%-*c* \n", 2, 0, -2, 0);
	ft_printf("my print:        -%-*c* -%-*c* \n", 2, 0, -2, 0);
	printf("original print:  -%*c* -%-*c* \n", -1, 0, 1, 0);
	ft_printf("my print:        -%*c* -%-*c* \n", -1, 0, 1, 0);
	printf("original print:  -%-*c* -%-*c* \n", 2, 0, -2, 0);
	ft_printf("my print:        -%-*c* -%-*c* \n", 2, 0, -2, 0);
	printf("original print:  -%-2c* -%2c* \n", 0, 0);
	ft_printf("my print:        -%-2c* -%2c* \n", 0, 0);
}