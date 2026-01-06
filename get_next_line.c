/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigondra <tigondra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:58:33 by tigondra          #+#    #+#             */
/*   Updated: 2026/01/06 13:24:47 by tigondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return (NULL);
}

static char	*fill_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&stash));
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			break ;
	}
	free(buf);
	if (bytes < 0 || !stash || !stash[0])
		return (ft_free(&stash));
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	len;

	if (!stash || !stash[0])
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (ft_substr(stash, 0, len));
}

static char	*trim_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free(&stash));
	i++;
	if (!stash[i])
		return (ft_free(&stash));
	new_stash = ft_substr(stash, i, ft_strlen_sizet(stash + i));
	if (!new_stash)
		return (ft_free(&stash));
	ft_free(&stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (ft_free(&stash));
	stash = trim_stash(stash);
	return (line);
}
