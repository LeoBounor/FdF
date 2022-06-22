# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbounor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:28:13 by Leo               #+#    #+#              #
#    Updated: 2022/06/22 13:48:26 by lbounor          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = 	draw.c 									\
		fdf_utils_2.c 							\
		fdf_utils.c 							\
		main.c 									\
		read_file.c 							\
		get_next_line/get_next_line_utils.c 	\
		get_next_line/get_next_line.c 			\
		
HEADER		=	fdf.h 							\
				get_next_line/get_next_line.h	\
				
OBJS		= ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

all: ${NAME}

$(NAME) : ${SRCS} $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(SRCS) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o ${NAME}
	@echo "\033[92m\n[- COMPILATION COMPLETE -]\n\033[0m"
	@echo "\033[94m\n[- PLEASE LAUNCH FDF WITH A MAP AS AN ARGUMENT -]\n\033[0m"

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o -o3 $@

clean :
	${RM} ${OBJS}
	@echo "\033[91m\n[- FILES DELETED -]\n\033[0m"

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re