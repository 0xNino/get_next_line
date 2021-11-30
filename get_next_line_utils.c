/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:16 by 0xNino            #+#    #+#             */
/*   Updated: 2021/11/30 14:27:22 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_start;

	src_start = src;
	if (dstsize > 1)
	{
		while (*src && dstsize > 1)
		{
			*dst++ = *src++;
			dstsize--;
		}
	}
	if (dstsize >= 1)
		*dst = '\0';
	while (*src)
		src++;
	return (src - src_start);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dst_len + 1)
		return (src_len + dstsize);
	while (i < (dstsize - dst_len - 1) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len != dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *reminder, char *buf)
{
	char	*s3;
	size_t	dstsize;

	s3 = NULL;
//	printf("reminder in join = (%s)\n", reminder);
//	printf("buf in join = (%s)\n", buf);
	if (!reminder)
	{
		reminder = (char *)malloc(sizeof(char));
		reminder[0] = '\0';
	}
	if (reminder && buf)
	{
		dstsize = ft_strlen(reminder) + ft_strlen(buf) + 1;
		s3 = (char *)malloc(sizeof(char) * dstsize);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, reminder, dstsize);
		ft_strlcat(s3, buf, dstsize);
	}
	free(reminder);
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
