#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	//int		a = -4;
	//int		b = 0;
	//char	c = 'a';
	//int		d = 2147483647;
	//int		e = -2147483648;
	//int		f = 42;
	//int		g = 25;
	//int		h = 4200;
	//int		i = 8;
	//int		j = -12;
	//int		k = 123456789;
	//int		l = 0;
	//int		m = -12345678;
	//char	*n = ft_strdup("abcdefghijklmnop");
	//char	*o = ft_strdup("-a");
	//char	*p = ft_strdup("-12");
	//char	*q = ft_strdup("0");
	//char	*r = ft_strdup("%%");
	//char	*s = ft_strdup("-2147483648");
	//char	*t = ft_strdup("0x12345678");
	//char	*u = ft_strdup("-0");
//
	////printf("1: %i\n", printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	////printf("1: %i\n", ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d));
	//printf(" 2: %i\n", printf("%5%"));
	//printf(" 2: %i\n", ft_printf("%5%"));
	//printf(" 3: %i\n", printf("%-5%"));
	//printf(" 3: %i\n", ft_printf("%-5%"));
	//printf(" 4: %i\n", printf("%05%"));
	//printf(" 4: %i\n", ft_printf("%05%"));
	//printf(" 5: %i\n", printf("%-05%"));
	//printf(" 5: %i\n", ft_printf("%-05%"));
	//printf(" 6: %i\n", printf("%.3i", 13862));
	//printf(" 6: %i\n", ft_printf("%.3i", 13862));
	//printf(" 6: %i\n", printf("%.3i",-23646));
	//printf(" 6: %i\n", ft_printf("%.3i",-23646));
	//printf(" 7: %i\n", printf("%3.3d", 6983));
	//printf(" 7: %i\n", ft_printf("%3.3d", 6983));
	//printf(" 8: %i\n", printf("%3.3d", -8462));
	//printf(" 8: %i\n", ft_printf("%3.3d", -8462));
	//printf(" 9: %i\n", printf("%03.3d", 6983));
	//printf(" 9: %i\n", ft_printf("%03.3d", 6983));
	//printf(" 10: %i\n", printf("%03.3i", -8462));
	//printf(" 10: %i\n", ft_printf("%03.3i", -8462));
	//printf(" 11: %i\n", printf("%0-3.3i", 6983));
	//printf(" 11: %i\n", ft_printf("%0-3.3i", 6983));
	//printf(" 12: %i\n", printf("%0-3.3i", -8462));
	//printf(" 12: %i\n\n", ft_printf("%0-3.3i", -8462));
//
	//printf(" 13: %i\n", printf("%2.9p", 1234));
	//printf(" 13: %i\n", ft_printf("%2.9p", 1234));
	//printf("14: %i\n", printf("%.5p", 0));
	//printf("14: %i\n", ft_printf("%.5p", 0));
	//printf("15: %i\n", printf("%.0p", 0));
	//printf("15: %i\n\n", ft_printf("%.0p", 0));
	//
	//printf(" 16: %i\n", printf("%*.*s", -7, -3, "yolo"));
	//printf(" 16: %i\n", ft_printf("%*.*s", -7, -3, "yolo"));
	//printf(" 17: %i\n", printf("%*i", -4, 94827));
	//printf(" 17: %i\n", ft_printf("%*i", -4, 94827));
//
	//free(n);
	//free(o);
	//free(p);
	//free(q);
	//free(r);
	//free(s);
	//free(t);
	//free(u);

	printf("1: %i\n", printf("%5.p", NULL));
	printf("1: %i\n", ft_printf("%5.p", NULL));
	printf("2: %i\n", printf("-->|%-16.p|<-- ", NULL));
	printf("2: %i\n", ft_printf("-->|%-16.p|<-- ", NULL));
	printf("3: %i\n", printf("%p", NULL));
	printf("3: %i\n", ft_printf("%p", NULL));
	printf("4: %i\n", printf("%.0p", 0));
	printf("4: %i\n", ft_printf("%.0p", 0));
	//printf("4: %i\n", printf("|%020.18i|%013.9i|%-8X|%---45.36X|" ,-1748967713,-1568187420,124888334u,2293430389u));
	//printf("4: %i\n", ft_printf("|%020.18i|%013.9i|%-8X|%---45.36X|" ,-1748967713,-1568187420,124888334u,2293430389u));
	//printf("5: %i\n", printf("%--40.183X%-178.81X%036.192u%-119.27s" ,2684215029u,410939004u,2169426684u,"!ufvJeVr`+BF#EV"));
	//printf("5: %i\n", ft_printf("%--40.183X%-178.81X%036.192u%-119.27s" ,2684215029u,410939004u,2169426684u,"!ufvJeVr`+BF#EV"));
	//printf("6: %i\n", printf("%098.58d%--7.168d" ,549613177,850697743));
	//printf("6: %i\n", ft_printf("%098.58d%--7.168d" ,549613177,850697743));
	//printf("7: %i\n", printf(" %1s %1s ", "123", "4567"));
	//printf("8: %i\n", printf(" %4s %4s ", "123", "4567"));
	//printf("9: %i\n", printf(" %-4s %4s ", "123", "4567"));
	//printf("10: %i\n", printf(" %4s %-4s ", "123", "4567"));
	//printf("11: %i\n", printf(" %-4s %-4s ", "123", "4567"));
	//printf("12: %i\n", printf(" %-4s %-4s ", "123", "4567"));
	//printf("13: %i\n", printf(" %*s %*s ", 1, "123", 10, "4567"));
	//printf("14: %i\n", printf(" *%s %*s ", "123", 10, "4567"));
	//printf("15: %i\n", printf(" %*s %s ", 10, "123", "4567"));
	//printf("16: %i\n", printf(" %*.s %.1s ", 10, "123", "4567"));
	//printf("16: %i\n", ft_printf(" %*.s %.1s ", 10, "123", "4567"));
	//printf("17: %i\n", printf(" %*.0s %.2s ", 10, "123", "4567"));
	//printf("18: %i\n", printf(" %*.3s %.3s ", 10, "123", "4567"));
	//printf("19: %i\n", printf(" %*.4s %.4s ", 10, "123", "4567"));
	//printf("20: %i\n", printf(" %*.5s %.5s ", 10, "123", "4567"));
	//printf("21: %i\n", printf(" %*.5s %*.5s ", 10, "123", 10, "4567"));
	//printf("22: %i\n", printf(" %*.5s %*.5s ", -10, "123", 10, "4567"));
	//printf("23: %i\n", printf(" %*.5s %*.5s ", 10, "123", -10, "4567"));
	//printf("24: %i\n", printf(" %*.5s %*.5s ", -10, "123", -10, "4567"));
	//printf("25: %i\n", printf(" %10.s %1.s ", "123", "4567"));
	//printf("26: %i\n", printf(" %0.s %0.s ", "123", "4567"));
	//printf("27: %i\n", printf(" %.s %.s ", "123", "4567"));
	//printf("28: %i\n", printf(" %3.3s %3.3s ", "123", "4567"));
	//printf("29: %i\n", printf(" %4.3s %-4.3s ", "123", "4567"));
	//printf("30: %i\n", printf("%.s", ""));
	//printf("31: %i\n", printf("%.0s", ""));
	//printf("32: %i\n", printf("%.1s", ""));
	//printf("33: %i\n", printf(" %4.2s %-4.2s ", "123", "4567"));
	//printf("34: %i\n", printf(" %-3.s ", NULL));
	//printf("34: %i\n", ft_printf(" %-3.s ", NULL));
	//printf("35: %i\n", printf(" |%-9.3s| ", NULL));
	//printf("35: %i\n", ft_printf(" |%-9.3s| ", NULL));
	//printf("36: %i\n", printf(" %.*s ", 0, NULL));
	//printf("36: %i\n", ft_printf(" %.*s ", 0, NULL));
}