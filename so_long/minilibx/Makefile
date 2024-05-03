# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpocater <rpocater@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 14:54:41 by rpocater          #+#    #+#              #
#    Updated: 2024/02/13 15:42:46 by rpocater         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+= -O2 -w -DSTRINGPUTX11
%.o : %.c
	@cc $(CFLAGS) -c -o $@ $<
%.o : %.m
	@cc $(CFLAGS) -c -o $@ $<
all: $(NAME)
$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME) *~
	@rm -f mlx_app
re: clean all
