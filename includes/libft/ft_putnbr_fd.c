/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:16:20 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/16 17:29:33 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
}
/*
int	main(void)
{
	int fd = 1;

	ft_putnbr_fd(42, fd);
	write(fd, "\n", 1);

	ft_putnbr_fd(-42, fd);
	write(fd, "\n", 1);

	ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);

	ft_putnbr_fd(2147483647, fd);
	write(fd, "\n", 1);

	ft_putnbr_fd(-2147483648, fd);
	write(fd, "\n", 1);

	return (0);
}*/