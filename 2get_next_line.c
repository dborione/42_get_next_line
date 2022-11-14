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
// # define BUF_SIZE
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf; // buffer de destination
	int			count;//nbre d'octets a lire: line size
	int			line_count; // nbr de char lus sur la ligne;
	int			ret; // valuer de returrn: nbre d'octets lus

	buf = malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	buf = read(fd, buf, BUF_SIZE);
	while (*buf <= BUF_SIZE)
	{
		buf++;
		
	}
	if (*stash == '\n')

	stash = buf;
	buf[i] = '\0';
	ft_pustr(buf);





	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
//	close(file_to_read);
//	return (ligne lue\n)
//		ou return (-1);

}
