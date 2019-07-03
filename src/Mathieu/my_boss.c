/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "map.h"
#include "rpg.h"

void boss_rects(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocke);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.15) {
        (game->boss.alive == 1) ? change_rect(&game->boss.rect, 1072, 268): 0;
        sfSprite_setTextureRect(game->boss.sprite, game->boss.rect);
    }
}

void boss_fight(game_t *game, sfRenderWindow *window)
{
    sfFloatRect player = sfSprite_getGlobalBounds(game->player.sprite);
    sfFloatRect boss = sfSprite_getGlobalBounds(game->boss.sprite);

    boss.left += 100;
    if (game->map[1][3] == 'P' && game->map[2][2] != 'W') {
        sfMusic_play(game->music_boss);
        game->boss.texture = sfTexture_createFromFile("ressources/map/boss.png",
                                                        NULL);
        sfSprite_setTexture(game->boss.sprite, game->boss.texture, sfTrue);
        game->map[2][2] = 'W';
    }
    if (game->map[2][2] == 'W') {
        sfSprite_move(game->boss.sprite, getvector(-10, 0));
        if (sfFloatRect_intersects(&player, &boss, NULL)) {
            fight(game->fig, window, 5);
            game->alive = 0;
        }
    }
}

void boss(sfRenderWindow *window, game_t *game)
{
    boss_rects(game);
    boss_fight(game, window);
    sfRenderWindow_drawSprite(window, game->boss.sprite, NULL);
}

void my_rpg2(game_t *game, gestion_t *gest, scene_t **scenes)
{
    game->fig->f1 = 1;
    game->fig->f2 = 0;
    game->fig->f3 = 0;
    game->fig->cloque3 = sfClock_create();
    game->fig->cloque4 = sfClock_create();
    init_stats(game->fig);
    loop_game(gest, scenes, game);
    destroy_music(gest, game);
}
