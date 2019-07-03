##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a makefile
##

SRC	=	src/main.c						\
		src/scene/buttons_functions.c		\
		src/scene/check_buttons.c			\
		src/scene/create_scenes.c			\
		src/scene/draw_scenes.c				\
		src/scene/event_scenes.c			\
		src/scene/init_struct.c				\
		src/scene/tools.c					\
		src/scene/inventory.c				\
		src/scene/items.c					\
		src/Mathieu/my_map.c				\
		src/Mathieu/my_tools.c				\
		src/Mathieu/init1.c					\
		src/Mathieu/init2.c					\
		src/Mathieu/init3.c					\
		src/Mathieu/my_ennemies.c			\
		src/Mathieu/my_moves.c				\
		src/Mathieu/my_world.c				\
		src/Mathieu/my_boss.c				\
		src/Mathieu/launch_fight.c			\
		src/Mathieu/particles.c				\
		src/Mathieu/particles_walk.c		\
		src/fight/fight.c					\
		src/fight/fight2.c					\
		src/fight/fight3.c					\
		src/fight/fight4.c					\
		src/fight/fight5.c					\
		src/fight/fight6.c				\
		src/fight/anim_kris1.c				\
		src/fight/anim_kris.c				\
		src/fight/spell.c					\
		src/fight/fight_norm.c				\
		src/fight/play_eve2.c		\
		src/fight/init_enemi.c		\
		src/fight/enemies_atk.c		\
		src/fight/more_anim.c				\
		src/fight/anim_ene1.c				\
		src/fight/atk_ene.c					\
		src/fight/play_eve.c				\
		src/scene/game_win.c				\
		src/scene/draw_inventory.c			\
		src/scene/inventory_click_item.c	\
		src/scene/inventory_shop.c			\
		src/scene/armor.c					\
		src/scene/shield.c					\
		src/scene/sword.c					\
		src/scene/get_object_scene.c		\

FML		=	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

CPPFLAGS	=	-I./include/

##CFLAGS	=	-Wall -Wextra -W -g3

OBJ		=	$(SRC:.c=.o)

NAME	=	my_rpg.exe

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(FML) $(CPPFLAGS)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
