/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:22:10 by dborione          #+#    #+#             */
/*   Updated: 2022/11/15 10:49:40 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		buff;

	if (!s2 || !s1)
		return (NULL);
	buff = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc (sizeof(char) * buff);
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, (ft_strlen(s1) + 1));
	ft_strlcat(s3, s2, buff);
	return (s3);
}

// int	main()
// {
// 	char *s1 = "buffer";
// 	char *s2;
// 	s2 = "";

// 	printf("%s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
