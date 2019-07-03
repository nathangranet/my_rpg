/*
** EPITECH PROJECT, 2019
** anim kris
** File description:
** animation of kris
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

int kris_cast(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris.f_rect.top = 220;
        fig->kris.f_rect.left = 300;
        fig->kris.f_rect.height = 100;
        fig->kris.f_rect.width = 140;
        ini = 1;
    }
    if (fig->time.microseconds > 600000) {
        fig->kris.f_rect.left += 150;
        if (fig->kris.f_rect.left > 500) {
            ini = 0;
            fig->kris.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque);
    }
    sfSprite_setTextureRect(fig->kris.f_pers, fig->kris.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
    return (6);
}

int anim_ene1(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->ene1.f_rect.top = 0;
        fig->ene1.f_rect.left = 0;
        fig->ene1.f_rect.height = 135;
        fig->ene1.f_rect.width = 140;
        ini = 1;
    }
    if (fig->time3.microseconds > 140000) {
        if (fig->ene1.f_rect.top == 0)
            fig->ene1.f_rect.top += 130;
        else if (fig->ene1.f_rect.top == 130)
            fig->ene1.f_rect.top -= 130;
        sfClock_restart(fig->cloque3);
    }
    sfSprite_setTextureRect(fig->ene1.f_pers, fig->ene1.f_rect);
    sfRenderWindow_drawSprite(window, fig->ene1.f_pers, NULL);
}

void item21(fight2_t *fig)
{
    if (fig->kris_2.item == 3) {
        fig->kris_2.item = 0;
        if (fig->f1 == 1)
            fig->ene1.hp = fig->ene1.hp - 15 + fig->ene1.def;
        else if (fig->f3 == 1)
            fig->ene3.hp = fig->ene3.hp - 15 + fig->ene1.def;
        else if (fig->f2 == 1)
            fig->ene2.hp = fig->ene2.hp - 15 + fig->ene1.def;
        if (fig->ene1.hp <= 0)
            fig->ene1.name = NULL;
        if (fig->ene2.hp <= 0)
            fig->ene2.name = NULL;
        if (fig->ene3.hp <= 0)
            fig->ene3.name = NULL;
    }
}

void item2(fight2_t *fig)
{
    if (fig->kris_2.item == 1) {
        fig->kris_2.item = 0;
        fig->kris_2.hp += 10;
    }
    if (fig->kris_2.item == 2) {
        fig->kris_2.item = 0;
        fig->mana += 13;
    }
    item21(fig);
}
