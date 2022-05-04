# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:28:13 by Leo               #+#    #+#              #
#    Updated: 2022/05/04 11:01:46 by lbounor          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

SRCS = sources/ft_printf.c 					\
		sources/ft_parse_printf.c 			\
		sources/ft_args_sort.c 				\
		sources/ft_putchar_args.c 			\
		sources/ft_putstr_args.c 			\
		sources/ft_putptr_args.c 			\
		sources/ft_putnbr_args.c 			\
		sources/ft_putnbr_unsigned_args.c 	\
		sources/ft_puthex_x_args.c 			\
		sources/ft_puthex_ux_args.c 		\
		sources/ft_percent_args.c 			\

OBJS = ${SRCS:.c=.o}

INCLUDES = includes/ft_printf.h

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${INCLUDES}
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} 
	ar rcs ${NAME} ${OBJS} 

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re