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
	static char	*line;
	char		*buf;
	int i = 0;

	if (!fd)
		return (NULL);
	if (!line)
		line = "";
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE))
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				//buf = &(buf[i]);
				line = ft_strjoin(line, buf);
				free (buf);
				return (line);
			}
			i++;
		}
	}
	free (buf);
	return (NULL);
}