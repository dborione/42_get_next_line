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

// # define BUF_SIZE nbr de char a lire avant de rencontrer la fin de la ligne
char	*get_next_line(int fd)
{
	char	*buf; // buffer de destination
	static char	*stash;
	int		count;//nbre d'octets a lire: line size
	int		line_count; // nbr de char lus sur la ligne;
	int		ret;

	int		byte = 
	while (byte != '\n' && byte <= BUF_SIZE)
	{
		line_count++;
		count++;
	}
	buf = malloc(sizeof(*buf) * (line_count + 1));
	if (!buf)
		return (NULL);
	while (byte != '\n' && byte <= BUF_SIZE)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf = read(fd, buf, BUF_SIZE);
	}
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
