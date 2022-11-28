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
	if (!ft_strchr(stash, '\n'))
	{
		while ((read_ret = read(fd, buf, BUFFER_SIZE)))
		{
			if (read_ret == -1)
			{
				free (buf);
				return (NULL);
			}
			//printf("read_ret:%d\n", read_ret);
			buf[read_ret] = '\0';
			stash = ft_strjoin(stash, buf);
			//printf("stash1");
			if (!stash)
			{
				free (buf);
				return (NULL);
			}
			if (strchr(buf, '\n'))
			{
				free (buf);
				//free (stash);
				//printf("ns:%s:fin\n", stash);
				//printf("stash3");
				return (stash);
			}
		}
	}
	//printf("stash2");
	free (buf);
	return (stash);
}

char *ft_copy_line(char *stash)
{
	char		*line;
	int			i;

	i = 0;
	//printf("stash5");
	while (stash[i] && stash[i] != '\n')
		i++;
	//printf("stash6");
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	//printf("stash7");
	ft_strlcpy(line, stash, (i + 2));
	//printf("stash8");
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
		//printf("stash4");
		free (stash);
		return (NULL);
	}
	line = ft_copy_line(stash);
	//printf("stash9");
	while (*stash && *stash != '\n')
		stash++;
	//printf("stash10");
	stash++;
	return (line);
}