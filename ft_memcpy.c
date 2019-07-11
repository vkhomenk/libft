/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:11:53 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/07/10 18:11:43 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*temp;
	char	*res;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	temp = (char*)src;
	res = (char*)dest;
	i = 0;
	while (i < n)
	{
		res[i] = temp[i];
		i++;
	}
	return (dest);
}
