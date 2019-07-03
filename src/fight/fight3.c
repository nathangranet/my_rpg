/*
** EPITECH PROJECT, 2019
** fight3
** File description:
** a fight3
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

int kris_atk(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris.f_rect.top = 335;
        fig->kris.f_rect.left = 100;
        fig->kris.f_rect.height = 120;
        fig->kris.f_rect.width = 145;
        ini = 1;
    }
    if (fig->time.microseconds > 100000) {
        fig->kris.f_rect.left += 155;
        if (fig->kris.f_rect.left == 1030) {
            ini = 0;
            fig->kris.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque);
    }
    sfSprite_setTextureRect(fig->kris.f_pers, fig->kris.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
    return (1);
}

int kris_use(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris.f_rect.top = 455;
        fig->kris.f_rect.left = 325;
        fig->kris.f_rect.height = 100;
        ini = 1;
    }
    if (fig->time.microseconds > 120000) {
        fig->kris.f_rect.left += 149;
        if (fig->kris.f_rect.left == 1368) {
            ini = 0;
            fig->kris.f_rect.left = 0;
            return (0);
        }
        sfClock_restart(fig->cloque);
    }
    sfSprite_setTextureRect(fig->kris.f_pers, fig->kris.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
    return (2);
}

int fill_text1(fight2_t *fig, int nb)
{
    if (fig->ene1.name != NULL) {
        for (int con = 0; fig->ene1.name[con] != '\0'; con++) {
            fig->str[nb] = fig->ene1.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str[nb] = ' ';
            jh++;
        }
        if (fig->ene1.hp >= 10) {
            fig->str[nb] = fig->ene1.hp / 10 + 48;
            nb++;
        }
        fig->str[nb] = fig->ene1.hp % 10 + 48;
        nb++;
        if (fig->f1 == 1)
            fig->str[fig->pos_f1] = '>';
    }
    return (nb);
}

int fill_text2(fight2_t *fig, int nb)
{
    if (fig->ene2.name != NULL) {
        for (int con = 0; fig->ene2.name[con] != '\0'; con++) {
            fig->str[nb] = fig->ene2.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str[nb] = ' ';
            jh++;
        }
        if (fig->ene2.hp >= 10) {
            fig->str[nb] = fig->ene2.hp / 10 + 48;
            nb++;
        }
        fig->str[nb] = fig->ene2.hp % 10 + 48;
        nb++;
        if (fig->f2 == 1)
            fig->str[fig->pos_f2] = '>';
    }
    return (nb);
}

int fill_text3(fight2_t *fig, int nb)
{
    if (fig->ene3.name != NULL) {
        for (int con = 0; fig->ene3.name[con] != '\0'; con++) {
            fig->str[nb] = fig->ene3.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str[nb] = ' ';
            jh++;
        }
        if (fig->ene3.hp >= 10) {
            fig->str[nb] = fig->ene3.hp / 10 + 48;
            nb++;
        }
        fig->str[nb] = fig->ene3.hp % 10 + 48;
        nb++;
        if (fig->f3 == 1)
            fig->str[fig->pos_f3] = '>';
    }
    return (nb);
}
