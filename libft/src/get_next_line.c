/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:48:29 by sjolliet          #+#    #+#             */
/*   Updated: 2026/02/15 16:21:42 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all_stash(char **stash);
static char	*fill_stash(char *stash, int fd);
static char	*get_line_before_newline(char *stash);
static char	*clean_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*new_line;

	if (fd == -1)
		return (free_all_stash(stash), NULL);
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup_gnl("");
	if (!stash[fd])
		return (NULL);
	stash[fd] = fill_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	new_line = get_line_before_newline(stash[fd]);
	if (!new_line)
		return (free_and_null(&stash[fd]), NULL);
	stash[fd] = clean_stash(stash[fd]);
	return (new_line);
}

static void	free_all_stash(char **stash)
{
	int	i;

	i = 0;
	while (i < FD_MAX)
	{
		free_and_null(&stash[i]);
		i++;
	}
}

static char	*fill_stash(char *stash, int fd)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free_and_null(&stash), NULL);
	while (!ft_strchr_gnl(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free_and_null(&stash), NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		temp = ft_strjoin_gnl(stash, buffer);
		if (!temp)
			return (free(buffer), free_and_null(&stash), NULL);
		free_and_null(&stash);
		stash = temp;
	}
	free(buffer);
	if (stash[0] == '\0')
		return (free_and_null(&stash), NULL);
	return (stash);
}

static char	*get_line_before_newline(char *stash)
{
	int		i;
	int		len;
	char	*line;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*temp;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (free_and_null(&stash), NULL);
	temp = ft_strdup_gnl(&stash[i + 1]);
	free_and_null(&stash);
	return (temp);
}
