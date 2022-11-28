/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:50:38 by dborione          #+#    #+#             */
/*   Updated: 2022/11/12 13:29:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && (read_ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_ret == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[read_ret] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	int	i;

	i = 0;
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = "";
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	ft_strlcpy(line, stash, (i + 2));
	while (*stash != '\n')
		stash++;
	stash++;
	return (line);
}