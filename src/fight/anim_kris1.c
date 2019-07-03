/*
** EPITECH PROJECT, 2019
** fight
** File description:
** the six fight
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

void anim_kris1(fight2_t *fig, sfRenderWindow *window)
{
    fig->kris_2.f_rect.top = 0;
    fig->kris_2.f_rect.width = 100;
    fig->kris_2.f_rect.height = 110;
    if (fig->time2.microseconds > 180000) {
        fig->kris_2.f_rect.left += 123;
        if (fig->kris_2.f_rect.left == 615)
            fig->kris_2.f_rect.left = 0;
        sfClock_restart(fig->cloque2);
    }
    sfSprite_setTextureRect(fig->kris_2.f_pers, fig->kris_2.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris_2.f_pers, NULL);
}

int kris_atk1(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris_2.f_rect.top = 330;
        fig->kris_2.f_rect.left = 830;
        fig->kris_2.f_rect.height = 120;
        fig->kris_2.f_rect.width = 180;
        ini = 1;
    }
    if (fig->time2.microseconds > 100000) {
        fig->kris_2.f_rect.left += 190;
        if (fig->kris_2.f_rect.left == 1970) {
            ini = 0;
            fig->kris_2.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque2);
    }
    sfSprite_setTextureRect(fig->kris_2.f_pers, fig->kris_2.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris_2.f_pers, NULL);
    return (1);
}

int kris_use1(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris_2.f_rect.top = 920;
        fig->kris_2.f_rect.left = 0;
        fig->kris_2.f_rect.height = 120;
        fig->kris_2.f_rect.width = 180;
        ini = 1;
    }
    if (fig->time2.microseconds > 120000) {
        fig->kris_2.f_rect.left += 180;
        if (fig->kris_2.f_rect.left == 1620) {
            ini = 0;
            fig->kris_2.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque2);
    }
    sfSprite_setTextureRect(fig->kris_2.f_pers, fig->kris_2.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris_2.f_pers, NULL);
    return (2);
}

void kris_def1(sfRenderWindow *window, fight2_t *fig, int lim)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris_2.f_rect.top = 800;
        fig->kris_2.f_rect.left = 0;
        fig->kris_2.f_rect.width = 140;
        fig->kris_2.f_rect.height = 105;
        ini = 1;
    }
    if (fig->time2.microseconds > 70000) {
        if (fig->kris_2.f_rect.left < 1100)
            fig->kris_2.f_rect.left += 168;
        else
            fig->kris_2.f_rect.left -= 168;
        sfClock_restart(fig->cloque2);
    }
    if (fig->hero == 3 && lim == 0)
        ini = 0;
    sfSprite_setTextureRect(fig->kris_2.f_pers, fig->kris_2.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris_2.f_pers, NULL);
}

int kris_cast1(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris_2.f_rect.top = 1050;
        fig->kris_2.f_rect.left = 750;
        fig->kris_2.f_rect.height = 115;
        fig->kris_2.f_rect.width = 140;
        ini = 1;
    }
    if (fig->time2.microseconds > 140000) {
        fig->kris_2.f_rect.left += 137;
        if (fig->kris_2.f_rect.left > 1900) {
            ini = 0;
            fig->kris_2.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque2);
    }
    sfSprite_setTextureRect(fig->kris_2.f_pers, fig->kris_2.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris_2.f_pers, NULL);
    return (6);
}
