#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{

	printf("----------------------char---------------------------\n");
	printf("1: %i\n", printf("%c", '0'));
	printf("1: %i\n", ft_printf("%c", '0'));
	//printf("2: %i\n", printf(" %c ", '0'));
	//printf("3: %i\n", printf("10%c", '0'));
	//printf("4: %i\n", printf("%10c", '0'));
	//printf("5: %i\n", printf("-10%c", '0'));
	//printf("6: %i\n", printf("%-10c", '0'));
	//printf("7: %i\n", printf("%-10c", '0'));
	//printf("8: %i\n", printf("%*c", 1, '0'));
	//printf("9: %i\n", printf("%*c", 0, '0'));
	//printf("10: %i\n", printf("%*c", 2, '0'));
	//printf("11: %i\n", printf("%*c", -2, '0'));
	//printf("12: %i\n", printf("%*c", 0, '0'));
	//printf("13: %i\n", printf("%*c", 10, '0'));
	//printf("14: %i\n", printf("%*c", -10, '0'));
	//printf("15: %i\n", printf("%*c%*c", -10, '0', 10, '1'));
	//printf("16: %i\n", printf("*%c%*c", '0', 10, '1'));
	//printf("17: %i\n", printf("%*c%c*", -10, '0', '1'));
	//printf("18: %i\n", printf("%-10c*",'0'));
	//printf("19: %i\n", printf("%-10c%*c%c*",'0', 10, '1', '2'));
	//printf("20: %i\n", printf("%c%c%c*",'0', '1', '2'));
	//printf("21: %i\n", printf("%-c%-c%c*", 1, '0', 0));
	//printf("22: %i\n", printf("%c", '0' - 256));
	//printf("23: %i\n", printf("%c", '0' + 256));
	//printf("24: %i\n", printf("%c", 0));
	//printf("25: %i\n", printf("0%c", 0));
	//printf("26: %i\n", printf("%c", -129));
	//printf("27: %i\n", printf("%c", 128));
	//printf("28: %i\n", printf("%-*c", 10, '1'));
	//printf("29: %i\n", printf(" -%*c* -%-*c* ", -2, 0, 2, 0));
	//printf("30: %i\n", printf(" -%-*c* -%-*c* ", 2, 0, -2, 0));
	//printf("31: %i\n", printf(" -%*c* -%-*c* ", -1, 0, 1, 0));
	//printf("32: %i\n", printf(" -%-*c* -%-*c* ", 2, 0, -2, 0));
	//printf("33: %i\n", printf(" -%-2c* -%2c* ", 0, 0));


	//printf("------------------pointer------------------\n");
	//printf("5: %i\n", printf(" %p ", 17));
	//printf("6: %i\n", printf(" %10p %10p ", 1, -1));
	//printf("7: %i\n", printf(" %-10p %10p ", 1, -1));
	//printf("8: %i\n", printf(" %10p %-10p ", 1, -1));
	//printf("9: %i\n", printf(" %-10p %-10p ", 1, -1));
	//printf("10: %i\n", printf(" %10p %-10p ", 1, -1));
	//printf("11: %i\n", printf(" %p %p ", 1, -1));
	//printf("12: %i\n", printf(" %10p %-10p ", 0, 0));


	//printf("---------------strings-------------");
	//printf("1: %i\n", printf("%s", ""));
	//printf("1: %i\n", ft_printf("%s", ""));
	//printf("2: %i\n", printf("|%s|", "0"));
	//printf("3: %i\n", printf("%s %s", "", ""));
	//printf("3: %i\n", ft_printf("%s %s", "", ""));
	//printf("4: %i\n", printf("%s %s", "0", "1"));
	//printf("5: %i\n", printf(" %s %s ", "0", "1"));
	//printf("6: %i\n", printf(" %s %s ", "", ""));
	//printf("7: %i\n", printf(" %+1s %+1s ", "123", "4567"));
	//printf("8: %i\n", printf(" %4s %4s ", "123", "4567"));
	//printf("9: %i\n", printf(" %-4s %4s ", "123", "4567"));
	//printf("10: %i\n", printf(" %4ls %-4ls ", "123", "4567"));
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

	//printf("1: %i\n", printf(" %p ", -1));
	//printf("1: %i\n", ft_printf(" %p ", -1));
	//printf("2: %i\n", printf(" %p ", 1));
	//printf("2: %i\n", ft_printf(" %p ", 1));
	//printf("3: %i\n", printf(" %p ", 15));
	//printf("3: %i\n", ft_printf(" %p ", 15));
	//printf("4: %i\n", printf(" %p ", NULL));
	//printf("4: %i\n", ft_printf(" %p ", NULL));
	//printf("5: %i\n", printf(" %p ", 17));
	//printf("5: %i\n", ft_printf(" %p ", 17));
	//printf("6: %i\n", printf(" %10p %10p ", 1, -1));
	//printf("6: %i\n", ft_printf(" %10p %10p ", 1, -1));
	//printf("7: %i\n", printf(" %-10p %10p ", 1, -1));
	//printf("7: %i\n", ft_printf(" %-10p %10p ", 1, -1));
	//printf("8: %i\n", printf(" %10p %-10p ", 1, -1));
	//printf("8: %i\n", ft_printf(" %10p %-10p ", 1, -1));
	//printf("9: %i\n", printf(" %-10p %-10p ", 1, -1));
	//printf("9: %i\n", ft_printf(" %-10p %-10p ", 1, -1));
	//printf("10: %i\n", printf(" %10p %-10p ", 1, -1));
	//printf("10: %i\n", ft_printf(" %10p %-10p ", 1, -1));
	//printf("11: %i\n", printf(" %p %p ", 1, -1));
	//printf("11: %i\n", ft_printf(" %p %p ", 1, -1));
	//printf("12: %i\n", printf(" %10.p %-10p ", 0, 0));
	//printf("12: %i\n", ft_printf(" %10.p %-10p ", 0, 0));
	//printf("16: %i\n", printf(" %*p %-*p ", -10, 101, -10, 42));
	//printf("16: %i\n", ft_printf(" %*p %-*p ", -10, 101, -10, 42));
	//printf("17: %i\n", printf(" .-0*%*p %-*p*0-. ", 11, 101, 11, 42));
	//printf("17: %i\n", ft_printf(" .-0*%*p %-*p*0-. ", 11, 101, 11, 42));


	//printf("-----------------unsigned---------------\n")
	//printf("1: %i\n", printf(" %+u ", 23));
	//printf("1: %i\n", ft_printf(" %u ", 23));
	//printf("2: %i\n", printf(" %+.u ", 23));
	//printf("2: %i\n", ft_printf(" %.u ", 23));
	//printf("3: %i\n", printf(" %-+.2u ", 23));
	//printf("3: %i\n", ft_printf(" %-.2u ", 23));
	//printf("4: %i\n", printf(" %-2.0u ", 10));
	//printf("4: %i\n", ft_printf(" %-2.0u ", 10));
	//printf("5: %i\n", printf(" %-3.2u ", 0));
	//printf("5: %i\n", ft_printf(" %-3.2u ", 0));
	//printf("6: %i\n", printf(" %-3.2u %010.42u ", 0, 0));
	//printf("6: %i\n", ft_printf(" %-3.2u %010.42u ", 0, 0));
	//printf("7: %i\n", printf(" %-3.2u %10.42u ", 1, -1));
	//printf("7: %i\n", ft_printf(" %-3.2u %10.42u ", 1, -1));
	//printf("8: %i\n", printf(" %-3.2u %10.42u ", 10, -10));
	//printf("8: %i\n", ft_printf(" %-3.2u %10.42u ", 10, -10));
	//printf("9: %i\n", printf(" *%-*.*u* *%*.*u* ", 4, 5, 10, 10, 21, -10));
	//printf("10: %i\n", printf(" *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101));
	//printf("11: %i\n", printf(" *%*.*u* *%*.*u* ", -6, 2, 102, 10, 21, 101));
	//printf("12: %i\n", printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101));
	//printf("12: %i\n", ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101));
	//printf("13: %i\n", printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));
	//printf("13: %i\n", ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));
	//printf("14: %i\n", printf(" 0*%0-*u*0 0*%0*u*0 ", 21, 1021, 21, -1011));
	//printf("14: %i\n", ft_printf(" 0*%0-*u*0 0*%0*u*0 ", 21, 1021, 21, -1011));
	//printf("15: %i\n", printf(" 0*%-0*.10u*0 0*%-0*.0u*0 ", 21, 1021, 21, -1011));
	//printf("15: %i\n", ft_printf(" 0*%-0*.10u*0 0*%-0*.0u*0 ", 21, 1021, 21, -1011));
	//printf("16: %i\n", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));
	//printf("16: %i\n", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));
	//printf("17: %i\n", printf("%0-2.0u*0", 0));
	//printf("17: %i\n", ft_printf("%0-2.0u*0", 0));
	//printf("70: %i\n", printf("%.0u", 5));
	//printf("70: %i\n", ft_printf("%.0u", 5));
	//printf("71: %i\n", printf("%.0u", 10));
	//printf("71: %i\n", ft_printf("%.0u", 10));

	//printf("-----------------persent----------------\n");
	//printf("1: %i\n", printf(" %% "));
	//printf("1: %i\n", ft_printf(" %% "));
	//printf("2: %i\n", printf(" %%%% "));
	//printf("2: %i\n", ft_printf(" %%%% "));
	//printf("3: %i\n", printf(" %% %% %% "));
	//printf("3: %i\n", ft_printf(" %% %% %% "));
	//printf("4: %i\n", printf(" %%  %%  %% "));
	//printf("4: %i\n", ft_printf(" %%  %%  %% "));
	//printf("5: %i\n", printf(" %%   %%   %% "));
	//printf("5: %i\n", ft_printf(" %%   %%   %% "));
	//printf("6: %i\n", printf("%%"));
	//printf("7: %i\n", printf("%% %%"));


	//printf("----------------integer-----------------\n");
	//printf("1: %i\n", printf(" %+d ", 24));
	//printf("1: %i\n", ft_printf(" %+d ", 24));
	//printf("2: %i\n", printf(" %+.d ", 24));
	//printf("2: %i\n", ft_printf(" %+.d ", 24));
	//printf("3: %i\n", printf(" %-+.2d ", 24));
	//printf("3: %i\n", ft_printf(" %-+.2d ", 24));
	//printf("4: %i\n", printf(" %-2.2d ", 0));
	//printf("4: %i\n", ft_printf(" %-2.2d ", 0));
	//printf("5: %i\n", printf(" %-3.2d ", 1));
	//printf("5: %i\n", ft_printf(" %-3.2d ", 1));
	//printf("6: %i\n", printf(" %-3.2d %10.42d ", 0, 0));
	//printf("6: %i\n", ft_printf(" %-3.2d %10.42d ", 0, 0));
	//printf("7: %i\n", printf(" %-3.2d %10.42d ", 1, -1));
	//printf("7: %i\n", ft_printf(" %-3.2d %10.42d ", 1, -1));
	//printf("8: %i\n", printf(" %-3.2d %10.42d ", 10, -10));
	//printf("8: %i\n", ft_printf(" %-3.2d %10.42d ", 10, -10));
	//printf("9: %i\n", printf(" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10));
	//printf("9: %i\n", ft_printf(" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10));
	//printf("10: %i\n", printf(" *%-*.*d* *%*.*d* ", 6, 3, 10256, 10, 21, -101));
	//printf("10: %i\n", ft_printf(" *%-*.*d* *%*.*d* ", 6, 3, 10256, 10, 21, -101));
	//printf("11: %i\n", printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101));
	//printf("11: %i\n", ft_printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101));
	//printf("12: %i\n", printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101));
	//printf("12: %i\n", ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101));
	//printf("13: %i\n", printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101));
	//printf("13: %i\n", ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101));
	//printf("14: %i\n", printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011));
	//printf("14: %i\n", ft_printf(" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011));
	//printf("15: %i\n", printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011));
	//printf("15: %i\n", ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011));
	//printf("16: %i\n", printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1));
	//printf("16: %i\n", ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1));
	//printf("17: %i\n", printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, 2147483647, 21, -2147483648));
	//printf("17: %i\n", ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, 2147483647, 21, -2147483648));
	//printf("17: %i\n", printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	//printf("17: %i\n", ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	//printf("69: %i\n", printf("%.0d", 0));
	//printf("69: %i\n", ft_printf("%.0d", 0));
	//printf("70: %i\n", printf("%.0d", 5));
	//printf("69: %i\n", ft_printf("%.0d", 5));
	//printf("71: %i\n", printf("%.0d", 10));
	//printf("71: %i\n", ft_printf("%.0d", 10));
	//printf("72: %i\n", printf("%1.d", 0));
	//printf("72: %i\n", ft_printf("%1.d", 0));
	//printf("73: %i\n", printf("%2.d", 0));
	//printf("73: %i\n", ft_printf("%2.d", 0));
	//printf("74: %i\n", printf("%3.d", 0));
	//printf("74: %i\n", ft_printf("%3.d", 0));
	//printf("75: %i\n", printf("%1.1d", 0));
	//printf("75: %i\n", ft_printf("%1.1d", 0));
	//printf("76: %i\n", printf("%1.2d", 0));
	//printf("77: %i\n", printf("%1.3d", 0));
	//printf("78: %i\n", printf("%1.1d", 0));
	//printf("79: %i\n", printf("%2.2d", 0));
	//printf("80: %i\n", printf("%3.3d", 0));
	//printf("81: %i\n", printf("%3d", 0));
	//printf("82: %i\n", printf("%-3d", 0));
	//printf("83: %i\n", printf("%03d", 0));
	//printf("84: %i\n", printf("%0*d", -7, -54));
}