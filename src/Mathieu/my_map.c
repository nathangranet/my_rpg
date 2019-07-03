/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "map.h"
#include "rpg.h"

void event_game(gestion_t *game, scene_t *scene, sfView* view)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->inventory->tab)
            inventory_event(game, scene, view);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            game->current_scene = 2;
        if ((game->event.type == sfEvtKeyPressed)
            && (game->event.key.code == sfKeyTab))
            game->inventory->tab++;
    }
}

void player(sfRenderWindow *window, sfView *view, game_t *game)
{
    sfVector2f pos = sfView_getCenter(view);

    sfSprite_setTextureRect(game->player.sprite, game->player.rect);
    sfSprite_setPosition(game->player.sprite, pos);
    sfRenderWindow_drawSprite(window, game->player.sprite, NULL);
}

void quest(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    static int quest = 0;
    sfVector2f vi = sfView_getCenter(game->view);

    vi.x -= 800;
    vi.y -= 530;
    if (gest->inventory->tab == 0)
        vi.x -= 140;
    sfText_setPosition(game->quest, vi);
    sfRenderWindow_drawText(window, game->quest, NULL);
    if (game->key_i <= 1)
        sfRenderWindow_drawSprite(window, game->key.sprite, NULL);
}

void aug_stat(gestion_t *gest, game_t *game)
{
    game->fig->kris.atk = 5 + gest->inventory->stuff[0]->bonus;
    game->fig->kris.def = 2 + gest->inventory->stuff[2]->bonus;
    game->fig->kris.conc = 3 + gest->inventory->stuff[1]->bonus;
    game->fig->kris_2.atk = 4 + gest->inventory->stuff2[0]->bonus;
    game->fig->kris_2.def = 3 + gest->inventory->stuff2[2]->bonus;
    game->fig->kris_2.conc = 5 + gest->inventory->stuff2[1]->bonus;
}

int my_map(gestion_t *gest, scene_t *scene, game_t *game)
{
    event_game(gest, scene, game->view);
    background(gest->window, game, gest);
    move(gest->window, game, game->view);
    doors(gest->window, game, gest);
    boss(gest->window, game);
    ennemies(gest->window, game, gest);
    walk(gest->window, game);
    player(gest->window, game->view, game);
    wall(gest->window, game);
    inventory(gest, scene, game);
    quest(gest->window, game, gest);
    rain(gest->window, game);
    aug_stat(gest, game);
    sfRenderWindow_display(gest->window);
    sfRenderWindow_setView(gest->window, game->view);
    sfRenderWindow_clear(gest->window, sfBlack);
    return (0);
}
