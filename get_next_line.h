/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:28:25 by 0xNino            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:06:39 by 0xNino           ###   ########.fr       */
=======
/*   Updated: 2021/11/25 16:37:33 by 0xNino           ###   ########.fr       */
>>>>>>> 48a030130ebbce6405bf9859ead9fde56b8c5ff8
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

<<<<<<< HEAD
=======
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

>>>>>>> 48a030130ebbce6405bf9859ead9fde56b8c5ff8
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif