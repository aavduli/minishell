/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:42:00 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/23 15:57:48 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	hex_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

void	put_hex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		put_hex(nbr / 16, format);
		put_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			print_char((nbr + '0'));
		else
		{
			if (format == 'x')
				print_char(nbr - 10 + 'a');
			if (format == 'X')
				print_char((nbr - 10 + 'A'));
		}
	}
}

int	print_hex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		put_hex(nbr, format);
	return (hex_len(nbr));
}
