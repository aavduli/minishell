/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:13 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/23 14:44:33 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_nbr(int nbr)
{
	char	*str;
	int		count;

	str = ft_itoa(nbr);
	if (!str)
		return (0);
	count = print_string(str);
	free(str);
	return (count);
}

int	print_unsint(unsigned int nbr)
{
	char	*str;
	int		count;

	str = ft_utoa(nbr);
	if (!str)
		return (0);
	count = print_string(str);
	free (str);
	return (count);
}
