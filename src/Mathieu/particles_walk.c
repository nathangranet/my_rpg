/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particles
*/

#include <map.h>

void walk_right(sfRenderWindow *window, game_t *game, int i)
{
    sfVector2f vi = sfView_getCenter(game->view);

    game->walk[i].position.x -= rand() % 10;
    game->walk[i].position.y -= rand() % 5 - 1;
    vi.x += 15 + game->walk[i].position.x;
    vi.y += 130 + game->walk[i].position.y;
    (game->walk[i].position.x <= -90) ? game->walk[i].position.x = -10: 0;
    (game->walk[i].position.y <= -30) ? game->walk[i].position.y = 0: 0;
    (game->walk[i].position.y >= 100) ? game->walk[i].position.y = 0: 0;
    sfSprite_setPosition(game->walk[i].sprite, vi);
    sfRenderWindow_drawSprite(window, game->walk[i].sprite, NULL);
}

void walk_left(sfRenderWindow *window, game_t *game, int i)
{
    sfVector2f vi = sfView_getCenter(game->view);

    game->walk[i].position.x += rand() % 10;
    game->walk[i].position.y -= rand() % 5 - 1;
    vi.x += 65 + game->walk[i].position.x;
    vi.y += 130 + game->walk[i].position.y;
    (game->walk[i].position.x >= 90) ? game->walk[i].position.x = 10: 0;
    (game->walk[i].position.y <= -30) ? game->walk[i].position.y = 0: 0;
    (game->walk[i].position.y >= 100) ? game->walk[i].position.y = 0: 0;
    sfSprite_setPosition(game->walk[i].sprite, vi);
    sfRenderWindow_drawSprite(window, game->walk[i].sprite, NULL);
}

void walk_down(sfRenderWindow *window, game_t *game, int i)
{
    sfVector2f vi = sfView_getCenter(game->view);

    game->walk[i].position.y -= rand() % 10;
    game->walk[i].position.x -= rand() % 5 - 1;
    vi.x += 65 + game->walk[i].position.x;
    vi.y += 130 + game->walk[i].position.y;
    (game->walk[i].position.y <= -90) ? game->walk[i].position.y = -10: 0;
    (game->walk[i].position.x <= -30) ? game->walk[i].position.x = 0: 0;
    (game->walk[i].position.x >= 100) ? game->walk[i].position.x = 0: 0;
    sfSprite_setPosition(game->walk[i].sprite, vi);
    sfRenderWindow_drawSprite(window, game->walk[i].sprite, NULL);
}

void walk_up(sfRenderWindow *window, game_t *game, int i)
{
    sfVector2f vi = sfView_getCenter(game->view);

    game->walk[i].position.y += rand() % 10;
    game->walk[i].position.x -= rand() % 5 - 1;
    vi.x += 65 + game->walk[i].position.x;
    vi.y += 130 + game->walk[i].position.y;
    (game->walk[i].position.y >= 90) ? game->walk[i].position.y = 10: 0;
    (game->walk[i].position.x <= -30) ? game->walk[i].position.x = 0: 0;
    (game->walk[i].position.x >= 100) ? game->walk[i].position.x = 0: 0;
    sfSprite_setPosition(game->walk[i].sprite, vi);
    sfRenderWindow_drawSprite(window, game->walk[i].sprite, NULL);
}