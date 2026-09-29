/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:02:40 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/21 15:03:26 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_format(char specifier, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	if (!format)
		return (count - 1);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_print_format(format[++i], ap);
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

static int	ft_print_format(char specifier, va_list ap)
{
	int		count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_ptr((unsigned long long)va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr((long)va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_print_nbr((long)va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int), 0);
	else if (specifier == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), 1);
	else
		count += ft_print_char(specifier);
	return (count);
}
