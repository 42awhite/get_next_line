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

char *ft_join_free(char *txt, char *buffer)
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
	
	if (!txt)
		txt = ft_calloc(1, 1);
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
			return(NULL);
		}
		buffer[buf_size] = '\0';
		txt = ft_join_free(txt, buffer);
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

	// printf("antes de\n");
	// system("leaks -q a.out");
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
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_join_buf(fd, buffer);
	line = ft_line(buffer);
	buffer = save_txt(buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*buf;
	int		cont;

	fd = open ("file.txt", O_RDONLY);
	cont = 1;
	while (cont <= 1)
	{	
		buf = get_next_line(fd);
		printf("%s", buf);
		free(buf);
		cont++;
	}
	close(fd);
	//system("leaks -q a.out");
}*/