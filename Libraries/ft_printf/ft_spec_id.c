
#include "ft_printf.h"

void	ft_putnbr_args(va_list args, t_options *options)
{
	int num_len;
	int n_zero;
	int	num;

	num = va_arg(args, long int);
	n_zero = 0;
	num_len = ft_digits_counter(num);
	if (options->precision > -1)
		options->zero = 0;
	if (options->precision == 0 && num == 0)
	{
		num_len = 0;
		if (options->width)
		{
			while(options->width-- > num_len)
			{
				ft_putchar(' ');
				options->res++;
			}
		}
		initialize_struct(options);
		return;
	}
	if (options->precision > num_len)
	{
		n_zero = options->precision - num_len;
		num_len = options->precision;
	}
	if (num < 0)
		num_len++;
	options->res += num_len;
	if (options->width > num_len)
		options->res += (options->width - num_len);
	if (!options->minus)
	{
		if (num < 0 && options->zero)
		{
			ft_putchar('-');
			num *= -1;
		}
		while (options->width-- > num_len)
			ft_putchar((options->zero? '0' : ' '));
	}
	if (num < 0 && num != -2147483648)
	{
		ft_putchar('-');
		num *= -1;
	}
	while (n_zero-- > 0)
		ft_putchar('0');
	ft_putnbr(num);
	if (options->minus)
	{
		while(options->width-- > num_len)
			ft_putchar(' ');
	}
	initialize_struct(options);
}
