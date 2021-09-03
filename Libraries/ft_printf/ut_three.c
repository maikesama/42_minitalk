
#include "ft_printf.h"

unsigned int	ft_digits_counter_hexp(unsigned long long int n)
{
	unsigned int	needed;

	needed = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		needed++;
	}
	return (needed);
}

char	*ft_convert_hexlow(char *str, unsigned long int n, unsigned int len)
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
			str[len - 1] = res + 87;
		n = n / 16;
		len--;
	}
	return (str);
}

char	*ft_itoa_hexlow(unsigned long int n)
{
	char	*str;
	unsigned int		len;

	len = ft_digits_counter_hex(n);
	if (!(str = ft_calloc(len + 1, sizeof(*str))))
		return (0);
	return (ft_convert_hexlow(str, n, len));
}

unsigned int	ft_digits_counter_hex(unsigned long int n)
{
	unsigned int	needed;

	needed = 0;
	if (!n)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		needed++;
	}
	return (needed);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else if (n < 10)
		ft_putchar(n % 10 + '0');
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

