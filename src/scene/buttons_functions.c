/*
** EPITECH PROJECT, 2019
** buttons functions
** File description:
** buttons functions
*/

#include "rpg.h"
#include "map.h"

void previous_scene(gestion_t *game)
{
    sfMusic_play(game->music);
    game->current_scene--;
}

void close_window(gestion_t *game)
{
    sfMusic_play(game->music);
    sfRenderWindow_close(game->window);
}

void next_scene(gestion_t *game)
{
    sfMusic_play(game->music);
    game->current_scene++;

    if (game->current_scene == 3 || game->current_scene == 4) {
        game->current_scene = 0;
        game->reset = 1;
    }
}