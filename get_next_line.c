/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:50:38 by dborione          #+#    #+#             */
/*   Updated: 2022/11/10 16:57:17 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define BUF_SIZE nbr de char a lire avant de rencontrer la fin de la ligne
char	*get_next_line(int fd)
{
	char	*buf; // buffer de destination
	int		count;//nbre d'octets a lire: line size
//	buf = malloc(sizeof(*buf));
	fd  = open();
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}

//	return (ligne lue\n)
//		ou return (-1);

}
