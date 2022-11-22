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
	int	i;
	static char	*stash;
	char		*buf;
	//int j;
	//int ret;

	if (!fd)
		return (NULL);
	//if (!i)
	i = 0;
	// else
	// 	i++;
	// j = i;
	if (!stash)
		stash = "";
	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (stash[i] != '\n' && read(fd, buf, BUFFER_SIZE))
	{
		stash = ft_strjoin(buf, stash);
		//printf("stash:%s\n", stash);
		// while (stash[i])
		// {
		// 	if (stash[i] == '\n')
		// 	{
		// 		free (buf);
		// 		return (stash);
		// 	}
		// 	i++;
		//}
		//printf("stash:%s\n", stash);
		// printf("%d:", ret);
		// printf("buf:%s:fin\n", buf);
		// printf("stash:%s:fin\n", stash);
		
		// while (stash[i])
		// {	
			
		// 	//printf("%d", ret);
		// 	//printf(":%c ", stash[i]);
		// 	if (stash[i] == '\n')
		// 	{
		// 		// printf("j:%d ", j);
		// 		// printf("i:%d ", i);		
		// 		free (buf);
		// 		//if (ret < BUFFER_SIZE)

		// 		return (ft_substr(stash, j, (i + 1) - j));
		// 	}
		//i++;
		// }
	}
	free (buf);
	return (stash);
}