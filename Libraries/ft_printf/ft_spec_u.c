
#include "ft_printf.h"

unsigned int	ft_digits_counter_unsigned(unsigned long int n)
{
	unsigned int	needed;

	needed = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		needed++;
	}
	return (needed);
}

char	*ft_convert_unsigned(char *str, unsigned long int n, int len)
{
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned long int n)
{
	char	*str;
	int		len;

	len = ft_digits_counter_unsigned(n);
	if (!(str = ft_calloc(len + 1, sizeof(*str))))
		return (0);
	return (ft_convert_unsigned(str, n, len));
}

void	ft_putnbr_unsigned_args(va_list args, t_options *options)
{
	unsigned int	n;

	n = va_arg(args, unsigned long int);
	if (n >= 4294967195 || n == 2147483648)
		options->zero = 0;
	ft_putstr_hex(ft_itoa_unsigned(n), options);
	initialize_struct(options);
}
