/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:19:00 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/24 10:56:34 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	i;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}
