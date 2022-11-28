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
	//char	*new_stash;
	int		read_ret;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// if (read(fd, buf, BUFFER_SIZE) == 0)
	// 	return (NULL);
	if (!ft_strchr(stash, '\n'))
	{
		while ((read_ret = read(fd, buf, BUFFER_SIZE)))
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
			if (strchr(buf, '\n'))
			{
				free (buf);
				//free (stash);
				return (stash);
			}
		}
	}
	free (buf);
	if (*stash == '\0')
		return (NULL);
	return (stash);
}

char *ft_copy_line(char *stash)
{
	char		*line;
	int			i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	ft_strlcpy(line, stash, (i + 2));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char *line;

	
	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	
	if (!stash)
	{
		stash = malloc(sizeof(*stash));
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	stash = ft_read_line(fd, stash);
	if (!stash)
	{
		free (stash);
		return (NULL);
	}
	line = ft_copy_line(stash);
	while (*stash && *stash != '\n')
		stash++;
	stash++;
	return (line);
}