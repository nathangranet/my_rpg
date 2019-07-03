/*
** EPITECH PROJECT, 2019
** shield
** File description:
** shield
*/

#include "rpg.h"
#include "map.h"

void bonus_and_sprite_shield2(gestion_t *game, scene_t *scene,
                                stuff_t **stuff, int nb)
{
    if (nb == 6) {
        stuff[1]->bonus = 3;
        stuff[1]->item = create_object
            ("ressources/sprite_inventory/shield3.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 7) {
        stuff[1]->bonus = 4;
        stuff[1]->item = create_object
            ("ressources/sprite_inventory/shield4.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void bonus_and_sprite_shield(gestion_t *game, scene_t *scene,
                            stuff_t **stuff, int nb)
{
    if (nb == 4) {
        stuff[1]->bonus = 1;
        stuff[1]->item = create_object
            ("ressources/sprite_inventory/shield1.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 5) {
        stuff[1]->bonus = 2;
        stuff[1]->item = create_object
            ("ressources/sprite_inventory/shield2.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void add_shield(gestion_t *game, scene_t *scene, stuff_t **stuff, int i)
{
    if (stuff[1]->exist == 0)
        stuff[1]->exist = 1;
    else if (stuff[1]->exist = 1)
        game->inventory->item[stuff[1]->type]->nb++;
    stuff[1]->type = i;
    bonus_and_sprite_shield(game, scene, stuff, i);
    bonus_and_sprite_shield2(game, scene, stuff, i);
}
