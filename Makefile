# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouflet <amouflet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 09:55:07 by amouflet          #+#    #+#              #
#    Updated: 2023/02/02 14:38:54 by amouflet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

################################################################################
#                                                                              #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
#                                                                              #
################################################################################

MAP		=	map_tab.c				\
			map_lst.c				\
			map_utils.c				\
			map_check_format.c		\
			map_check_gameplay.c

INIT_END	=	open_window.c	\
			close_window.c

DISPLAY	=	image.c	\
			init_images.c
			

HOOK	=	manage_hook.c

M		=	mandatory.c

B		=	bonus.c

################################################################################
#                                                                              #
#                                                                              #
#                                 VARIABLES                                    #
#                                                                              #
#                                                                              #
################################################################################

SRC_DIR	=	srcs/

MAP_DIR	=	map/

DISPLAY_DIR	=	display/

INIT_END_DIR	=	init_end/

HOOK_DIR	=	hook/

M_DIR	=	mandatory/

B_DIR	=	bonus/

SRC		=	$(addprefix $(MAP_DIR), $(MAP))
SRC		+=	$(addprefix $(INIT_END_DIR), $(INIT_END))
SRC		+=	$(addprefix $(DISPLAY_DIR), $(DISPLAY))
SRC		+=	$(addprefix $(HOOK_DIR), $(HOOK))

SRC_B	=	$(addprefix $(B_DIR), $(B))
SRC_M	=	$(addprefix $(M_DIR), $(M))

OBJ_M	=	$(addprefix $(BUILD), $(SRC_M:.c=.o))

OBJ_B	=	$(addprefix $(BUILD), $(SRC_B:.c=.o))

OBJ		=	$(addprefix $(BUILD), $(SRC:.c=.o))

DEPS 	= 	$(OBJ:.o=.d)

BUILD	=	.build/

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -MMD -MP -g

LIB_MLX	=	minilibx-linux/libmlx.a
LIB_MLX	+=	minilibx-linux/libmlx_Linux.a
LIBFT_A	=	libft/libft.a

LFT		=	-lft
LMLX	=	-lmlx
LMLX	+=	-lmlx_Linux
L		=	-lXext -lX11 -lm -lz

INCL	=	-I./includes/
INCL	+=	-I./libft/includes/
INCL	+=	-I./minilibx-linux/

DIRS	=	$(addprefix $(BUILD), $(INIT_END_DIR))
DIRS	+=	$(addprefix $(BUILD), $(MAP_DIR))
DIRS	+=	$(addprefix $(BUILD), $(M_DIR))
DIRS	+=	$(addprefix $(BUILD), $(B_DIR))
DIRS	+=	$(addprefix $(BUILD), $(HOOK_DIR))
DIRS	+=	$(addprefix $(BUILD), $(DISPLAY_DIR))


################################################################################
#                                                                              #
#                                                                              #
#                                    RULES                                     #
#                                                                              #
#                                                                              #
################################################################################

all:	$(NAME)

$(BUILD):
	@mkdir .build

$(addprefix $(BUILD), $(MAP_DIR)):
	@mkdir $@

$(addprefix $(BUILD), $(INIT_END_DIR)):
	@mkdir $@

$(addprefix $(BUILD), $(DISPLAY_DIR)):
	@mkdir $@

$(addprefix $(BUILD), $(HOOK_DIR)):
	@mkdir $@

$(addprefix $(BUILD), $(M_DIR)):
	@mkdir $@

$(addprefix $(BUILD), $(B_DIR)):
	@mkdir $@

$(BUILD)%.o:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

$(LIBFT_A):	mlibft

mlibft:
	@make -C libft/

$(LIB_MLX):	mlibmlx

mlibmlx:
	@make -C minilibx-linux/

$(NAME):	Makefile $(BUILD) $(DIRS) $(OBJ) $(OBJ_M) $(LIBFT_A) $(LIB_MLX)
	$(CC) $(OBJ) $(OBJ_M) -o $(NAME) $(L) -L./minilibx-linux/ $(LMLX) -L./libft/ $(LFT)
	
bonus:	Makefile $(BUILD) $(DIRS) $(OBJ) $(OBJ_B) $(LIBFT_A) $(LIB_MLX)
	$(CC) $(OBJ) $(OBJ_B) -o $(NAME) $(L) -L./minilibx-linux/ $(LMLX) -L./libft/ $(LFT)
	
clean:
	@make clean -C minilibx-linux/
	@make clean -C libft/
	@rm -rf $(BUILD)
	@rm -f $(LIBS)

fclean:	clean
	@make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean mlibft mlibmlx create_map_dir create_build 

-include $(DEPS)