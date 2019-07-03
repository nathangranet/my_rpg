/*
** EPITECH PROJECT, 2019
** inventory
** File description:
** inventory
*/

#include "rpg.h"
#include "map.h"

void second_clock_foreward(scene_t *kris, gestion_t *game, int nb, sfSprite *s)
{
    game->time = sfClock_getElapsedTime(game->clock2);
    if (game->time.microseconds > 100000) {
        sfClock_restart(game->clock2);
        kris->objs[nb]->rect.left += 48;
        if (kris->objs[nb]->rect.left >= 192)
            kris->objs[nb]->rect.left = 0;
        sfSprite_setTextureRect(s, kris->objs[nb]->rect);
    }
}

void set_pos_items(gestion_t *game, scene_t *scene, sfView *view, sfVector2i nb)
{
    int x = sfView_getCenter(view).x - 909 + (nb.x % 4) * 60;
    int y = sfView_getCenter(view).y + 103 + (nb.x / 4) * 59;
    int m = sfView_getCenter(view).x - 940 + (nb.x % 4) * 60;
    int n = sfView_getCenter(view).y + 80 + (nb.x / 4) * 60;
    nb.y += 9;
    if (sfSprite_getPosition(scene->objs[nb.y]->sprite).x != m
        || sfSprite_getPosition(scene->objs[nb.y]->sprite).y != n) {
        sfSprite_setTextureRect(scene->objs[nb.y]->sprite,
                                scene->objs[nb.y]->rect);
        sfSprite_setPosition(scene->objs[nb.y]->sprite, get_vector(m, n));
    }
    sfText_setPosition(game->text, get_vector(x, y));
}

void draw_all_inventory(gestion_t *game, scene_t *scene, game_t *play)
{
    draw_inventory(game, scene, play->view);
    draw_stuff(game, scene, play->view);
    draw_stuff2(game, scene, play->view);
    draw_stat(game, scene, play);
    if (game->inventory->selec == 1)
        kris_clock_foreward(scene, game, 7, scene->objs[7]->sprite);
    if (game->inventory->selec == 2)
        second_clock_foreward(scene, game, 8, scene->objs[8]->sprite);
}

void show_inventory(gestion_t *game, scene_t *scene, game_t *play)
{
    int nb = 0;

    draw_all_inventory(game, scene, play);
    for (int i = 0; i < 11; i++) {
        if (game->inventory->item[i]->nb >= 0) {
            sfText_setString(game->text,
                            to_array(game->inventory->item[i]->nb));
            sfText_setString(game->txt_money, to_array(game->money));
            set_pos_items(game, scene, play->view, get_vectori(nb, i));
            sfRenderWindow_drawSprite(game->window,
                                    scene->objs[i + 9]->sprite, NULL);
            sfRenderWindow_drawSprite(game->window,
                                    scene->objs[21]->sprite, NULL);
            sfRenderWindow_drawText(game->window, game->text, NULL);
            sfRenderWindow_drawText(game->window, game->txt_money, NULL);
            nb++;
        }
    }
}

void inventory(gestion_t *game, scene_t *scene, game_t *play)
{
    if (game->inventory->tab == 2)
        game->inventory->tab = 0;
    else if (game->inventory->tab == 1)
        show_inventory(game, scene, play);
}