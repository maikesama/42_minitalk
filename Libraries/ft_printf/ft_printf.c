#include "ft_printf.h"

void	wid_conversion(const char *str, int start, t_options *options)
{	
	options->width = ft_atoi_flag(str, start);
}

void	prec_conversion(const char *str, int start, t_options *options)
{	
	options->precision = ft_atoi_flag(str, start);
}

int		ft_printf(const char *str, ...)
{
	t_options	*options;
	t_options	opt;
	va_list ap;

	options = &opt;
	va_start(ap, str);
	initialize_struct(options);
	options->res = 0;
	options->it = 0;
	while(str[options->it])
	{
		if (str[options->it] != '%')
		{
			write (1, &str[options->it], 1);
			options->it++;
			options->res += 1;
		}
		else
		{
			options->it++;
			search_flag_one(str, ap, options);
			search_flag_two(str, ap, options);
			if (!search_char_one(str, ap, options))
				search_char_two(str, ap, options);
		}
	}
	va_end(ap);
	return (options->res);
}

