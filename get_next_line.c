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
	static char	*stash = "";
	char		*buf;
	int	ret;
	int i;

	i = 0;
	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (fd)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (stash);
		stash = ft_strjoin(stash, buf);
		// while (stash[i])
		// {
		// 	while (stash[i] != '\n')
		// 		i++;
		// }
	}
	free (buf);
	free (stash);
	return (stash);
}