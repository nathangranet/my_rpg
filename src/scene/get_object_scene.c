/*
** EPITECH PROJECT, 2019
** get_object_scene
** File description:
** get_object_scene
*/

#include "rpg.h"
#include "map.h"

void get_objs_game3(object_t **objects)
{
    objects[16] = create_object("ressources/sprite_inventory/shield4.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[17] = create_object("ressources/sprite_inventory/armor1.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[18] = create_object("ressources/sprite_inventory/armor2.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[19] = create_object("ressources/sprite_inventory/armor3.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[20] = create_object("ressources/sprite_inventory/armor4.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[21] = create_object("ressources/sprite_inventory/money.png",
                                get_vector(20, 620), get_rect(0, 0, 50, 50));
}

void get_objs_game2(object_t **objects)
{
    objects[7] = create_object("ressources/kris_moving_foreward.png",
                                get_vector(50, 30), get_rect(0, 0, 50, 99));
    objects[8] = create_object("ressources/sprite_inventory/sprite_sheet.png",
                                get_vector(55, 330), get_rect(0, 0, 47.5, 95));
    objects[9] = create_object("ressources/sprite_inventory/sword1.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[10] = create_object("ressources/sprite_inventory/sword2.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[11] = create_object("ressources/sprite_inventory/sword3.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[12] = create_object("ressources/sprite_inventory/sword4.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[13] = create_object("ressources/sprite_inventory/shield1.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[14] = create_object("ressources/sprite_inventory/shield2.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
    objects[15] = create_object("ressources/sprite_inventory/shield3.png",
                                get_vector(20, 620), get_rect(0, 0, 40, 40));
}

object_t **get_objs_pause(void)
{
    object_t **objects = malloc(sizeof(*objects) * 4);

    objects[0] = create_object("ressources/continue_button2.png",
                                get_vector(600, 330), get_rect(0, 0, 640, 210));
    objects[1] = create_object("ressources/main_menu2.png",
                                get_vector(600, 560), get_rect(0, 0, 640, 210));
    objects[2] = create_object("ressources/quit_button2.png",
                                get_vector(600, 790), get_rect(0, 0, 640, 210));
    objects[3] = create_object("ressources/coke.png",
                                get_vector(0, 0), get_rect(0, 0, 1920, 1080));
    return (objects);
}

object_t **get_objs_start(void)
{
    object_t **objects = malloc(sizeof(*objects) * 4);

    objects[0] = create_object("ressources/play_button2.png",
                                get_vector(620, 400), get_rect(0, 0, 640, 210));
    objects[1] = create_object("ressources/quit_button2.png",
                                get_vector(620, 700), get_rect(0, 0, 640, 210));
    objects[2] = create_object("ressources/coke.png",
                                get_vector(0, 0), get_rect(0, 0, 1920, 1080));
    return (objects);
}

object_t **get_objs_game(void)
{
    object_t **objects = malloc(sizeof(*objects) * 22);

    objects[0] = create_object("ressources/coke.png",
                                get_vector(0, 0), get_rect(0, 0, 1920, 1080));
    objects[1] = create_object("ressources/kris_moving_foreward.png",
                                get_vector(0, 0), get_rect(0, 0, 50, 99));
    objects[2] = create_object("ressources/kris_moving_right.png",
                                get_vector(0, 0), get_rect(0, 0, 50, 92));
    objects[3] = create_object("ressources/kris_moving_left.png",
                                get_vector(0, 0), get_rect(0, 0, 50, 94));
    objects[4] = create_object("ressources/kris_moving_up.png",
                                get_vector(0, 0), get_rect(0, 0, 50, 96));
    objects[5] = create_object("ressources/stat_pers.png",
                                get_vector(0, 0), get_rect(0, 0, 210, 600));
    objects[6] = create_object("ressources/sprite_inventory/market_inv.png",
                                get_vector(0, 600), get_rect(0, 0, 258, 200));
    get_objs_game2(objects);
    get_objs_game3(objects);
    return (objects);
}
