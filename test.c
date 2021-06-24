#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	ft_printf("comendo peixe |%*c| camarão\n", 20, 'P');
	ft_printf("\n");
	ft_printf("%-60s: |%s|","format identifier", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%20s|", "with minimum field (20) width", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%-20s|", "minimum field (20) left align", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%-20s|", "minimum field (20) left align", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%.8s|", "precision (8) field", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%-.8s|", "precision (8) field left align", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%20.8s|", "minimum (20) and precision (8) field", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%-20.8s|", "minimum (20) and precision (8) field left align", "quarenta e dois");
	ft_printf("\n");
	ft_printf("%-60s: |%-*.*s|", "minimum (20) and precision (8) field left align", 20, 8, "quarenta e dois");
	ft_printf("\n");
	return (0);
}