# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpocater <rpocater@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 21:03:44 by rpocater          #+#    #+#              #
#    Updated: 2024/02/13 19:17:44 by rpocater         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long
SRCS	= controls.c errors_two.c errors.c graphics.c map.c so_long.c
LIBFT	= ./libft/libft.a
MLX	= ./minilibx/libmlx.a
OBJS	= ${SRCS:.c=.o}
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS	= -Lminilibx -lmlx -framework OpenGL -framework Appkit
HEADER	= so_long.h
RM	= rm -f
%.o:		%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -Iminilibx -c -o $@ $<
all:	$(NAME)
$(NAME):	$(OBJS) ${LIBFT} ${MLX}
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(MLX) $(OBJS) -o $(NAME)
${LIBFT}:
	make all -C libft
	cp ${LIBFT} ${NAME}
${MLX}:
	make all -C minilibx
	cp ${MLX} ${NAME}
clean:
	$(RM) $(OBJS)
	make clean -C minilibx
	make clean -C libft
fclean:	clean
	$(RM) $(NAME)
	make fclean -C minilibx
	make fclean -C libft
re:		fclean all
.PHONY: clean fclean all re
