/*
** EPITECH PROJECT, 2019
** fight4
** File description:
** a fight4
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

int fill_text4(fight2_t *fig, int nb)
{
    fig->pos_f1 = nb;
    for (; nb != 4; nb++)
        fig->str[nb] = ' ';
    nb = fill_text1(fig, nb);
    fig->str[nb] = '\n';
    nb++;
    fig->pos_f2 = nb;
    for (int yu = 0; yu != 4; nb++) {
        fig->str[nb] = ' ';
        yu++;
    }
    return (nb);
}

void fill_text(fight2_t *fig)
{
    int nb = 0;

    nb = fill_text4(fig, nb);
    nb = fill_text2(fig, nb);
    fig->str[nb] = '\n';
    nb++;
    fig->pos_f3 = nb;
    for (int yui = 0; yui != 4; nb++) {
        fig->str[nb] = ' ';
        yui++;
    }
    nb = fill_text3(fig, nb);
    fig->str[nb] = '\0';
}

int fill_hero1(fight2_t *fig, int nb)
{
    if (fig->kris.name != NULL) {
        for (int con = 0; fig->kris.name[con] != '\0'; con++) {
            fig->str_hero[nb] = fig->kris.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str_hero[nb] = ' ';
            jh++;
        }
        if (fig->kris.hp >= 10) {
            fig->str_hero[nb] = fig->kris.hp / 10 + 48;
            nb++;
        }
        fig->str_hero[nb] = fig->kris.hp % 10 + 48;
        nb++;
    }
    fig->str_hero[nb] = '\n';
    nb++;
    return (nb);
}

int fill_hero2(fight2_t *fig, int nb)
{
    if (fig->kris_2.name != NULL) {
        for (int con = 0; fig->kris_2.name[con] != '\0'; con++) {
            fig->str_hero[nb] = fig->kris_2.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str_hero[nb] = ' ';
            jh++;
        }
        if (fig->kris_2.hp >= 10) {
            fig->str_hero[nb] = fig->kris_2.hp / 10 + 48;
            nb++;
        }
        fig->str_hero[nb] = fig->kris_2.hp % 10 + 48;
        nb++;
    }
    fig->str_hero[nb] = '\n';
    nb++;
    return (nb);
}

int fill_hero3(fight2_t *fig, int nb)
{
    if (fig->kris_3.name != NULL) {
        for (int con = 0; fig->kris_3.name[con] != '\0'; con++) {
            fig->str_hero[nb] = fig->kris_3.name[con];
            nb++;
        }
        for (int jh = 0; jh != 5; nb++) {
            fig->str_hero[nb] = ' ';
            jh++;
        }
        if (fig->kris_3.hp >= 10) {
            fig->str_hero[nb] = fig->kris_3.hp / 10 + 48;
            nb++;
        }
        fig->str_hero[nb] = fig->kris_3.hp % 10 + 48;
        nb++;
    }
    return (nb);
}
