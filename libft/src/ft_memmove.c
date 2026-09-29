/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:43:20 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/14 18:31:14 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp_dest;
	const unsigned char	*temp_src;

	if (!dest && !src)
		return (NULL);
	temp_dest = (unsigned char *) dest;
	temp_src = (const unsigned char *) src;
	if (temp_dest > temp_src && temp_dest < temp_src + n)
	{
		while (n > 0)
		{
			n--;
			temp_dest[n] = temp_src[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
