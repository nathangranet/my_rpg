/*
** EPITECH PROJECT, 2019
** button
** File description:
** button
*/

#include "rpg.h"
#include "map.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    else
        rect->left = rect->left + offset;
}

int press_button(gestion_t *game, scene_t *scene, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (button_is_clicked(scene->buttons[i],
            game->event.mouseButton.x, game->event.mouseButton.y)) {
            move_rect(&scene->objs[i]->rect, 640, 1920);
            sfSprite_setTextureRect(scene->objs[i]->sprite,
                                    scene->objs[i]->rect);
            scene->click = 1;
            return (i);
        }
    }
    return (0);
}

int button_is_clicked(button_t *button, int x, int y)
{
    int nb;

    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);
    nb = sfFloatRect_contains(&rect, x, y);

    return (nb);
}

void check_button(gestion_t *game, scene_t *scene, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (button_is_clicked(scene->buttons[i],
                game->event.mouseButton.x, game->event.mouseButton.y))
            scene->buttons[i]->callback(game, scene);
    }
}
