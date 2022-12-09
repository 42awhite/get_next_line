/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:50 by ablanco-          #+#    #+#             */
/*   Updated: 2022/11/24 17:19:38 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *txt, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(txt, buffer);
	free(txt);
	return (aux);
}

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
		if (buf_size == -1)
		{
			free (txt);
			free(buffer);
			return (NULL);
		}
		buffer[buf_size] = '\0';
		txt = ft_join_free(txt, buffer);
		if (ft_strchr(txt, '\n'))
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
	if (!buffer[pos_n])
		return (NULL);
	while ((buffer[pos_n] != '\n' && buffer[pos_n] != '\0'))
			pos_n++;
	if (buffer[pos_n] == '\n')
		str_line = ft_calloc(pos_n + 2, sizeof(char));
	else
		str_line = ft_calloc(pos_n + 1, sizeof(char));
	if (!str_line)
		return (NULL);
	pos_n = -1;
	while (buffer[++pos_n] != '\n' && buffer[pos_n] != '\0')
		str_line[pos_n] = buffer[pos_n];
	if (buffer[pos_n] == '\n' && buffer[pos_n])
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
	while (buffer[pos_n] != '\n' && buffer[pos_n])
		pos_n++;
	if (!buffer[pos_n])
	{
		free (buffer);
		return (NULL);
	}
	txt = ft_calloc(ft_strlen(buffer) - pos_n + 1, sizeof(char));
	c_txt = 0;
	pos_n++;
	while (buffer[pos_n])
	{
		txt[c_txt] = buffer[pos_n];
		pos_n++;
		c_txt++;
	}
	free (buffer);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char		*buffer[FOPEN_MAX];
	char			*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_join_buf(fd, buffer[fd]);
	line = ft_line(buffer[fd]);
	buffer[fd] = save_txt(buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd[4];
	char	*buf[4];
	int		cont;
	int		c_fd;

	fd[0] = open ("file.txt", O_RDONLY);
	fd[1] = open ("potter.txt", O_RDONLY);
	fd[2] = open ("Frodo.txt", O_RDONLY);
	fd[3] = open ("quijote.txt", O_RDONLY);
	cont = 0;
	c_fd = 0;
	while (cont <= 4)
	{	
		buf[cont] = get_next_line(fd[c_fd++]);
		printf("%s", buf[cont]);
		free(buf[cont]);
		cont++;
	}
	c_fd = 0;
	while (c_fd <= 3)
		close(fd[c_fd++]);
	//system("leaks -q a.out");
}
*/