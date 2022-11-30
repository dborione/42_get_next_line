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

char	*ft_search_new_line(char *buf, char *stash, int fd)
{
	int		read_ret;

	read_ret = 1;
	while (!ft_strrchr(stash, '\n') && (read_ret != 0))
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[read_ret] = '\0';
		stash = ft_strjoin(stash, buf);
		// free buf et retourner NULL directement si la malloc a echoue car apres on va tenter d'acceder a une valeur dans stash alors que la variable est free
	}
	free(buf);
	if (*stash == '\0')
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	// attention pas de free de stash si stash existe deja. malloc le stash avant de rentrant dans la fonction pour eviter le free d'une variable pas malloc
	if (!stash)
	{
		stash = malloc(sizeof(*stash));
		if (!stash)
		{
			free (buf);
			return (NULL);
		}
		*stash = '\0';
	}
	stash = ft_search_new_line(buf, stash, fd);
	return (stash);
}

char	*ft_copy_line(char *stash)
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

char	*ft_copy_stash(char *stash)
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
	if (stash_len == 1)
		ft_strlcpy(new_stash, &(stash[i]), stash_len);
	else
		ft_strlcpy(new_stash, &(stash[i + 1]), stash_len);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_copy_line(stash);
	// attention pas de return NULL si malloc rate au dessus, du coup il y aura un free de stash dans la prochaine fonction alors que stash est deja free //
	stash = ft_copy_stash(stash);
	// free line si la malloc de copy stash echoue et renvoie NULL
	return (line);
}
