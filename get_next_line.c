/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:21 by 0xNino            #+#    #+#             */
/*   Updated: 2021/12/02 12:13:15 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	reminder = ft_read_reminder(fd, reminder);
	if (!reminder)
		return (NULL);
	line = ft_get_line(reminder);
	reminder = ft_new_reminder(reminder);
	return (line);
}

char	*ft_read_reminder(int fd, char *reminder)
{
	char	*buf;
	int		read_return;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_return = 1;
	while (!ft_strchr(reminder, '\n') && read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_return] = '\0';
		reminder = ft_strjoin(reminder, buf);
	}
	free(buf);
	return (reminder);
}

char	*ft_get_line(char *reminder)
{
	int		i;
	char	*line;

	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		line[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n')
	{
		line[i] = reminder[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_reminder(char *reminder)
{
	int		i;
	int		j;
	char	*new_reminder;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	new_reminder = (char *)malloc((ft_strlen(reminder) - i + 1) * sizeof(char));
	if (!new_reminder)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i])
	{
		new_reminder[j++] = reminder[i++];
	}
	new_reminder[j] = '\0';
	free(reminder);
	return (new_reminder);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("./tests/41_no_nl", O_RDONLY);
//	fd = 1000;
	if (fd == -1)
		printf("open() error\n");
	i = 0;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("line = (%s)\n", line);
		i++;
	}
	free(line);
	if (close(fd) == -1)
	{
		printf("close() error\n");
		return (1);
	}
	printf("success\n");
	return (0);
}
*/