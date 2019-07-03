/*
** EPITECH PROJECT, 2019
** fight
** File description:
** a fight
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include "my.h"

void fight_2(fight2_t *fig, sfRenderWindow *window)
{
    sfVector2f dim;

    dim.x = 1.6;
    dim.y = 1.6;
    sfSprite_setScale(fig->kris.f_pers, dim);
    sfSprite_setScale(fig->kris_2.f_pers, dim);
    fill_text(fig);
    sfText_setString(fig->tex_ene, fig->str);
    fill_hero(fig);
    sfText_setString(fig->tex, fig->str_hero);
    fill_mana(fig);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, fig->f_back, NULL);
    fig->time = sfClock_getElapsedTime(fig->cloque);
    fig->time2 = sfClock_getElapsedTime(fig->cloque2);
    fig->time3 = sfClock_getElapsedTime(fig->cloque3);
}

void fight_3(fight2_t *fig, sfRenderWindow *window)
{
    sfVector2f sca;
    sfVector2f bak;

    bak.x = 250;
    bak.y = 550;
    sca.x = 390;
    sca.y = 180;
    verif_replace(fig);
    if (fig->hero == 0) {
        sfSprite_setPosition(fig->kris.f_pers, sca);
        sfSprite_setPosition(fig->kris_2.f_pers, bak);
    }
    sca.x = 250;
    bak.x = 370;
    if (fig->hero == 1) {
        sfSprite_setPosition(fig->kris.f_pers, sca);
        sfSprite_setPosition(fig->kris_2.f_pers, bak);
    }
    fig->str = malloc(200);
    fig->str_hero = malloc(300);
    fight_2(fig, window);
}

void enemies_atk(fight2_t *fig, sfRenderWindow *window)
{
    enemies_atk1(fig, window);
    if (fig->kris.hp <= 0)
        fig->kris.name = NULL;
    if (fig->kris_2.hp <= 0)
        fig->kris_2.name = NULL;
    change_hero(fig, window);
}

int fight_nex(fight2_t *fig, sfRenderWindow *window, int lvl)
{
    sfEvent event;
    sfClock *limit;
    sfTime timer;
    int lim = 0;

    fight_4(fig, window, lvl);
    limit = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        if (fight_5(fig, window) != 0)
            return (fight_5(fig, window));
        if (fig->hero == 2)
            fig->hero = 3;
        play_event(window, fig, lim);
        if (fig->hero == 3) {
            lim = pp2(lim, limit);
            timer = sfClock_getElapsedTime(limit);
            if (timer.microseconds > 700000)
                lim = fight_6(fig, window, lim);
        }
        draw_and_free(window, fig);
    }
}

int fight(fight2_t *fig, sfRenderWindow *window, int lvl)
{
    int ret = 0;

    fig->money = 0;
    ret = fight_nex(fig, window, lvl);
    if (lvl == 1)
        fig->money += 15;
    if (lvl == 2)
        fig->money += 20;
    if (lvl == 3)
        fig->money += 25;
    sfMusic_destroy(fig->zic);
    sfMusic_destroy(fig->select);
    return (ret);
}
