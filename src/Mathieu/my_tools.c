/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** my_tools
*/

#include "map.h"
#include "rpg.h"

sfFloatRect getfrect(int x, int y, int width, int height)
{
    sfFloatRect rect;

    rect.top = y;
    rect.left = x;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfIntRect getirect(int x, int y, int width, int height)
{
    sfIntRect rect;

    rect.top = y;
    rect.left = x;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfVector2f getvector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

moves_t get_moves(int up, int down, int left, int right)
{
    moves_t moves;

    moves.up = up;
    moves.down = down;
    moves.right = right;
    moves.left = left;
    return (moves);
}

void draw_door_sprites(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    sfVector2f vi = sfView_getCenter(game->view);

    sfRenderWindow_drawSprite(window, game->door.sprite, NULL);
    if (game->key_i == 1) {
        vi.x -= 800;
        vi.y -= 480;
        if (gest->inventory->tab == 0)
            vi.x -= 140;
        sfSprite_setPosition(game->key.sprite, vi);
    }
    sfRenderWindow_drawSprite(window, game->lever.sprite, NULL);
}