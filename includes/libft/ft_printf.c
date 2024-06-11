/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:14:24 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/23 16:42:36 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	print_format(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char((char)va_arg(arg, int));
	else if (specifier == 's')
		count += print_string(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_nbr(va_arg(arg, int));
	else if (specifier == 'u')
		count += print_unsint(va_arg(arg, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += print_hex(va_arg(arg, unsigned int), specifier);
	else if (specifier == 'p')
		count += ft_printptr(va_arg(arg, unsigned long));
	else if (specifier == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	va_start(arg, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += print_format(format[i + 1], arg);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
/*
int	main(void)
{
	int	count_ft;
	int	count;

	count_ft = ft_printf("Hex lowercase: %x\n", 255);
	count = printf("Hex lowercase: %x\n", 255);
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	count_ft = ft_printf("Hex uppercase: %X\n", 255);
	count = printf("Hex uppercase: %X\n", 255);
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	count_ft = ft_printf("Decimal: %d\n", 42);
	count = printf("Decimal: %d\n", 42);
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	count_ft = ft_printf("String: %s\n", "Ecole 42");
	count = printf("String: %s\n", "Ecole 42");
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	count_ft = ft_printf("Char: %c\n", 'A');
	count = printf("Char: %c\n", 'A');
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	count_ft = ft_printf("Pourcentage: %%\n");
	count = printf("Pourcentage: %%\n");
	printf("Compteur ft_printf : %d, Compteur printf : %d\n", count_ft, count);
	return (0);
}
*/