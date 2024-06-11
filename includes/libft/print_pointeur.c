/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:05:17 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/24 10:59:58 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointeur.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:05:17 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/23 16:05:21 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_ptr_len(unsigned long nbr)
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

void	ft_putptr(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_putptr(nbr / 16);
		ft_putptr(nbr % 16);
	}
	else if (nbr <= 9)
		ft_putchar_fd(nbr + '0', 1);
	else
		ft_putchar_fd(nbr - 10 + 'a', 1);
}

int	ft_printptr(unsigned long ptr)
{
	int	pointeur_len;

	pointeur_len = 0;
	if (ptr == 0)
		pointeur_len += print_string("0x0");
	else
	{
		pointeur_len += print_string("0x");
		ft_putptr(ptr);
		pointeur_len += ft_ptr_len(ptr);
	}
	return (pointeur_len);
}
