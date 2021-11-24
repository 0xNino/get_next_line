# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 0xNino <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 11:54:16 by 0xNino            #+#    #+#              #
#    Updated: 2021/11/24 12:09:21 by 0xNino           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	get_next_line_utils.c
				get_next_line.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -D BUFFER_SIZE=42

NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
