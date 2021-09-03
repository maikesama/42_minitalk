#include "ft_printf.h"

int		min(int i, t_options *option)
{
	if (i >= option->precision)
		return (option->precision);
	return (i);
}

void	sparestr_first(char *s, t_options *options)
{
	int n;

	if (!(options->zero) && !(options->minus) && options->width > ft_strlen(s))
	{
		n = options->width - (options->precision != -1 ? min(ft_strlen(s), options) : ft_strlen(s));
		while (n--)
		{
			write (1, " ", 1);
			options->res += 1;
		}
		options->width = 0;
	}
	else if ((options->zero) && !(options->minus) && options->width > ft_strlen(s))
	{
		n = options->width - (options->precision != -1 ? min(ft_strlen(s), options) : ft_strlen(s));
		while (n--)
		{
			write (1, "0", 1);
			options->res += 1;
		}
		options->zero = 0;
		options->width = 0;
	}
	else if (!options->minus && options->precision > -1 && options->width > options->precision)
	{
		while ((options->width--) - options->precision > 0)
		{
			write(1, (!options->zero ? " " : "0"), 1);
			options->res += 1;
		}
		options->zero = 0;
	}
}

void sparestr_sec(char *s, t_options *options)
{
	int n;

	if (!(options->zero) && (options->minus) && options->width > ft_strlen(s))
	{
		n = options->width - (options->precision != -1 ? min(ft_strlen(s), options) : ft_strlen(s));
		while (n--)
		{
			write (1, " ", 1);
			options->res += 1;
		}
		options->minus = 0;
	}
	else if ((options->zero) && (options->minus) && options->width > ft_strlen(s))
	{
		n = options->width - (options->precision != -1 ? min(ft_strlen(s), options) : ft_strlen(s));
		while (n--)
		{
			write (1, "0", 1);
			options->res += 1;
		}
		options->minus = 0;
		options->zero = 0;
	}
	else if (options->minus && options->precision > -1 && options->width > options->precision)
	{
		while ((options->width--) - options->precision > 0)
		{
			write(1, (!options->zero ? " " : "0"), 1);
			options->res += 1;
		}
		options->zero = 0;
	}
}

void	ft_putstr_args(va_list args, t_options *options)
{
	int					i;
	char				*s;

	s = va_arg(args, char *);
	i = 0;
	if (!s)
	{
		sparestr_first("(null)", options);
		write(1, "(null)", (options->precision > -1 ? min(6, options) : 6));
		options->res += (options->precision > -1 ? min(6, options) : 6);
		sparestr_sec("(null)", options);
		initialize_struct(options);
		return ;
	}
	sparestr_first(s, options);
	while (s[i])
		i++;
	write(1, s, (options->precision > -1 ? min(i, options) : i));
	options->res += (options->precision > -1 ? min(i, options) : i);
	sparestr_sec(s, options);
	initialize_struct(options);
}