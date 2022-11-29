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
	printf("bsize%zu", buf_size);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	size_t		pos_n;
	char		*str_line;
	
	pos_n = 0;
	if (!buffer)
		return (NULL);
	while ((buffer[pos_n] != '\n' && buffer[pos_n] != '\0'))
			pos_n++;
	printf("%zu", pos_n);
	str_line = ft_calloc(pos_n + 1, sizeof(char));
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
	return (str_line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = read_buf(fd);
	line = ft_line(buffer);
	free(buffer);
	buffer = NULL;
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("\n%s", line);
	close (fd);
	system("leaks -q a.out\n");
}
