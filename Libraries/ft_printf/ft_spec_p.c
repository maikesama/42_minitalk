
#include "ft_printf.h"

char	*ft_convert_hexp(char *str, unsigned long long int n, unsigned int len)
{
	unsigned long long int res;

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

char	*ft_itoa_hexp(unsigned long long int n)
{
	char	*str;
	unsigned long long int		len;

	len = ft_digits_counter_hexp(n);
	if (!(str = ft_calloc(len + 1, sizeof(*str))))
		return (0);
	return (ft_convert_hexp(str, n, len));
}

void	sparep(char *s, t_options *options)
{
	int n;
	
	if (!options->minus && options->width > ft_strlen(s))
	{
		n = options->width - ft_strlen(s) - 2;
		while (n--)
		{
			write(1, " ", 1);
			options->res += 1;
		}
	}
}
void	ft_putstr_0x(char *s, t_options *options)
{
	int	i;
	int	n;

	i = 0;
	sparep(s, options);
	write (1, "0x", 2);
	while (s[i])
	{
		i++;
	}
	write(1, s, i);
	options->res += (i + 2);
	if (options->minus && options->width > ft_strlen(s))
	{
		n = options->width - ft_strlen(s) - 2;
		while (n--)
		{
			write(1, " ", 1);
			options->res += 1;
		}
	}
	free(s);
}


void	put_memadd_arg(va_list args, t_options *options)
{
	unsigned long long int ptr;

	ptr = va_arg(args, unsigned long long int);
	ft_putstr_0x(ft_itoa_hexp(ptr), options);
	initialize_struct(options);
}