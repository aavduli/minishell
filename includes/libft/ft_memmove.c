/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:26:31 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 12:08:59 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	char		*d;
	const char	*s;

	d = (char *) dst;
	s = (const char *) src;
	if (!dst && !src)
		return (0);
	if (d < s)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += len;
		s += len;
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	return (dst);
}

/*int main(void)
{
	char	src[] = "Coucou";
	char	dst[] = "Uoc";

	printf("before: %s\n", dst);
	printf("after: %s\n", ft_memmove(dst, src, 9));
	return (0);
}*/