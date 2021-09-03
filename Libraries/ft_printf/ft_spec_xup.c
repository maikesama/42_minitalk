
#include "ft_printf.h"

char	*ft_convert_hex(char *str, unsigned int n, int len)
{
	unsigned int res;

	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	while (n > 0)
	{
		res = n % 16;
		if (res < 10)
			str[len - 1] = res + 48;
		else
			str[len - 1] = res + 55;
		n = n / 16;
		len--;
	}
	return (str);
}

char	*ft_itoa_hex(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_digits_counter_hex(n);
	if (!(str = ft_calloc(len + 1, sizeof(*str))))
		return (0);
	return (ft_convert_hex(str, n, len));
}

void	ft_putnbr_hex_args(va_list args, t_options *options)
{
	unsigned int	n;

	n = va_arg(args, unsigned long int);
	ft_putstr_hex(ft_itoa_hex(n), options);
	initialize_struct(options);
}