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
	static int i;
	char		*buf;
	int j;
	int ret;

	if (!fd)
		return (NULL);
	if (BUFFER_SIZE < 0)
		return (NULL);
	if (!i)
		i = 0;
	else
		i++;
	j = i;
	if (!stash)
		stash = "";
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		stash = ft_strjoin(stash, buf);
		// printf("%d\n", ret);
		// printf("buf:%s\n", buf);
		// printf("stash:%s\n", stash);
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
	return (NULL);
}