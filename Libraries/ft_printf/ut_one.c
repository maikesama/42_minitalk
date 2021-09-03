#include "ft_printf.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *ptr;

	ptr = b;
	while (n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (b);
}

void	ft_bzero(void *str, size_t n)
{
	if (n)
		ft_memset(str, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (!size)
	{
		ptr = malloc(size);
		return (ptr);
	}
	if (!(ptr = malloc(size * count)))
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr2;

	ptr = (unsigned char *)src;
	ptr2 = (unsigned char *)dst;
	if (!(dst) && !(src))
		return (0);
	while (n)
	{
		*ptr2 = *ptr;
		ptr2++;
		ptr++;
		n--;
	}
	return (dst);
}