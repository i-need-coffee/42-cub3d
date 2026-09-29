/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shadya <shadya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 14:23:03 by sjolliet          #+#    #+#             */
/*   Updated: 2026/09/03 10:47:12 by shadya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_parse_sign(const char *nptr, long long *i);

long long	ft_str_to_lld(const char *nptr)
{
	long long	res;
	long long	sign;
	long long	i;

	if (ft_strcmp(nptr, "-9223372036854775808") == 0)
		return (LLONG_MIN);
	i = 0;
	sign = ft_parse_sign(nptr, &i);
	res = 0;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		if (res > (LLONG_MAX - (nptr[i] - '0')) / 10)
			return (0);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

static long long	ft_parse_sign(const char *nptr, long long *i)
{
	long long	sign;

	sign = 1;
	while (nptr[*i] == ' ' || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}
