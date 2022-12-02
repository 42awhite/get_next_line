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

char	*read_join_buf(int fd, char *txt)
{
	char	*buffer;
	int		buf_size;
	
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	if (!buffer)
		return (NULL);
	buf_size = 1;
	while (buf_size > 0)
	{
		buf_size = read(fd, buffer, BUFFER_SIZE);
		if (buf_size < 0)
		{
			free(buffer);
			return(NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		txt = ft_strjoin(txt, buffer);
		if(ft_strchr(txt, '\n'))
			break ;
	}
	free (buffer);
	return (txt);
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

char	*save_txt(char *buffer)
{
	char	*txt;
	size_t	pos_n;
	size_t	c_txt;

	if (!buffer)
		return (NULL);
	pos_n = 0;
	while (buffer[pos_n] != '\n' && buffer[pos_n] != '\0')
		pos_n++;
	txt = ft_calloc(ft_strlen(buffer) - pos_n + 1, sizeof(char));
	if (!txt)
		return(NULL);
	c_txt = 0;
	while (buffer[pos_n])
	{
		txt[c_txt] = buffer[pos_n];
		pos_n++;
		c_txt++;
	}
	return (txt);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}	
	buffer = read_join_buf(fd, buffer);
	line = ft_line(buffer);
	buffer = save_txt(buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*buf;
	int		cont;

	fd = open ("file.txt", O_RDONLY);
	cont = 1;
	while (cont < 4)
	{
		buf = get_next_line(fd);
		printf("%s\n", buf);
		cont++;
	}
	close(fd);
	//system("leaks -q a.out");
}