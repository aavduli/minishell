/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:22:27 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/12 15:46:06 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = dst_len;
	while (i + 1 < size && *src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/*int	main(void)
{
	char	str[] = "AAAAAAAAAAAAAAAAAAAA";
	char	dst[] = "BBBBBBBBBBBBBBBBBBBB";
	char	dst2[] = "BBBBBBBBBBBBBBBBBBBB";

	printf("Result: %zu\n", ft_strlcat(dst, str, 30));
	printf("dst_result: %s\n", dst);
	printf("true.fonc: %zu\n", strlcat(dst2, str, 30));
	printf("dst2.result: %s\n", dst2);
	return (0);
}*/
