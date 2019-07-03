/*
** EPITECH PROJECT, 2019
** Mathieu
** File description:
** init3
*/

#include "map.h"
#include "rpg.h"

void init_settings2(game_t *game)
{
    game->player = init_sprite("ressources/map/player.png");
    game->player.rect = getirect(0, 0, 104, 144);
    sfSprite_setTextureRect(game->player.sprite, game->player.rect);
    game->win = 0;
    game->x = 15;
    game->y = 1;
    game->quest = sfText_create();
    game->fight_text = sfText_create();
    sfFont *font = sfFont_createFromFile("ressources/map/JAGUAR.ttf");
    sfText_setCharacterSize(game->fight_text, 40);
    sfText_setFont(game->fight_text, font);
    sfText_setFont(game->quest, font);
}

void init_settings(game_t *game)
{
    game->map = malloc(sizeof(char *) * 18);
    create_map(game->map);
    game->clocka = sfClock_create();
    game->clockb = sfClock_create();
    game->clocke = sfClock_create();
    game->clockt = sfClock_create();
    game->clockf = sfClock_create();
    game->clockw = sfClock_create();
    game->moves = get_moves(0, 0, 0, 0);
    game->alive = 1;
    game->gate_status = 0;
    game->key_status = 0;
    game->key_i = 0;
    game->gold1_status = 0;
    game->gold2_status = 0;
    init_settings2(game);
}