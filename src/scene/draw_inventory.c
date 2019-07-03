/*
** EPITECH PROJECT, 2019
** draw_inventory
** File description:
** draw_inventory
*/

#include "map.h"
#include "rpg.h"

void draw_inventory(gestion_t *game, scene_t *scene, sfView *view)
{
    int x = sfView_getCenter(view).x;
    int y = sfView_getCenter(view).y;
    sfSprite_setPosition(scene->objs[5]->sprite, get_vector(x - 960, y - 540));
    sfSprite_setPosition(scene->objs[6]->sprite, get_vector(x - 960, y + 60));
    sfSprite_setPosition(scene->objs[7]->sprite, get_vector(x - 910, y - 510));
    sfSprite_setPosition(scene->objs[8]->sprite, get_vector(x - 905, y - 210));
    sfText_setPosition(game->txt_money, get_vector(x- 900, y + 300));
    sfSprite_setPosition(scene->objs[21]->sprite, get_vector(x - 955, y + 310));
    for (int i = 5; i < 9; i++)
        sfRenderWindow_drawSprite(game->window, scene->objs[i]->sprite, NULL);
}

void draw_stat2(gestion_t *gest, scene_t *scene, game_t *game)
{
    int x = sfView_getCenter(game->view).x;
    int y = sfView_getCenter(game->view).y;
    int hp = 28 + gest->inventory->stuff2[2]->bonus;
    int atk = 5 + gest->inventory->stuff2[0]->bonus;
    int def = 2 + gest->inventory->stuff2[1]->bonus;
    sfText_setString(gest->stats[0], "HP");
    sfText_setPosition(gest->stats[0], get_vector(x - 900, y - 75));
    sfText_setString(gest->stats[1], "Atk");
    sfText_setPosition(gest->stats[1], get_vector(x - 900, y - 50));
    sfText_setString(gest->stats[2], "Def");
    sfText_setPosition(gest->stats[2], get_vector(x - 900, y - 25));
    sfText_setString(gest->stats[3], to_array(hp));
    sfText_setPosition(gest->stats[3], get_vector(x - 850, y - 75));
    sfText_setString(gest->stats[4], to_array(atk));
    sfText_setPosition(gest->stats[4], get_vector(x - 850, y - 50));
    sfText_setString(gest->stats[5], to_array(def));
    sfText_setPosition(gest->stats[5], get_vector(x - 850, y - 25));
}

void draw_stat(gestion_t *gest, scene_t *scene, game_t *game)
{
    int x = sfView_getCenter(game->view).x;
    int y = sfView_getCenter(game->view).y;
    int hp = 21 + gest->inventory->stuff[2]->bonus;
    int atk = 4 + gest->inventory->stuff[0]->bonus;
    int def = 3 + gest->inventory->stuff[1]->bonus;
    sfText_setString(gest->stats[6], "HP");
    sfText_setPosition(gest->stats[6], get_vector(x - 900, y - 375));
    sfText_setString(gest->stats[7], "Atk");
    sfText_setPosition(gest->stats[7], get_vector(x - 900, y - 350));
    sfText_setString(gest->stats[8], "Def");
    sfText_setPosition(gest->stats[8], get_vector(x - 900, y - 325));
    sfText_setString(gest->stats[9], to_array(hp));
    sfText_setPosition(gest->stats[9], get_vector(x - 850, y - 375));
    sfText_setString(gest->stats[10], to_array(atk));
    sfText_setPosition(gest->stats[10], get_vector(x - 850, y - 350));
    sfText_setString(gest->stats[11], to_array(def));
    sfText_setPosition(gest->stats[11], get_vector(x - 850, y - 325));
    draw_stat2(gest, scene, game);
    for (int i = 0; i < 12; i++)
        sfRenderWindow_drawText(gest->window, gest->stats[i], NULL);
}

void draw_stuff2(gestion_t *game, scene_t *scene, sfView *view)
{
    int m = sfView_getCenter(view).x - 940;
    int n = sfView_getCenter(view).y + 15;
    sfCircleShape_setPosition(game->circle[0], get_vector(m - 20, n - 555));
    sfCircleShape_setPosition(game->circle[1], get_vector(m - 20, n - 255));
    for (int i = 0; i < 3; i++) {
        if (game->inventory->stuff2[i]->exist == 1) {
            m = sfView_getCenter(view).x - 940 + i * 50;
            sfSprite_setTextureRect(game->inventory->stuff2[i]->item->sprite,
                                    game->inventory->stuff2[i]->item->rect);
            sfSprite_setPosition
                (game->inventory->stuff2[i]->item->sprite, get_vector(m, n));
            sfRenderWindow_drawSprite(game->window,
                                    game->inventory->stuff2[i]->item->sprite,
                                    NULL);
        }
    }
}

void draw_stuff(gestion_t *game, scene_t *scene, sfView *view)
{
    int m = sfView_getCenter(view).x - 940;
    int n = sfView_getCenter(view).y - 285;

    for (int i = 0; i < 3; i++) {
        if (game->inventory->stuff[i]->exist == 1) {
            m = sfView_getCenter(view).x - 940 + i * 50;
            sfSprite_setTextureRect(game->inventory->stuff[i]->item->sprite,
                                    game->inventory->stuff[i]->item->rect);
            sfSprite_setPosition
                (game->inventory->stuff[i]->item->sprite, get_vector(m, n));
            sfRenderWindow_drawSprite(game->window,
                                    game->inventory->stuff[i]->item->sprite,
                                    NULL);
        }
    }
}