/*
** EPITECH PROJECT, 2019
** my
** File description:
** a struct
*/

#ifndef MENU_H_
#define MENU_H_

typedef struct stats2
{
    sfTexture *f_text;
    sfSprite *f_pers;
    sfIntRect f_rect;
    sfMusic *mus_atk;
    sfMusic *mus_use;
    sfText *tet;
    int dmgs;
    char *name;
    int item;
    int hp;
    int atk;
    int def;
    int conc;
}stat2_t;

typedef struct fight2
{
    int hero;
    int ev;
    int ev1;
    int ev2;
    char *str_hero;
    char *str;
    int pos_f1;
    int pos_f2;
    int pos_f3;
    int f1;
    int f2;
    int f3;
    int act;
    sfText *tex;
    sfText *tex_ene;
    sfText *tex_mana;
    sfClock *cloque;
    sfClock *cloque2;
    sfClock *cloque3;
    sfClock *cloque4;
    sfClock *cloque5;
    sfTime time;
    sfTime time2;
    sfTime time3;
    sfMusic *zic;
    sfMusic *select;
    sfTexture *f_text_back;
    sfSprite *f_back;
    stat2_t kris;
    stat2_t kris_2;
    stat2_t kris_3;
    stat2_t ene1;
    stat2_t ene2;
    stat2_t ene3;
    int mana;
    int def;
    int def2;
    int def3;
    int money;
} fight2_t;

void change_hero2(fight2_t *fig);
void change_hero(fight2_t *fig, sfRenderWindow *window);
void init_things(fight2_t *fig);
int event_handle(sfRenderWindow *window, sfEvent event, int ev);
void anim_kris(fight2_t *fig, sfRenderWindow *window);
int kris_atk(sfRenderWindow *window, fight2_t *fig);
int kris_use(sfRenderWindow *window, fight2_t *fig);
int fill_text1(fight2_t *fig, int nb);
int fill_text2(fight2_t *fig, int nb);
int fill_text3(fight2_t *fig, int nb);
int fill_hero3(fight2_t *fig, int nb);
int fill_hero2(fight2_t *fig, int nb);
int fill_hero1(fight2_t *fig, int nb);
void fill_text(fight2_t *fig);
void fill_mana(fight2_t *fig);
void up_change(fight2_t *fig, sfRenderWindow *window);
int dmg_enemies2(fight2_t *fig);
int dmg_enemies1(fight2_t *fig);
int dmg_enemies(fight2_t *fig);
void fill_hero(fight2_t *fig);
int dmg_enemies(fight2_t *fig);
void anim_kris1(fight2_t *fig, sfRenderWindow *window);
int kris_atk1(sfRenderWindow *window, fight2_t *fig);
int kris_use1(sfRenderWindow *window, fight2_t *fig);
int kris_cast1(sfRenderWindow *window, fight2_t *fig);
int kris_cast(sfRenderWindow *window, fight2_t *fig);
int anim_ene1(sfRenderWindow *window, fight2_t *fig);
int anim_ene2(sfRenderWindow *window, fight2_t *fig);
void kris_def1(sfRenderWindow *window, fight2_t *fig, int lim);
void spell1(fight2_t *fig);
void spell2(fight2_t *fig);
void item1(fight2_t *fig);
void item2(fight2_t *fig);
int fight(fight2_t *fig, sfRenderWindow *window, int lvl);
void init_stats(fight2_t *fig);
void change_hero2(fight2_t *fig);
sfFloatRect getfrect(int x, int y, int width, int height);
void up_change_2(fight2_t *fig, sfRenderWindow *window);
void down_change(fight2_t *fig, sfRenderWindow *window);
void init_enemies3(fight2_t *fig, int lvl, sfVector2f pos);
void init_stats(fight2_t *fig);
void init_text(fight2_t *fig);
void kris_def(sfRenderWindow *window, fight2_t *fig, int lim);
void verif_replace(fight2_t *fig);
void anim_enem1(fight2_t *fig, sfRenderWindow *window, stat2_t *ene1);
void anim_enem2(fight2_t *fig, sfRenderWindow *window, stat2_t *ene1);
void anim_enem3(fight2_t *fig, sfRenderWindow *window, stat2_t *ene1);
int ene_atk1(sfRenderWindow *window, fight2_t *fig);
void init_enemies1(fight2_t *fig, sfVector2f pos);
void init_enemies4(fight2_t *fig, int lvl, sfVector2f pos);
void play_event1(sfRenderWindow *window, fight2_t *fig, int lim);
void play_event2(sfRenderWindow *window, fight2_t *fig, int lim);
int end(fight2_t *fig);
void init_enemies(fight2_t *fig, int lvl);
int play_event(sfRenderWindow *window, fight2_t *fig, int lim);
void enemies_atk(fight2_t *fig, sfRenderWindow *window);
void enemies_atk1(fight2_t *fig, sfRenderWindow *window);
void fight_3(fight2_t *fig, sfRenderWindow *window);
void fight_4(fight2_t *fig, sfRenderWindow *window, int lvl);
int fight_5(fight2_t *fig, sfRenderWindow *window);
int fight_6(fight2_t *fig, sfRenderWindow *window, int lim);
int pp2(int lim, sfClock *limit);
void draw_and_free(sfRenderWindow *window, fight2_t *fig);

#endif
