#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = ft_strdup("abcdefghijklmnop");
	char	*o = ft_strdup("-a");
	char	*p = ft_strdup("-12");
	char	*q = ft_strdup("0");
	char	*r = ft_strdup("%%");
	char	*s = ft_strdup("-2147483648");
	char	*t = ft_strdup("0x12345678");
	char	*u = ft_strdup("-0");

	//printf("1: %i\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	//printf("1: %i\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	printf(" 2: %i\n", printf("%5%"));
	printf(" 2: %i\n", ft_printf("%5%"));
	printf(" 3: %i\n", printf("%-5%"));
	printf(" 3: %i\n", ft_printf("%-5%"));
	printf(" 4: %i\n", printf("%05%"));
	printf(" 4: %i\n", ft_printf("%05%"));
	printf(" 5: %i\n", printf("%-05%"));
	printf(" 5: %i\n", ft_printf("%-05%"));
	printf(" 6: %i\n", printf("%.3i", 13862));
	printf(" 6: %i\n", ft_printf("%.3i", 13862));
	printf(" 6: %i\n", printf("%.3i",-23646));
	printf(" 6: %i\n", ft_printf("%.3i",-23646));
	printf(" 7: %i\n", printf("%3.3d", 6983));
	printf(" 7: %i\n", ft_printf("%3.3d", 6983));
	printf(" 8: %i\n", printf("%3.3d", -8462));
	printf(" 8: %i\n", ft_printf("%3.3d", -8462));
	printf(" 9: %i\n", printf("%03.3d", 6983));
	printf(" 9: %i\n", ft_printf("%03.3d", 6983));
	printf(" 10: %i\n", printf("%03.3i", -8462));
	printf(" 10: %i\n", ft_printf("%03.3i", -8462));
	printf(" 11: %i\n", printf("%0-3.3i", 6983));
	printf(" 11: %i\n", ft_printf("%0-3.3i", 6983));
	printf(" 12: %i\n", printf("%0-3.3i", -8462));
	printf(" 12: %i\n\n", ft_printf("%0-3.3i", -8462));

	printf(" 13: %i\n", printf("%2.9p", 1234));
	printf(" 13: %i\n", ft_printf("%2.9p", 1234));
	printf("14: %i\n", printf("%.5p", 0));
	printf("14: %i\n", ft_printf("%.5p", 0));
	printf("15: %i\n", printf("%.0p", 0));
	printf("15: %i\n\n", ft_printf("%.0p", 0));
	
	printf(" 16: %i\n", printf("%*.*s", -7, -3, "yolo"));
	printf(" 16: %i\n", ft_printf("%*.*s", -7, -3, "yolo"));
	printf(" 17: %i\n", printf("%*i", -4, 94827));
	printf(" 17: %i\n", ft_printf("%*i", -4, 94827));

	free(n);
	free(o);
	free(p);
	free(q);
	free(r);
	free(s);
	free(t);
	free(u);
}