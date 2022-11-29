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
	while (!ft_strchr(stash, '\n') && (read_ret = read(fd, buf, BUFFER_SIZE)))
	{
		if (read_ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_ret] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
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
		free(stash);
		return (NULL);
	}
	ft_strlcpy(line, stash, (i + 2));
	return (line);
}

char *ft_copy_stash(char *stash)
{
	char		*new_stash;
	int			stash_len;
	int			i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	stash_len = ft_strlen(stash) - i + 1;
	new_stash = malloc(sizeof(*new_stash) * stash_len);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	ft_strlcpy(new_stash, &(stash[i + 1]), stash_len);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char 		*line;

	if (!fd || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(*stash));
		if (!stash)
			return (NULL);
	}
	stash = ft_read_line(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = ft_copy_line(stash);
	stash = ft_copy_stash(stash);
	return (line);
}
 
























// char	*ft_update_stash(char *stash)
// {
// 	int		i;
// 	int		len;
// 	char	*buffer;

// 	i = 0;
// 	if (!stash)
// 		return (NULL);
// 	len = ft_strlen(stash);
// 	while (stash[i] != '\n' && stash[i])
// 		i++;
// 	if (!stash[i])
// 	{
// 		free(stash);
// 		return (NULL);
// 	}
// 	buffer = malloc(sizeof(*buffer) * (len - i + 1));
// 	i++;
// 	len = 0;
// 	while (stash[i])
// 		buffer[len++] = stash[i++];
// 	free(stash);
// 	return (buffer);
// }

// char	*ft_get_line(char *stash)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!stash[0])
// 		return (NULL);
// 	while (stash[i] != '\n' && stash[i])
// 		i++;
// 	line = malloc(sizeof(*line) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (stash[i] != '\n' && stash[i])
// 	{
// 		line[i] = stash[i];
// 		i++;
// 	}
// 	if (stash[i] == '\n' && stash[i])
// 	{
// 		line[i] = '\n';
// 		i++;
// 	}
// 	return (line);
// }

// char	*ft_readline(int fd, char *stash)
// {
// 	char	*buffer;
// 	int		a;

// 	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	if (!stash)
// 		stash = malloc(sizeof(*stash));
// 	a = 1;
// 	while (!ft_strrchr(buffer, '\n') && a > 0)
// 	{
// 		a = read(fd, buffer, BUFFER_SIZE);
// 		if (a < 0)
// 		{
// 			free(buffer);
// 			free(stash);
// 			return (NULL);
// 		}
// 		buffer[a] = '\0';
// 		stash = ft_strjoin(stash, buffer);
// 	}
// 	free(buffer);
// 	return (stash);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*stash;
// 	char		*line;

// 	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
// 		return (NULL);
// 	stash = ft_readline(fd, stash);
// 	if (!stash)
// 		return (NULL);
// 	line = ft_get_line(stash);
// 	stash = ft_update_stash(stash);
// 	return (line);
// }