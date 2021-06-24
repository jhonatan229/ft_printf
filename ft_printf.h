#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef	struct	s_ft_printf
{
	char	*str;
	int		pos_str;
	int		width;
	int		presition;
	int		sinal;
	int		dot;
	int		zero;
}				t_flags;

int		ft_printf(const char *str, ...);
int		pupulate_flags(va_list list, t_flags *flag);
void	set_char(va_list list, t_flags *flag);
void	set_string(va_list list, t_flags *flag);

#endif
