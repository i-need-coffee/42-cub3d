/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:08:11 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/09 16:43:22 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;
	size_t			i;

	temp_s = (unsigned char *) s;
	temp_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == temp_c)
			return ((void *) &temp_s[i]);
		i++;
	}
	return (NULL);
}
