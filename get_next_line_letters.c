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

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line_letters(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int	i;

	if (!fd)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!stash)
		stash = "";
	i = 0;
	while (i < BUFFER_SIZE && read(fd, buf, 1))
	{
		stash = ft_strjoin(stash, buf);
		if (*buf == '\n')
		{
			line = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
			if (!line)
				return (NULL);
			line = stash;
			stash = buf + 1;
			free (buf);
			return (line);
		}
		i++;
	}
	free (buf);
	return (NULL);
}