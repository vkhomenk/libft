/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:55:33 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/07/10 17:31:11 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_nbrlen_base(long long int nbr, size_t base, int sign)
{
	size_t				count;
	int					k;
	unsigned long long	tmp;

	if (base < 2 || nbr == 0)
		return (base < 2 ? 0 : 1);
	count = 0;
	k = 1;
	if (sign && nbr < 0)
	{
		count = 1;
		k = -1;
	}
	tmp = (unsigned long long)nbr * k;
	while (tmp >= base)
	{
		tmp /= base;
		count++;
	}
	return (count + 1);
}
