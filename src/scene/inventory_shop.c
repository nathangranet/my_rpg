/*
** EPITECH PROJECT, 2019
** inventory_shop
** File description:
** inventory_shop
*/

#include "map.h"
#include "rpg.h"

void buy_check2(int i, gestion_t *game)
{
    if (i == 2 || i == 6 || i == 10) {
        if (game->money >= 30) {
            game->money = game->money - 30;
            game->inventory->item[i]->nb++;
        }
    }
    else if (i == 3 || i == 7) {
        if (game->money >= 40) {
            game->money = game->money - 40;
            game->inventory->item[i]->nb++;
        }
    }
}

void buy_check(int i, gestion_t *game)
{
    if (i == 0 || i == 4 || i == 8) {
        if (game->money >= 10) {
            game->money = game->money - 10;
            game->inventory->item[i]->nb++;
        }
    }
    else if (i == 1 || i == 5 || i == 9) {
        if (game->money >= 20) {
            game->money = game->money - 20;
            game->inventory->item[i]->nb++;
        }
    }
    else
        buy_check2(i, game);
}

void buy_inventory(gestion_t *game, scene_t *scene, sfView *view)
{
    static int ntm = 0;
    sfFloatRect rect;
    float a = sfMouse_getPosition(NULL).x;
    float b = sfMouse_getPosition(NULL).y;
    float l, m;

    for (int i = 0; i < 11; i++) {
        if (game->inventory->item[i]->nb >= 0) {
            rect = sfSprite_getGlobalBounds(scene->objs[i + 9]->sprite);
            l = a + sfView_getCenter(view).x - 960;
            m = b + sfView_getCenter(view).y - 540;
            if (sfFloatRect_contains(&rect, l, m)) {
                buy_check(i, game);
            }
        }
    }
}