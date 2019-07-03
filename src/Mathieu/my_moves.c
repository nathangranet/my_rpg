/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "map.h"
#include "rpg.h"

void change_map(game_t *game, int mv)
{
    game->map[game->x][game->y] = '*';
    if (mv == 1) {
        game->map[game->x - 1][game->y] = 'P';
        game->x--;
    }
    if (mv == 2) {
        game->map[game->x + 1][game->y] = 'P';
        game->x++;
    }
    if (mv == 3) {
        game->map[game->x][game->y - 1] = 'P';
        game->y--;
    }
    if (mv == 4) {
        game->map[game->x][game->y + 1] = 'P';
        game->y++;
    }
}

int map_move(game_t *game, int mv)
{
    if (mv == 1 && game->map[game->x - 1][game->y] == '*') {
        (game->map[15][1] == 'P' && game->key_status == 0) ?
            sfMusic_play(game->need_key) : 0;
        change_map(game, mv);
        return (0);
    }
    if (mv == 2 && game->map[game->x + 1][game->y] == '*') {
        change_map(game, mv);
        return (0);
    }
    if (mv == 3 && game->map[game->x][game->y - 1] == '*') {
        change_map(game, mv);
        return (0);
    }
    if (mv == 4 && game->map[game->x][game->y + 1] == '*') {
        change_map(game, mv);
        return (0);
    }
    return (1);
}

void make_moves(sfRenderWindow *window, game_t *game, sfView *view)
{
    if (game->moves.up > 0) {
        sfView_move(view, getvector(0, -5));
        player_rect(game, 432);
        game->moves.up--;
    }
    if (game->moves.down > 0) {
        sfView_move(view, getvector(0, 5));
        player_rect(game, 0);
        game->moves.down--;
    }
    if (game->moves.right > 0) {
        sfView_move(view, getvector(5, 0));
        player_rect(game, 288);
        game->moves.right--;
    }
    if (game->moves.left > 0) {
        sfView_move(view, getvector(-5, 0));
        player_rect(game, 144);
        game->moves.left--;
    }
}

void move(sfRenderWindow *window, game_t *game, sfView *view)
{
    if (game->moves.up <= 0 && game->moves.down <= 0
        && game->moves.left <= 0 && game->moves.right <= 0) {
        game->moves.up = (sfKeyboard_isKeyPressed(sfKeyUp)
        && map_move(game, 1) == 0) ? 26 : 0;
        game->moves.down = (sfKeyboard_isKeyPressed(sfKeyDown)
        && map_move(game, 2) == 0) ? 26 : 0;
        game->moves.right = (sfKeyboard_isKeyPressed(sfKeyRight)
        && map_move(game, 4) == 0) ? 26 : 0;
        game->moves.left = (sfKeyboard_isKeyPressed(sfKeyLeft)
        && map_move(game, 3) == 0) ? 26 : 0;
    }
    make_moves(window, game, view);
}