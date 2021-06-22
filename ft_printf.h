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

int	ft_printf(const char *str, ...);
int pupulate_flags(t_flags *flag);

#endif
