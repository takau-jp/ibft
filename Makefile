# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 15:48:11 by macbook_air       #+#    #+#              #
#    Updated: 2022/06/15 16:49:10 by stanaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCDIR	= ./srcs
SRCS	= ${addprefix ${SRCDIR}/ctype/, ${addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_isspace}}
SRCS	+= ${addprefix ${SRCDIR}/stdio/, ${addsuffix .c, ft_printf ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd}}
SRCS	+= ${addprefix ${SRCDIR}/stdio/printf/, ${addsuffix .c, ft_array_calc ft_conv_a ft_conv_a2 ft_conv_a3 ft_conv_c ft_conv_d ft_conv_d_len ft_conv_e \
			 ft_conv_e2 ft_conv_e3 ft_conv_e4 ft_conv_o ft_conv_o_len ft_conv_p ft_conv_percent ft_conv_u ft_conv_u_len \
			 ft_conv_utils ft_conv_s ft_conv_x ft_conv_x_len \
			 ft_conv_f ft_conv_f2 ft_conv_g ft_conv_ge ft_conv_ge2 ft_conv_ge3 ft_conv_gf ft_conv_gf2 ft_double_utils ft_double_utils2 ft_double_utils3 \
			 ft_conv_n ft_conv_n_len ft_get_digits ft_get_digits_long ft_hex_array_calc ft_put_conv ft_put_width_space ft_read_conv ft_read_conv_utils \
			 ft_join_utils ft_print ft_print_buf \
			 ft_abs_intmax ft_putchar ft_putstr ft_putstrl ft_putnbr ft_strcmp}}
SRCS	+= ${addprefix ${SRCDIR}/stdlib/, ${addsuffix .c, ft_atoi ft_calloc ft_itoa ft_abs ft_labs}}
SRCS	+= ${addprefix ${SRCDIR}/string/, ${addsuffix .c, ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
		  ft_strlcat ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_strdup\
		  ft_substr ft_strjoin ft_strtrim ft_split ft_strmapi ft_striteri ft_strcat ft_strndup ft_strnlen}}
B_SRCS	= ${addprefix ${SRCDIR}/lst/, ${addsuffix .c, ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
		  ft_lstdelone ft_lstclear ft_lstiter ft_lstmap}}

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

${NAME} : ${OBJDIR} ${OBJS}
	ar src $(NAME) $(OBJS)

${OBJDIR}:
	-mkdir -p ${OBJDIR}

${OBJDIR}/%.o: ${SRCDIR}/ctype/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdio/%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/stdio/printf/%.c
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
	rm -rf ${OBJDIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
