/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:10:58 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/09 15:24:53 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	temp_c;
	char	*temp_s;

	temp_c = (char) c;
	temp_s = (char *) s;
	i = ft_strlen(temp_s);
	while (i >= 0)
	{
		if (temp_s[i] == temp_c)
			return (&temp_s[i]);
		i--;
	}
	return (NULL);
}
