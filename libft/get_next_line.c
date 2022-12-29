/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:48:38 by sharrach          #+#    #+#             */
/*   Updated: 2022/12/25 15:33:47 by sharrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnljoin(char *s1, char *s2)
{
	char	*s;
	int		s_len;
	int		s2_len;
	int		i;

	s2_len = 0;
	while (s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	if (s2[s2_len] == '\n')
		s2_len++;
	s = ((char *)malloc(ft_strlen(s1) + s2_len + 1));
	if (s == 0)
		return (NULL);
	ft_strcpy(s, (char *) s1);
	s_len = ft_strlen(s);
	i = 0;
	while (i < s2_len)
	{
		s[s_len + i] = s2[i];
		i++;
	}
	s[s_len + i] = '\0';
	free (s1);
	return (s);
}

static int	ft_read_fd(int fd, char **next_line)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	int			ret;
	size_t		buffer_len;

	if (buffer[fd][0] == '\0')
	{
		ret = read(fd, buffer[fd], BUFFER_SIZE);
		buffer[fd][ret] = '\0';
		if (ret < 1)
		{
			if (ret == -1)
				ft_bzero(*next_line, 1);
			return (0);
		}
	}
	buffer_len = 0;
	while (buffer[fd][buffer_len] && buffer[fd][buffer_len] != '\n')
		buffer_len ++;
	if (buffer[fd][buffer_len] == '\n')
		buffer_len ++;
	*next_line = ft_strnljoin(*next_line, buffer[fd]);
	ft_strcpy(buffer[fd], &buffer[fd][buffer_len]);
	return (1);
}

char	*get_next_line(int fd)
{
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = malloc (1 * sizeof(char));
	if (!next_line)
		return (0);
	next_line[0] = '\0';
	while (!ft_strchr(next_line, '\n'))
		if (!ft_read_fd(fd, &next_line))
			break ;
	if (next_line[0] == '\0')
	{
		free (next_line);
		return (0);
	}
	return (next_line);
}
