# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchow <jchow@student.42.us.org>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/21 22:34:31 by jchow             #+#    #+#              #
#    Updated: 2017/06/21 22:34:32 by jchow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				fdf

SRC = 				main \
					pulsers \
					util \
					transform_scale \
					transform_translate \
					transform_rotate \
					bresenham_line_drawing_algo \
					cohen_sutherland_line_clipping_algo \
					draw_grid \
					init \
					init2 \
					key_hooks_init \
					key_function_pointers \
					key_function_pointers2 \
					key_function_pointers3 \
					key_function_pointers4 \
					key_function_pointers5 \
					mlx_hooks \
					mouse_hooks_init \
					mouse_function_pointers \
					instructions \
					pulse_function_pointers

HDR =				fdf \
					keys \
					function_pointers

SRC_DIR =			src/
SRC_C =				$(addsuffix .c, $(SRC))
SRC_FILES =			$(addprefix $(SRC_DIR), $(SRC_C))

OBJ_DIR =			obj/
OBJ_O =				$(addsuffix .o, $(SRC))
OBJ_FILES =			$(addprefix $(OBJ_DIR), $(OBJ_O))

LIBFT_DIR =			libft/
LIBFT_A =			libft.a
LIBFT_FILES =		$(addprefix $(LIBFT_DIR), $(LIBFT_A))

LIBFT_HDR_DIR =		libft/includes/

MLX =				minilibx/libmlx.a
MLX_FLAGS =			-L minilibx -lmlx -framework OpenGL -framework AppKit

HDR_DIR =			includes/
HDR_H =				$(addsuffix .h, $(HDR))
HDR_FILES =			$(addprefix $(HDR_DIR), $(HDR_H))

C_FLAGS =			-Wall -Wextra -Werror
OPT_FLAGS = 		-O3
P_THREAD =			-lpthread

RED =				\033[31m
GREEN =				\033[32m
BLUE =				\033[34m
YELLOW =			\033[33m
MAGENTA =			\033[35m
GREY =				\033[37m
GREEN_LIGHT =		\033[92m
YELLOW_LIGHT =		\033[93m
YELLOW_BOLD =		\033[1;33m
YELLOW_LIGHT_BOLD =	\033[1;93m
MAGENTA_LIGHT =		\033[95m
BLINK =				\033[5m
GREEN_LIGHT_BLINK =	\033[5;92m
END_COLOUR =		\033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_FILES) $(MLX)
	@echo "$(YELLOW_LIGHT)$(NAME): $(YELLOW)Compiling $(NAME)...$(END_COLOUR)"
	@gcc $(C_FLAGS) $(MLX_FLAGS) $(OPT_FLAGS) $(P_THREAD) $^ -o $@
	@echo "$(YELLOW_LIGHT)$(NAME): $(GREEN)Successfully compiled $(NAME)!$(END_COLOUR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR_FILES)
	@mkdir -p obj
	@gcc $(C_FLAGS) -I $(HDR_DIR) -I $(LIBFT_HDR_DIR) -I minilibx -c $< -o $@

$(LIBFT_FILES): force
	@make -C $(LIBFT_DIR)

$(MLX): force
	@make -C minilibx

force:
	@true

clean:
	@echo "$(YELLOW_LIGHT)$(NAME): $(YELLOW)Cleaning objects...$(END_COLOUR)"
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) && make clean -C minilibx
	@echo "$(YELLOW_LIGHT)$(NAME): $(GREEN)Successfully cleaned all objects!$(END_COLOUR)"

fclean: clean
	@echo "$(YELLOW_LIGHT)$(NAME): $(YELLOW)Cleaning executable...$(END_COLOUR)"
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(YELLOW_LIGHT)$(NAME): $(GREEN)Successfully cleaned everything!$(END_COLOUR)"

re:	fclean all

.PHONY: all force clean fclean re
