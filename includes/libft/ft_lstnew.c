/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aavduli <aavduli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:29:11 by aavduli           #+#    #+#             */
/*   Updated: 2023/10/17 13:36:39 by aavduli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (0);
	new_elem -> content = content;
	new_elem -> next = 0;
	return (new_elem);
}
