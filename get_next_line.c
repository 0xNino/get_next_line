/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:21 by 0xNino            #+#    #+#             */
/*   Updated: 2021/11/30 03:14:03 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_reminder(int fd, char *reminder)
{
	char	*buf;
	int		read_return;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
//	printf("buf = (%s)\n", buf);
	read_return = 1;
//	printf("reminder = (%s)\n", reminder);
	while (!ft_strchr(reminder, '\n') && read_return)
	{
//		printf("read_return = %i\n", read_return);
		read_return = read(fd, buf, BUFFER_SIZE);
//		printf("read_return = %i\n", read_return);
		if (read_return == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_return] = '\0';
//		printf("buf before join = (%s)\n", buf);
		reminder = ft_strjoin(reminder, buf);
//		printf("reminder after join = (%s)\n", reminder);
	}
	free(buf);
	return (reminder);
}

char	*ft_get_line(char *reminder)
{
	int		i;
	char	*line;

	i = 0;
	if (!reminder)
		return (NULL);
	while (reminder[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reminder[i] != '\n')
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
	char	*line;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	line = (char *)malloc((ft_strlen(reminder) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i])
	{
		line[j++] = reminder[i++];
	}
	line[j] = '\0';
	free(reminder);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
//	printf("reminder = (%s)\n", reminder);
	reminder = ft_read_reminder(fd, reminder);
//	printf("reminder2 = (%s)\n", reminder);
	if (!reminder)
		return (NULL);
	line = ft_get_line(reminder);
	reminder = ft_new_reminder(reminder);
	return (line);
}
/*
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	fd = open("./tests/test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error");
		return (1);
	}
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
		printf("close() error");
		return (1);
	}
	printf("success");
	return (0);
}
*/
