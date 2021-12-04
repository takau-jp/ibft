# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:48:11 by macbook_air       #+#    #+#              #
#    Updated: 2021/12/04 20:22:22 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
		  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= ${SRCS:.c=.o}
B_OBJS	= $(B_SRCS:.c=.o)
ifdef WITH_BONUS
OBJS	+= $(B_OBJS)
endif
DEPS	= ${SRCS:.c=.d}
B_DEPS	= ${B_SRCS:.c=.d}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -MMD -MP
RM = rm -f

${NAME} : ${OBJS}
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus :
	@make WITH_BONUS=1

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS} $(B_OBJS) ${DEPS} ${B_DEPS}

fclean: clean
	${RM} ${NAME}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus