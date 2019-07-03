/*
** EPITECH PROJECT, 2019
** sword
** File description:
** sword
*/

#include "rpg.h"
#include "map.h"

void bonus_and_sprite_sword2(gestion_t *game, scene_t *scene,
                            stuff_t **stuff, int nb)
{
    if (nb == 2) {
        stuff[0]->bonus = 6;
        stuff[0]->item = create_object
            ("ressources/sprite_inventory/sword3.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 3) {
        stuff[0]->bonus = 8;
        stuff[0]->item = create_object
            ("ressources/sprite_inventory/sword4.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void bonus_and_sprite_sword(gestion_t *game, scene_t *scene,
                            stuff_t **stuff, int nb)
{
    if (nb == 0) {
        stuff[0]->bonus = 2;
        stuff[0]->item = create_object
            ("ressources/sprite_inventory/sword1.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
    if (nb == 1) {
        stuff[0]->bonus = 4;
        stuff[0]->item = create_object
            ("ressources/sprite_inventory/sword2.png",
            get_vector(20, 620), get_rect(0, 0, 40, 40));
    }
}

void add_sword(gestion_t *game, scene_t *scene, stuff_t **stuff, int i)
{
    if (stuff[0]->exist == 0)
        stuff[0]->exist = 1;
    else if (stuff[0]->exist = 1)
        game->inventory->item[stuff[0]->type]->nb++;
    stuff[0]->type = i;
    bonus_and_sprite_sword(game, scene, stuff, i);
    bonus_and_sprite_sword2(game, scene, stuff, i);
}
