/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:42:25 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/01 17:20:53 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	temp_s = (unsigned char *) s;
	i = 0;
	while (i < n)
		temp_s[i++] = (unsigned char) c;
	return (s);
}
