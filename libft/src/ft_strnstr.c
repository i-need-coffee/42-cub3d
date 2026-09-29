/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shadya <shadya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:41:45 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/15 21:14:51 by shadya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp_big;
	char	*temp_little;

	temp_big = (char *) big;
	temp_little = (char *) little;
	if (*temp_little == '\0')
		return (temp_big);
	i = 0;
	while (temp_big[i] && i < len)
	{
		j = 0;
		if (temp_big[i] == temp_little[j])
		{
			while ((temp_big[i + j] == temp_little[j]) && (i + j != len))
			{
				j++;
				if (temp_little[j] == '\0')
					return (&temp_big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
