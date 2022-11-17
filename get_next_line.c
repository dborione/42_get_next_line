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

char	*get_next_line(int fd)
{
	static int	i;
	static char	*stash;
	char		*buf;
	int j;

	if (fd != 3)
		return (NULL);
	if (!i)
		i = 0;
	else
		i++;
	j = i;
	if (!stash)
		stash = "";
	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE))
	{
		stash = ft_strjoin(stash, buf);
		while (stash[i])
		{
			if (stash[i] == '\n')
			{
				free (buf);
				return (ft_substr(stash, j, (i + 1) - j));
			}
			i++;
		}
	}
	free (buf);
	return (stash);
}