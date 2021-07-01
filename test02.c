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

	printf("1: %i\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	printf("1: %i\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	printf("1: %i\n", printf("%1i", j));
	printf("1: %i\n", ft_printf("%1i", j));
 //j, k, l, m, c, e, d
	free(n);
	free(o);
	free(p);
	free(q);
	free(r);
	free(s);
	free(t);
	free(u);
}