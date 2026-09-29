/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:08:10 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/18 11:45:44 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c);
static void	ft_free(char **strings, int count);
static int	ft_get_word_len(const char *s, char c);
static int	ft_fill_strings(char **strings, const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (! ft_fill_strings(strings, s, c))
		return (NULL);
	return (strings);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	is_word;

	count = 0;
	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (s[i] == c)
			is_word = 0;
		i++;
	}
	return (count);
}

static void	ft_free(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	ft_get_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	ft_fill_strings(char **strings, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = ft_get_word_len(s + i, c);
		strings[j] = ft_substr(s, i, len);
		if (!strings[j])
		{
			ft_free(strings, j);
			return (0);
		}
		i += len;
		j++;
	}
	strings[j] = NULL;
	return (1);
}
