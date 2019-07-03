/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include "map.h"
#include "rpg.h"

void change_rect(sfIntRect *rect, int max, int add)
{
    if (rect->left >= max)
        rect->left = 0;
    else
        rect->left += add;
}

void background(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    sfRenderWindow_drawSprite(window, game->background.sprite, NULL);
    (game->gold1_status == 0) ?
    sfRenderWindow_drawSprite(window, game->gold1.sprite, NULL) : 0;
    (game->gold2_status == 0) ?
    sfRenderWindow_drawSprite(window, game->gold2.sprite, NULL) : 0;
    if (game->map[11][9] == 'P' && game->gold1_status == 0) {
        sfMusic_play(game->pickup);
        game->gold1_status = 1;
        gest->money += 50;
    }
    if (game->map[6][1] == 'P' && game->gold2_status == 0) {
        sfMusic_play(game->pickup);
        game->gold2_status = 1;
        gest->money += 60;
    }
}

void wall(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->wall.sprite, NULL);
}

void doors2(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    if (game->map[6][7] == 'P' && sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfMusic_play(game->music_switch);
        sfText_setString(game->quest, "Escape !");
        sfSprite_setTextureRect(game->lever.sprite, getirect(60, 0, 60, 88));
        game->map[4][14] = '*';
        game->gate_status = 1;
    }
    if (game->map[13][12] == 'P' && game->key_status == 0) {
        sfMusic_play(game->pickup);
        sfText_setString(game->quest, "Open the door with the key !");
        game->key_status = 1;
        game->key_i = 1;
    }
}

void doors(sfRenderWindow *window, game_t *game, gestion_t *gest)
{
    if (game->gate_status == 0)
        sfRenderWindow_drawSprite(window, game->gate.sprite, NULL);
    if (game->map[14][1] == 'P')
        if (sfKeyboard_isKeyPressed(sfKeySpace) && game->key_status == 1) {
            game->map[13][1] = '*';
            sfMusic_play(game->music_door);
            game->key_i = 2;
            sfText_setString(game->quest, "Turn ON the switch !");
            sfSprite_setTextureRect(game->door.sprite,
                                    getirect(338, 0, 169, 167));
        }
    doors2(window, game, gest);
    draw_door_sprites(window, game, gest);
}