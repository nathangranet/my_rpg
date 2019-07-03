/*
** EPITECH PROJECT, 2019
** armor
** File description:
** armor
*/

#include "rpg.h"
#include "map.h"

void bonus_and_sprite_armor2(gestion_t *game, scene_t *scene,
                            stuff_t **stuff, int nb)
{
    if (nb == 10) {
        stuff[2]->bonus = 3;
        stuff[2]->item = create_object
            ("ressources/sprite_inventory/armor3.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 11) {
        stuff[2]->bonus = 4;
        stuff[2]->item = create_object
            ("ressources/sprite_inventory/armor4.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void bonus_and_sprite_armor(gestion_t *game, scene_t *scene,
                            stuff_t **stuff, int nb)
{
    if (nb == 8) {
        stuff[2]->bonus = 1;
        stuff[2]->item = create_object
            ("ressources/sprite_inventory/armor1.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 9) {
        stuff[2]->bonus = 2;
        stuff[2]->item = create_object
            ("ressources/sprite_inventory/armor2.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void add_armor(gestion_t *game, scene_t *scene, stuff_t **stuff, int i)
{
    if (stuff[2]->exist == 0)
        stuff[2]->exist = 1;
    else if (stuff[2]->exist = 1)
        game->inventory->item[stuff[2]->type]->nb++;
    stuff[2]->type = i;
    bonus_and_sprite_armor(game, scene, stuff, i);
    bonus_and_sprite_armor2(game, scene, stuff, i);
}
