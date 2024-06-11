/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:11:48 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/23 16:37:44 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_format(char specifier, va_list arg);
int		print_char(char c);
int		print_string(char *str);
int		print_nbr(int nbr);
int		print_unsint(unsigned int nbr);
int		print_hex(unsigned int nbr, const char format);
int		ft_printptr(unsigned long ptr);
#endif
