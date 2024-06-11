/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:00:39 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/13 14:42:18 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (0);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int	main(void)
{
	char	str[] = "Coucou";

	printf("Copie= %s\n", ft_strdup(str));
	return (0);
}
*/