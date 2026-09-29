/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:28:23 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/21 15:00:18 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	count;

	if (!str)
	{
		ft_print_str("(null)");
		return (6);
	}
	count = 0;
	while (str[count])
	{
		ft_print_char((int) str[count]);
		count++;
	}
	return (count);
}

int	ft_print_nbr(long n)
{
	int		count;

	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_nbr(-n) + 1);
	}
	else if (n < 10)
		return (ft_print_char(n + '0'));
	else
	{
		count = ft_print_nbr(n / 10);
		return (count + ft_print_nbr(n % 10));
	}
}

int	ft_print_hex(unsigned long long n, int is_upper)
{
	int		count;
	char	*hex_base;

	if (is_upper)
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (n < 16)
		return (ft_print_char(hex_base[n]));
	else
	{
		count = ft_print_hex(n / 16, is_upper);
		return (count + ft_print_hex(n % 16, is_upper));
	}
}

int	ft_print_ptr(unsigned long long n)
{
	int	count;

	if (n == 0)
	{
		ft_print_str("(nil)");
		return (5);
	}
	ft_print_str("0x");
	count = ft_print_hex(n, 0);
	return (count + 2);
}
