/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:50 by ablanco-          #+#    #+#             */
/*   Updated: 2022/11/22 20:08:09 by ablanco-         ###   ########.fr       */
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

int	main(void)
{
	char	*buf;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	buf = read_buf(fd);
	printf("%s\n", buf);
	close(fd);
}
