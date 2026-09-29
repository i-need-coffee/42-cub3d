/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shadya <shadya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:44:47 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/15 20:40:39 by shadya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	temp_c;
	char	*temp_s;

	temp_c = (char) c;
	temp_s = (char *) s;
	i = 0;
	while (temp_s[i])
	{
		if (temp_s[i] == temp_c)
			return (&temp_s[i]);
		i++;
	}
	if (temp_s[i] == temp_c)
		return (&temp_s[i]);
	return (NULL);
}
