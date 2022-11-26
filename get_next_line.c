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
	//char	*return_line;
	//int	line_len;

	if (!fd || BUFFER_SIZE < 0)
		return (NULL);
	if (!stash)
		stash = "";
	printf("stash:%s\n", stash);
	stash = ft_read_line(fd, stash);
	//printf("strrchr:%s:fin\n", ft_strchr(stash, '\n'));
	// line_len = ft_strlen(ft_strchr(stash, '\n'));
	// return_line = malloc (sizeof(*return_line) * ((ft_strlen(stash) + 1) - line_len));
	// if (!return_line)
	// {
	// 	free (stash);
	// 	return (NULL);
	// }
	// ft_strlcpy(return_line, stash, ft_strlen(stash) + 1);
	// free (stash);
	// return (return_line);
	return (stash);
}