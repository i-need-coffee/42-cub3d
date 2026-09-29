/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shadya <shadya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 20:14:40 by shadya            #+#    #+#             */
/*   Updated: 2025/10/15 21:30:33 by shadya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	dup_s = malloc(s_len * sizeof(char));
	if (! dup_s)
		return (NULL);
	ft_strlcpy(dup_s, s, s_len);
	return (dup_s);
}
