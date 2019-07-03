/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "map.h"
#include "rpg.h"

void change_rects(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocke);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.15) {
        (game->santa.alive == 1) ? change_rect(&game->santa.rect, 2592, 288): 0;
        sfSprite_setTextureRect(game->santa.sprite, game->santa.rect);
        (game->mino.alive == 1) ? change_rect(&game->mino.rect, 1440, 288) : 0;
        sfSprite_setTextureRect(game->mino.sprite, game->mino.rect);
        (game->cycl.alive == 1) ? change_rect(&game->cycl.rect, 2688, 192) : 0;
        sfSprite_setTextureRect(game->cycl.sprite, game->cycl.rect);
        (game->glad.alive == 1) ? change_rect(&game->glad.rect, 384, 96) : 0;
        sfSprite_setTextureRect(game->glad.sprite, game->glad.rect);
        sfClock_restart(game->clocke);
    }
}

void is_alive(game_t *game)
{
    if (game->santa.alive == 0)
        sfSprite_setTextureRect(game->santa.sprite, getirect(2880, 0, 90, 288));
    if (game->mino.alive == 0)
        sfSprite_setTextureRect(game->mino.sprite, getirect(1728, 0, 200, 288));
    if (game->cycl.alive == 0)
        sfSprite_setTextureRect(game->cycl.sprite, getirect(2880, 0, 192, 192));
    if (game->glad.alive == 0)
        sfSprite_setTextureRect(game->glad.sprite, getirect(480, 0, 96, 96));
}

void is_fight2(game_t *game, sfRenderWindow *window, gestion_t *gest)
{
    if (game->map[13][10] == 'P' && sfKeyboard_isKeyPressed(sfKeySpace)
        && game->cycl.alive == 1) {
        sfMusic_play(game->music_cycl);
        launch_fight(window, game, 3);
        game->cycl.alive = 0;
        game->map[12][10] = '*';
        gest->money += 30;
    }
    if (game->map[5][14] == 'P' && sfKeyboard_isKeyPressed(sfKeySpace)
        && game->glad.alive == 1) {
        sfMusic_play(game->music_glad);
        launch_fight(window, game, 4);
        game->glad.alive = 0;
        game->map[5][13] = '*';
        gest->money += 50;
    }
}

void is_fight(game_t *game, sfRenderWindow *window, gestion_t *gest)
{
    if (game->map[11][14] == 'P' && sfKeyboard_isKeyPressed(sfKeySpace)
        && game->santa.alive == 1) {
        sfMusic_play(game->music_santa);
        launch_fight(window, game, 1);
        game->santa.alive = 0;
        game->map[11][13] = '*';
        gest->money += 25;
    }
    if (game->map[6][4] == 'P' && sfKeyboard_isKeyPressed(sfKeySpace)
        && game->mino.alive == 1) {
        sfMusic_play(game->music_mino);
        launch_fight(window, game, 2);
        game->mino.alive = 0;
        game->map[6][3] = '*';
        gest->money += 40;
    }
    is_fight2(game, window, gest);
}

void ennemies(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    change_rects(game);
    is_alive(game);
    is_fight(game, window, gest);
    sfRenderWindow_drawSprite(window, game->santa.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->mino.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->cycl.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->glad.sprite, NULL);
}
