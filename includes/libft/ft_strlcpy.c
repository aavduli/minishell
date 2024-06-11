/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:53:56 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 10:42:07 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <string.h>

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (--size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}

/*int main(void)
{
	char	str[] = "ASkjnalkfa";
	char	dst[] = "";

	printf("src.len: %d\n", ft_strlen(str));
	printf("dst.len %d\n", ft_strlen(dst));
	printf("after: %zu\n", ft_strlcpy(dst,str,6));
	//printf("strlcpy.result: %lu\n", strlcpy(dst, str, 6));
	printf("dst.strlcpy %zu\n", ft_strlcpy(dst,str,6));
	printf("dst= %s\n", dst);
	return (0);
}*/
