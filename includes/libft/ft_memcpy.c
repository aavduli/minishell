/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:41:42 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 11:20:36 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*dst_initial;

	if (!dst && !src)
		return (0);
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	dst_initial = d;
	while (n)
	{
		*d++ = *s++;
		n--;
	}
	return (dst_initial);
}

/*int main (void)
{
	char	src[] = "Coucou";
	char	dst[] = "Uocuoc";

	ft_memcpy(dst, src, 6);
	printf("result: %s", dst);
	return 0;
}*/
