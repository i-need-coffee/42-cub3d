/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:58:35 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/09 14:44:10 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	if (n == 0)
		return (0);
	temp_s1 = (unsigned char *) s1;
	temp_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n - 1 && temp_s1[i] == temp_s2[i])
		i++;
	return ((unsigned char) temp_s1[i] - (unsigned char) temp_s2[i]);
}
