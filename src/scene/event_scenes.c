/*
** EPITECH PROJECT, 2019
** event
** File description:
** event
*/

#include "rpg.h"
#include "map.h"

void event_end(gestion_t *game, scene_t *scene)
{
    static int i = 0;

    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed)
        i = press_button(game, scene, 1);
    if (game->event.type == sfEvtMouseButtonReleased && scene->click) {
        if (button_is_clicked(scene->buttons[i],
                            game->event.mouseButton.x,
                            game->event.mouseButton.y))
            scene->buttons[i]->callback(game, scene);
        scene->objs[i]->rect = get_rect(0, 0, 640, 210);
        sfSprite_setTextureRect(scene->objs[i]->sprite, scene->objs[i]->rect);
        scene->click = 0;
    }
}

void event_pause(gestion_t *game, scene_t *scene)
{
    static int i = 0;

    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed)
        i = press_button(game, scene, 3);
    if (game->event.type == sfEvtMouseButtonReleased && scene->click) {
        if (button_is_clicked(scene->buttons[i],
                                game->event.mouseButton.x,
                                game->event.mouseButton.y))
            scene->buttons[i]->callback(game, scene);
        scene->objs[i]->rect = get_rect(0, 0, 640, 210);
        sfSprite_setTextureRect(scene->objs[i]->sprite, scene->objs[i]->rect);
        scene->click = 0;
    }
}

void event_start(gestion_t *game, scene_t *scene)
{
    static int i = 0;

    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtMouseButtonPressed)
        i = press_button(game, scene, 2);
    if (game->event.type == sfEvtMouseButtonReleased && scene->click) {
        if (button_is_clicked(scene->buttons[i],
                            game->event.mouseButton.x,
                            game->event.mouseButton.y))
            scene->buttons[i]->callback(game, scene);
        scene->objs[i]->rect = get_rect(0, 0, 640, 210);
        sfSprite_setTextureRect(scene->objs[i]->sprite, scene->objs[i]->rect);
        scene->click = 0;
    }
}

void analyse_events(gestion_t *game, scene_t *scene)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->current_scene == 0)
            event_start(game, scene);
        if (game->current_scene == 2)
            event_pause(game, scene);
        if (game->current_scene == 3)
            event_end(game, scene);
    }
}
