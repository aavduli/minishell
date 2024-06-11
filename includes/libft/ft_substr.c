/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:03:18 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 16:28:14 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*dst;
	unsigned int	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (str_len < start + len)
		len = str_len - start;
	dst = (char *) malloc((len + 1) * sizeof (char));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

/*int	main(void)
{
	char	*str = "0123456789";
	int		start = 5;

	printf("result: %s\n", ft_substr(str, start, 10));
	return (0);
}*/
