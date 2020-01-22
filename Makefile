# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jesmith <jesmith@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 11:03:39 by jesmith        #+#    #+#                 #
#    Updated: 2020/01/22 17:15:58 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -o

DEBUGFLAGS = -g 

MLX = minilibx_macos/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/

SRCS = ./srcs/

SRCS_FILES = main utilities mlx_setup fractol_manager key_events \
			get_color mouse_events user_interface hsv_color

CFILES = $(SRCS_FILES:%=$(SRCS)%.c)

OFILES = $(CFILES:%.c=%.o)

HEADERS = includes/fractol.h

ADD_FILES = Makefile author


all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $@ $<

$(NAME) : $(OFILES)
	@make re -C $(LIBFT)
	@gcc -I $(MLX) -L $(MLX) $(MLXFLAGS) -I $(LIBFT) -L $(LIBFT) -lft \
	$(CFILES) $(FLAGS) $(NAME)

clean :
	@make clean -C $(LIBFT)
	@rm -f $(OFILES)
	@rm -f *#
	@rm -f *~
	@rm -f *.DS_Store
	@rm -Rf .vscode

fclean :
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

add : fclean
	@git add $(MLX) $(LIBFT) $(CFILES) $(HEADERS) $(ADD_FILES)
	@git status

push :
ifdef MSG
	@git commit -m MSG
	@git push -u
endif
