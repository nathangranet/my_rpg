/*
** EPITECH PROJECT, 2019
** inventory_click_item
** File description:
** inventory_click_item
*/

#include "rpg.h"
#include "map.h"

void use_items_second(gestion_t *game, scene_t *scene, sfView *view, int i)
{
    float x, y;
    sfFloatRect rect;
    rect = sfSprite_getGlobalBounds(scene->objs[i + 9]->sprite);
    rect.top -= 70;
    x = game->event.mouseButton.x + sfView_getCenter(view).x - 960;
    y = game->event.mouseButton.y + sfView_getCenter(view).y - 540;
    if (sfFloatRect_contains(&rect, x, y)) {
        game->inventory->item[i]->nb--;
        if (game->inventory->selec == 1)
            game->inventory->item[i]->function
                (game, scene, game->inventory->stuff, i);
        if (game->inventory->selec == 2)
            game->inventory->item[i]->function
                (game, scene, game->inventory->stuff2, i);
    }
}

void use_items(gestion_t *game, scene_t *scene, sfView *view)
{
    for (int i = 0; i < 11; i++) {
        if (game->inventory->item[i]->nb > 0)
            use_items_second(game, scene, view, i);
    }
}

int check_pos(gestion_t *game, scene_t *scene)
{
    if (game->event.mouseButton.x > game->inventory->x + 5)
        return (0);
    if (game->event.mouseButton.x < game->inventory->x - 5)
        return (0);
    if (game->event.mouseButton.y > game->inventory->y + 5)
        return (0);
    if (game->event.mouseButton.y < game->inventory->y - 5)
        return (0);
    return (1);
}

void check_double_click(gestion_t *game, scene_t *scene, sfView *view)
{
    sfTime time = sfClock_getElapsedTime(game->inventory->clock);
    float seconds = time.microseconds / 1000000.0;
    if (seconds < 0.3 && check_pos(game, scene))
        use_items(game, scene, view);
    else {
        sfClock_restart(game->inventory->clock);
        game->inventory->x = game->event.mouseButton.x;
        game->inventory->y = game->event.mouseButton.y;
    }
}

void inventory_event(gestion_t *game, scene_t *scene, sfView *view)
{
    static int test = 0;

    if (game->event.type == sfEvtMouseButtonPressed) {
        selec_character(game, scene, view);
        check_double_click(game, scene, view);
    }
    if (sfKeyboard_isKeyPressed(sfKeyB) && test == 0) {
        buy_inventory(game, scene, view);
        test++;
    }
    else if (test == 1)
        test = 0;
}
