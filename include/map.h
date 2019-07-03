/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map.h
*/

#ifndef __MAP_H_
#define __MAP_H_

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "my.h"

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f offset;
    sfVector2f position;
    sfIntRect rect;
    int alive;
} sprite_t;

typedef struct moves_s {
    int up;
    int down;
    int left;
    int right;
} moves_t;

typedef struct game_s {
    fight2_t *fig;
    sprite_t rain[50];
    sprite_t walk[3];
    sfView *view;
    sprite_t background;
    sprite_t wall;
    sprite_t player;
    sprite_t santa;
    sfMusic *music_santa;
    sprite_t cycl;
    sfMusic *music_cycl;
    sprite_t mino;
    sfMusic *music_mino;
    sprite_t glad;
    sfMusic *music_glad;
    sprite_t boss;
    sfMusic *music_boss;
    sprite_t door;
    sfMusic *music_door;
    sprite_t gate;
    sprite_t key;
    int key_i;
    sprite_t gold1;
    sprite_t gold2;
    sprite_t lever;
    sfMusic *music_switch;
    sfMusic *need_key;
    sfMusic *pickup;
    sfMusic *music;
    sfText *quest;
    sfClock *clocka;
    sfClock *clockb;
    sfClock *clocke;
    sfClock *clockt;
    sfClock *clockf;
    sfClock *clockw;
    sfText *fight_text;
    moves_t moves;
    char **map;
    int win;
    int alive;
    int x;
    int y;
    int gate_status;
    int key_status;
    int gold1_status;
    int gold2_status;
} game_t;

sfFloatRect getfrect(int x, int y, int width, int height);
sfIntRect getirect(int x, int y, int width, int height);
sfVector2f getvector(int x, int y);
moves_t get_moves(int up, int down, int left, int right);
char *create_line(char *src);
char *create_line(char *src);
sprite_t init_sprite(char *texture);
game_t *init_game(void);
void create_map(char **);
void player_rect(game_t *game, int y);
void close_when_escape(sfRenderWindow *window, sfEvent event);
sfRenderWindow *createwindow(int width, int height);
void move(sfRenderWindow *window, game_t *game, sfView *view);
void change_rect(sfIntRect *rect, int max, int add);
void wall(sfRenderWindow *window, game_t *game);
void print_message(sfRenderWindow *window, game_t *game, char *str);
int fight(fight2_t *fig, sfRenderWindow *window, int lvl);
void boss(sfRenderWindow *window, game_t *game);
void launch_fight(sfRenderWindow *window, game_t *game, int nb);
void rain(sfRenderWindow *window, game_t *game);
void walk(sfRenderWindow *window, game_t *game);
void walk_right(sfRenderWindow *window, game_t *game, int i);
void walk_left(sfRenderWindow *window, game_t *game, int i);
void walk_up(sfRenderWindow *window, game_t *game, int i);
void walk_down(sfRenderWindow *window, game_t *game, int i);
void init_settings(game_t *game);

#endif
