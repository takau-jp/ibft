# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:48:11 by macbook_air       #+#    #+#              #
#    Updated: 2021/12/05 11:11:36 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCDIR	= ./srcs
SRCS	= ${addprefix ${SRCDIR}/ctype/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c}
SRCS	+= ${addprefix ${SRCDIR}/stdio/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c}
SRCS	+= ${addprefix ${SRCDIR}/stdlib/, ft_atoi.c ft_calloc.c ft_itoa.c ft_abs.c ft_labs.c }
SRCS	+= ${addprefix ${SRCDIR}/string/, ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
		  ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_strcat.c ft_strndup.c ft_strnlen.c}
B_SRCS	= ${addprefix ${SRCDIR}/lst/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c}

OBJDIR	= ./objs
OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
B_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.o}}}
ifdef WITH_BONUS
OBJS	+= $(B_OBJS)
endif

DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.d}}}
B_DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.d}}}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -MMD -MP
INCLUDE   = -I./includes

RM = rm -f

${NAME} : ${OBJS}
	ar src $(NAME) $(OBJS)

${OBJDIR}/%.o: ${SRCDIR}/ctype/%.c
	-mkdir -p ${OBJDIR}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdio/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdlib/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/string/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/lst/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

all: $(NAME)

bonus :
	@make WITH_BONUS=1

.c.o :
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${RM} ${OBJS} $(B_OBJS) ${DEPS} ${B_DEPS}

fclean: clean
	${RM} ${NAME}
	rmdir ${OBJDIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus