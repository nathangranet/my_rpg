/*
** EPITECH PROJECT, 2019
** my
** File description:
** a struct
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "map.h"

typedef struct stats
{
    sfTexture *f_text;
    sfSprite *f_pers;
    sfIntRect f_rect;
    char *name;
    int hp;
    int atk;
    int def;
    int conc;
}stat_t;

typedef struct stuff_s {
    int exist;
    int type;
    int bonus;
    struct object_s *item;
} stuff_t;

typedef struct gestion_s {
    sfCircleShape **circle;
    sfView *view;
    struct inventory_s *inventory;
    sfText **stats;
    sfText *text;
    sfText *txt_money;
    sfIntRect money_rect;
    sfFont *font;
    sfEvent event;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfClock *clock;
    sfClock *clock2;
    sfMusic *music;
    sfTime time;
    sfVector2f move_right;
    sfVector2f move_left;
    sfVector2f move_up;
    sfVector2f move_down;
    sfVector2f stack_pos;
    int current_scene;
    int reset;
    int money;
} gestion_t;

typedef struct scene_s {
    struct object_s **objs;
    struct button_s **buttons;
    int nb_objs;
    int click;
} scene_t;

typedef struct inventory_s {
    struct items_s **item;
    struct stuff_s **stuff;
    struct stuff_s **stuff2;
    int selec;
    int tab;
    int x;
    int y;
    sfClock *clock;
} inventory_t;

typedef struct items_s {
    int nb;
    void (*function)(gestion_t *, scene_t *, stuff_t **, int);
} items_t;

typedef struct button_s {
    sfRectangleShape *rect;
    void (*callback)(gestion_t *, scene_t *);
} button_t;

typedef struct object_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
} object_t;

void selec_character(gestion_t *game, scene_t *scene, sfView *view);
sfCircleShape **init_circle(void);
object_t **get_objs_game(void);
object_t **get_objs_pause(void);
object_t **get_objs_start(void);

void game_win(gestion_t *gest, game_t *game, scene_t *scene);
stuff_t **init_stuff(void);
sfVector2i get_vectori(int x, int y);
int my_map(gestion_t *gest, scene_t *scene, game_t *game);
void give_function_items(items_t **items);
void inventory_event(gestion_t *game, scene_t *scene, sfView *view);
void inventory(gestion_t *game, scene_t *scene, game_t *play);

void add_sword(gestion_t *game, scene_t *scene, stuff_t **stuff, int i);
void add_shield(gestion_t *game, scene_t *scene, stuff_t **stuff, int i);
void add_armor(gestion_t *game, scene_t *scene, stuff_t **stuff, int i);

void draw_inventory(gestion_t *game, scene_t *scene, sfView *view);
void draw_stat2(gestion_t *gest, scene_t *scene, game_t *game);
void draw_stat(gestion_t *gest, scene_t *scene, game_t *game);
void inventory_event(gestion_t *game, scene_t *scene, sfView *view);
void buy_inventory(gestion_t *game, scene_t *scene, sfView *view);
void inventory_event(gestion_t *game, scene_t *scene, sfView *view);
void draw_stuff(gestion_t *game, scene_t *scene, sfView *view);
void draw_stuff2(gestion_t *game, scene_t *scene, sfView *view);

void move_rect(sfIntRect *rect, int offset, int max_value);
int button_is_clicked(button_t *button, int x, int y);
int press_button(gestion_t *game, scene_t *scene, int nb);
void analyse_events(gestion_t *game, scene_t *scene);
void draw_scene(gestion_t *game, scene_t *scene);
void check_button(gestion_t *game, scene_t *scene, int nb);

void next_scene(gestion_t *game);
void previous_scene(gestion_t *game);
void close_window(gestion_t *game);

sfIntRect get_rect(float a, float b, float c, float d);
sfVector2f get_vector(float x, float y);

void kris_clock_foreward(scene_t *, gestion_t *, int, sfSprite *);
void second_clock_foreward(scene_t *, gestion_t *, int , sfSprite *);

scene_t *create_start_scene(void);
scene_t *create_game_scene(void);
scene_t *create_pause_scene(void);
scene_t *create_end_scene(void);

char *to_array(int nb);
object_t *create_object(const char *, sfVector2f, sfIntRect);
void init_button(button_t *, sfVector2f, sfVector2f, void(*ptr));
gestion_t *init_struct(void);

void ennemies(sfRenderWindow *window, game_t *game, gestion_t *gest);
void background(sfRenderWindow *window, game_t *game, gestion_t *gest);
void doors(sfRenderWindow *window, game_t *game, gestion_t *gest);
void draw_door_sprites(sfRenderWindow *window, game_t *game, gestion_t *gest);
void my_rpg2(game_t *game, gestion_t *gest, scene_t **scenes);
void destroy_music(gestion_t *gest, game_t *game);
void loop_game(gestion_t *gest, scene_t **scenes, game_t *game);

#endif
