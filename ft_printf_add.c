#include "printf.h"
#include <unistd.h>

int	ft_putnbr(long nb) 
{
	long num;
	int len = 0;

	if (nb < 0) 
	{
		write(1, "-", 1);
		len++;
		nb = -nb;
	}
	if (nb > 9) 
	{
		len += ft_putnbr(nb / 10);
	}
	num = (nb % 10) + '0';
	write(1, &num, 1);
	len++;

	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char up) 
{
	int len = 0;
	char *base;

	base = (up == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nbr > 15) {
		int aux = ft_putnbr_hexa(nbr / 16, up);
		if (aux == -1)
			return -1;
		len += aux;
	}
	if (write(1, &base[nbr % 16], 1) == -1)
		return -1;

	return (len + 1);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}

int	ft_putstr(char *str1)
{
	int	len;

	if (!str1)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str1 != '\0')
	{
		if (write(1, str1, 1) == -1)
			return (-1);
		len++;
		str1++;
	}
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}