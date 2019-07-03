/*
** EPITECH PROJECT, 2019
** game_win
** File description:
** game_win
*/

#include "map.h"
#include "rpg.h"

void game_win(gestion_t *gest, game_t *game, scene_t *scene)
{
    while (sfRenderWindow_pollEvent(gest->window, &gest->event)) {
        if (gest->event.type == sfEvtClosed)
            sfRenderWindow_close(gest->window);
    }
    sfRenderWindow_clear(gest->window, sfBlack);
    sfRenderWindow_drawSprite(gest->window, scene->objs[3]->sprite, NULL);
    sfRenderWindow_display(gest->window);
}

sfCircleShape **init_circle(void)
{
    sfCircleShape **circle = malloc(sizeof(*circle) * 2);
    circle[0] = sfCircleShape_create();
    circle[1] = sfCircleShape_create();
    sfCircleShape_setPosition(circle[0], get_vector(0, 0));
    sfCircleShape_setRadius(circle[0], 80);
    sfCircleShape_setPosition(circle[1], get_vector(0, 300));
    sfCircleShape_setRadius(circle[1], 80);
    return (circle);
}

void kris_clock_foreward(scene_t *kris, gestion_t *game, int nb, sfSprite *s)
{
    game->time = sfClock_getElapsedTime(game->clock);
    if (game->time.microseconds > 100000) {
        sfClock_restart(game->clock);
        kris->objs[nb]->rect.left += 50;
        if (kris->objs[nb]->rect.left == 200)
            kris->objs[nb]->rect.left = 0;
        sfSprite_setTextureRect(s, kris->objs[nb]->rect);
    }
}

void selec_character(gestion_t *game, scene_t *scene, sfView *view)
{
    float m, n;
    sfFloatRect rect1, rect2;

    m = game->event.mouseButton.x + sfView_getCenter(view).x - 960;
    n = game->event.mouseButton.y + sfView_getCenter(view).y - 540;
    rect1 = sfCircleShape_getGlobalBounds(game->circle[0]);
    rect2 = sfCircleShape_getGlobalBounds(game->circle[1]);

    if (sfFloatRect_contains(&rect1, m, n))
            game->inventory->selec = 1;
    if (sfFloatRect_contains(&rect2, m, n))
            game->inventory->selec = 2;
}