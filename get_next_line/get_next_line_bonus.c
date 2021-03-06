/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:49:47 by wwang             #+#    #+#             */
/*   Updated: 2022/02/06 18:52:52 by wwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *s)
{
	int		i;
	char	*t;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	t = (char *)malloc(sizeof(char) * (i + 2));
	if (!t)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		t[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

char	*ft_save(char *s)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	t = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!t)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		t[j++] = s[i++];
	t[j] = '\0';
	free(s);
	return (t);
}

char	*ft_read_save(int fd, char *s)
{
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(s, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*s[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	s[fd] = ft_read_save(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	l = ft_line(s[fd]);
	s[fd] = ft_save(s[fd]);
	return (l);
}
