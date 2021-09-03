
#include "ft_printf.h"

void	sparehex_first(char *s, t_options *options)
{
	int n;

	if (options->precision > -1)
		options->zero = 0;
	if (options->width == 0 && options->precision == 0 && s[0] == '0')
		return ;
	else if ((options->width <= ft_strlen(s) && options->precision > ft_strlen(s)) || (!options->minus && s[0] == '0' && options->precision == options->width))
	{
		n = options->precision - ft_strlen(s);
		while (n--)
		{
			write(1, "0", 1);
			options->res++;
		}
	}
	else if (!options->zero && !options->minus && options->width > ft_strlen(s))
	{
		if (options->precision > options->width)
			n = options->precision - ft_strlen(s);
		else if (options->precision > ft_strlen(s) && options->precision < options->width)
			n = options->width - options->precision;
		else if (s[0] == '0' && !options->precision)
			n = options->width;
		else
			n = options->width - ft_strlen(s);
		while (n--)
		{
			write (1, options->precision >= options->width ? "0" : " ", 1);
			options->res += 1;
		}
		if (options->precision < options->width && options->precision > ft_strlen(s))
		{
			n = (options->precision) - ft_strlen(s);
			while ((n--) && options->res++)
					ft_putchar('0');
		}
	}
}

void	sparehex_sec(char *s, t_options *options)
{
	int	n;

	if (options->zero && !options->minus && options->width > ft_strlen(s) && options->precision <= ft_strlen(s))
	{
		n = options->width - ft_strlen(s);
		while (n-- && options->res++)
			write (1, "0", 1);
		options->zero = 0;
	}
	else if (options->minus && options->width > ft_strlen(s) && options->precision > ft_strlen(s))
	{
		n = options->precision - ft_strlen(s);
		while (n--)
		{
			write (1, "0", 1);
			options->res++;
		}
	}
	else if (options->zero && options->width > ft_strlen(s) && options->precision > ft_strlen(s))
	{
		n = options->width - options->precision;
		while(n-- && options->res++)
			write(1, " ", 1);
		n = options->precision - ft_strlen(s);
		while (n-- && options->res++)
			write(1, "0", 1);
	}
}

void	sparehex_third(char *s, t_options *options)
{
	int	n;

	if (options->minus && options->width > ft_strlen(s) && options->precision < options->width)
	{
		if (s[0] == '0' && options->precision == 0)
			n = options->width;
		else
			n = options->width - (options->precision > ft_strlen(s) ? options->precision : ft_strlen(s));
		while (n--)
		{
			write (1, " ", 1);
			options->res += 1;
		}
		options->zero = 0;
		options->minus = 0;
	}
	else if (options->zero && options->minus && options->width > ft_strlen(s))
	{
		n = options->width - ft_strlen(s);
		while (n--)
		{
			write (1, "0", 1);
			options->res += 1;
		}
	}
}

void	ft_putstr_hex(char *s, t_options *options)
{
	int	i;

	i = 0;
	sparehex_first(s, options);
	sparehex_sec(s, options);
	while (s[i])
		i++;
	write(1, s, (s[0] == '0' && !options->precision ? 0 : i));
	options->res += (s[0] == '0' && !options->precision ? 0 : i);
	if (s[0] == '0' && !options->precision && options->width == ft_strlen(s))
		while (options->width--  > 0)
		{
			write(1, " ", 1);
			options->res++;
		}
	sparehex_third(s, options);
	free(s);
}

void	ft_putnbr_hexlow_args(va_list args, t_options *options)
{
	unsigned int	n;

	n = va_arg(args, unsigned long int);
	ft_putstr_hex(ft_itoa_hexlow(n), options);
	initialize_struct(options);
}
