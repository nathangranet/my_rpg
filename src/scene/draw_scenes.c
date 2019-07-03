/*
** EPITECH PROJECT, 2019
** draw scenes
** File description:
** draw scenes
*/

#include "rpg.h"
#include "map.h"

void mouse_on_button(gestion_t *game, scene_t *scene, int nb)
{
    sfVector2i vect;
    vect = sfMouse_getPositionRenderWindow(game->window);
    for (int i = 0; i < nb; i++) {
        if (button_is_clicked(scene->buttons[i], vect.x, vect.y)
            && scene->objs[i]->rect.left == 0) {
            scene->objs[i]->rect = get_rect(640, 0, 640, 210);
            sfSprite_setTextureRect(scene->objs[i]->sprite,
                                    scene->objs[i]->rect);
        }
        else if (scene->click == 0 && !button_is_clicked
                (scene->buttons[i], vect.x, vect.y)
                && scene->objs[i]->rect.left != 0) {
            scene->objs[i]->rect = get_rect(0, 0, 640, 210);
            sfSprite_setTextureRect(scene->objs[i]->sprite,
                                    scene->objs[i]->rect);
        }
    }
}

void draw_end(gestion_t *game, scene_t *scene)
{
    mouse_on_button(game, scene, 1);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, scene->objs[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, scene->objs[0]->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_pause(gestion_t *game, scene_t *scene)
{
    mouse_on_button(game, scene, 3);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, scene->objs[3]->sprite, NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(game->window, scene->objs[i]->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_start(gestion_t *game, scene_t *scene)
{
    mouse_on_button(game, scene, 2);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, scene->objs[2]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, scene->objs[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, scene->objs[1]->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void draw_scene(gestion_t *game, scene_t *scene)
{
    if (game->current_scene == 0)
        draw_start(game, scene);
    if (game->current_scene == 2)
        draw_pause(game, scene);
    if (game->current_scene == 3)
        draw_end(game, scene);
}
