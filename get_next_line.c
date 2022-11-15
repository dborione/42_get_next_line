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
	static char	*stash;
	char		*buf;
	int	i;

	printf("%zd\n", read(fd, buf, BUFFER_SIZE));
	i = 0;
	if (BUFFER_SIZE < 0)
		return (NULL);
	if (stash)
		free (stash);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = "";
	while (read(fd, buf, BUFFER_SIZE))
	{
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free (stash);
			free (buf);
			return (NULL);
		}
	}
	while (stash[i] && stash[i] != '\n')
	{
		write(1, &stash[i], 1);
	 	i++;
	}
	free (buf);
	return (stash);
}
