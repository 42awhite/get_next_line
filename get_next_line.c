/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:50 by ablanco-          #+#    #+#             */
/*   Updated: 2022/11/24 17:19:38 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd)
{
	char	*buffer;
	size_t	buf_size;
	
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	if (!buffer)
		return (NULL);
	buf_size = read(fd, buffer, BUFFER_SIZE);
	buffer[buf_size++] = '\0';
	return (buffer);
}

char	*line(char *buffer)
{
	size_t		pos_n;
	char		*str_line;
	
	pos_n = 0;
	if (!buffer)
		return (NULL);
	while ((buffer[pos_n] != '\n' && buffer[pos_n] != '\0'))
			pos_n++;
	str_line = ft_calloc(pos_n + 2, sizeof(char));
	if (!str_line)
		return (NULL);
	pos_n = 0;
	while (buffer[pos_n] != '\n' && buffer[pos_n] != '\0')
	{
		str_line[pos_n] = buffer[pos_n];
		pos_n++;
	}
	if (buffer[pos_n] == '\n')
		str_line[pos_n] = '\n';
	str_line[++pos_n] = '\0';
	return (str_line);
}


int	main(void)
{
	char 	buffer[] = "hola, me llamo pingui \n, soy muy salado \n y solo como pescado congelado";
	char	*str_line;

	str_line = line(buffer);
	printf("%s", str_line);
	free(str_line);
}
