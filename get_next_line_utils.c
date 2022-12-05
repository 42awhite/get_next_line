/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:09:19 by ablanco-          #+#    #+#             */
/*   Updated: 2022/11/24 17:10:08 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	c;
	size_t	cont;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || (!s1 && !s2))
		return (NULL);
	c = 0;
	cont = 0;
	if (s1)
	{
		while (s1[c])
		{
			str[cont] = s1[c];
			cont++;
			c++;
		}
	}
	c = 0;
	while (s2[c])
		str[cont++] = s2[c++];
	str[cont] = '\0';
	return (str);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	q;
	char	*str;

	str = s;
	q = 0;
	while (q < n)
	{
		str[q] = '\0';
		q++;
	}
	return (str);
}

void	*ft_calloc(size_t cont, size_t size)
{
	void	*pnt;
	size_t	n;

	n = size * cont;
	if (n < size && n < cont)
		return (0);
	pnt = malloc(n);
	if (pnt == (void *)0)
		return (0);
	ft_bzero(pnt, n);
	return (pnt);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char) c)
			return ((char *)&s[cont]);
		cont++;
	}
	if ((char)c == '\0')
		return ((char *)&s[cont]);
	return (NULL);
}
