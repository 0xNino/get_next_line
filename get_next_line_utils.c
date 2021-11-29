/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:16 by 0xNino            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:07:01 by 0xNino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
=======
/*   Updated: 2021/11/25 17:56:41 by 0xNino           ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	dstsize;

	s3 = NULL;
	if (s1 && s2)
	{
		dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
		s3 = (char *)malloc(sizeof(char) * dstsize);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, dstsize);
		ft_strlcat(s3, s2, dstsize);
	}
	return (s3);
}
>>>>>>> 48a030130ebbce6405bf9859ead9fde56b8c5ff8
