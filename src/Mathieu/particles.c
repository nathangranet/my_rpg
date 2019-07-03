/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particles
*/

#include <map.h>

void fall_rain(sfRenderWindow *window, game_t *game, int i)
{
    sfVector2f vi = sfView_getCenter(game->view);

    game->rain[i].position.y += rand() % 20;
    game->rain[i].position.x -= rand() % 3;
    vi.x += game->rain[i].position.x - 960;
    vi.y += game->rain[i].position.y - 540;
    (game->rain[i].position.y >= 1200) ? game->rain[i].position.y = 0: 0;
    (game->rain[i].position.x <= 0) ? game->rain[i].position.x = 1920: 0;
    sfSprite_setPosition(game->rain[i].sprite, vi);
}

void rain(sfRenderWindow *window, game_t *game)
{
        for (int i = 0; i != 50; i++)
            fall_rain(window, game, i);
    for (int i = 0; i != 50; i++)
        sfRenderWindow_drawSprite(window, game->rain[i].sprite, NULL);
}

void choose_walk1(sfRenderWindow *window, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)
        && game->map[game->x][game->y + 1] == '*') {
            for (int i = 0; i != 3; i++)
                    walk_right(window, game, i);
            sfClock_restart(game->clockw);
        }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)
        && game->map[game->x][game->y - 1] == '*') {
        for (int i = 0; i != 3; i++)
                walk_left(window, game, i);
        sfClock_restart(game->clockw);
    }
}

void choose_walk2(sfRenderWindow *window, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)
        && game->map[game->x - 1][game->y] == '*') {
        for (int i = 0; i != 3; i++)
            walk_up(window, game, i);
        sfClock_restart(game->clockw);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)
        && game->map[game->x + 1][game->y] == '*') {
        for (int i = 0; i != 3; i++)
            walk_down(window, game, i);
        sfClock_restart(game->clockw);
    }
}

void walk(sfRenderWindow *window, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clockw);
    float seconds = time.microseconds / 1000000.0;

    if  (seconds >= 0.015) {
        choose_walk1(window, game);
        choose_walk2(window, game);
    }
}