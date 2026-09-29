/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:51:16 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/17 15:56:14 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	char			*temp_s;
	unsigned int	i;
	size_t			s_len;

	if (! s)
		return (NULL);
	s_len = (unsigned int) ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	temp_s = (char *) s;
	i = 0;
	while (i < len)
	{
		substr[i] = temp_s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
