#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BASE_DESC "0123456789"
# define BASE_LOWER_HEXA "0123456789abcdef"
# define BASE_UPPER_HEXA "0123456789ABCDEF"

typedef struct s_ft_printf
{
	char	*str;
	int		pos_str;
	int		width;
	int		presition;
	int		sinal;
	int		dot;
	int		zero;
	int		return_len;
}				t_flags;

int		ft_printf(const char *str, ...);
void	pupulate_flags(va_list list, t_flags *flag);
void	set_char(va_list list, t_flags *flag);
void	set_string(va_list list, t_flags *flag);
void	set_integer(va_list list, t_flags *flag);
void	set_unsigned(va_list list, t_flags *flag);
void	set_pointer(va_list list, t_flags *flag);
int		count_print_pointer(unsigned long int num, char *base, int sinal);
int		count_unsigned(unsigned int num, char *base, t_flags *flag);
int		count_print_int(int num, char *base, int sinal, int len_print);

#endif
