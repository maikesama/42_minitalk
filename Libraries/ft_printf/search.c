
#include "ft_printf.h"

void	search_flag_one(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == '-' || str[options->it] == '0')
	{
		if (str[options->it] == '-')
			options->minus = 1;
		else
			options->zero = 1;
		options->it++;
	}
	if (str[options->it] == '0' || str[options->it] == '-')
	{
		if (str[options->it] == '0') 
			options->zero = 1;
		else
			options->minus = 1;
		if (options->minus == 1)
			options->zero = 0;
		options->it++;
	}
	if (str[options->it] == '*')
	{
		options->width = va_arg(ap, int);
		if (options->width < 0)
		{
			options->minus = 1;
			options->zero = 0;
			options->width *= -1;
		}
		options->it++;
	}
}

void	search_flag_two(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] >= '1' && str[options->it] <= '9')
	{
		wid_conversion(str, options->it, options);
		while (str[options->it] >= '0' && str[options->it] <= '9')
			options->it++;
	}
	if (str[options->it] == '.')
	{
		options->it++;
		if (str[options->it] == '*')
		{
			options->precision = va_arg(ap, int);
			options->it++;
		}
		else if (str[options->it] >= '0' && str[options->it] <= '9')
			prec_conversion(str, options->it, options);
		else
			options->precision = 0;
		while (str[options->it] >= '0' && str[options->it] <= '9')
			options->it++;
	}
}

int search_char_one(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == '%')
	{
		ft_putperc('%', options);
		options->it++;
		return (1);
	}
	else if (str[options->it] == 'c')
	{
		ft_putchar_args(ap, options);
		options->it++;
		return (1);			
	}
	else if (str[options->it] == 's')
	{	
		ft_putstr_args(ap, options);
		options->it++;
		return (1);
	}
	else if (str[options->it] == 'd' || str[options->it] == 'i')
	{
		ft_putnbr_args(ap, options);
		options->it++;
		return (1);		
	}
	return (0);
}

void	search_char_two(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == 'u')
	{
		ft_putnbr_unsigned_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'X')
	{
		ft_putnbr_hex_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'x')
	{
		ft_putnbr_hexlow_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'p')
	{
		put_memadd_arg(ap, options);
		options->it++;
	}
}