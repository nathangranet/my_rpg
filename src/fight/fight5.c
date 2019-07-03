/*
** EPITECH PROJECT, 2019
** fight5
** File description:
** a fight5
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

void fill_hero(fight2_t *fig)
{
    int nb = 0;
    char *str = "\n    Space: Attack  C: Use item  D: Defend  S: Use spell";

    nb = fill_hero1(fig, nb);
    nb = fill_hero2(fig, nb);
    nb = fill_hero3(fig, nb);
    for (int vz = 0; str[vz] != '\0'; vz++) {
        fig->str_hero[nb] = str[vz];
        nb++;
    }
    fig->str_hero[nb] = '\0';
}

int dmg_enemies(fight2_t *fig)
{
    if (fig->f1 == 1)
        fig->ene1.hp = fig->ene1.hp + fig->ene1.def - fig->kris.atk;
    else if (fig->f3 == 1)
        fig->ene3.hp = fig->ene3.hp + fig->ene3.def - fig->kris.atk;
    else if (fig->f2 == 1)
        fig->ene2.hp = fig->ene2.hp + fig->ene2.def - fig->kris.atk;
    if (fig->ene1.hp <= 0)
        fig->ene1.name = NULL;
    if (fig->ene2.hp <= 0)
        fig->ene2.name = NULL;
    if (fig->ene3.hp <= 0)
        fig->ene3.name = NULL;
    return (0);
}

int dmg_enemies1(fight2_t *fig)
{
    if (fig->f1 == 1)
        fig->ene1.hp = fig->ene1.hp + fig->ene1.def - fig->kris_2.atk;
    else if (fig->f3 == 1)
        fig->ene3.hp = fig->ene3.hp + fig->ene3.def - fig->kris_2.atk;
    else if (fig->f2 == 1)
        fig->ene2.hp = fig->ene2.hp + fig->ene2.def - fig->kris_2.atk;
    if (fig->ene1.hp <= 0)
        fig->ene1.name = NULL;
    if (fig->ene2.hp <= 0)
        fig->ene2.name = NULL;
    if (fig->ene3.hp <= 0)
        fig->ene3.name = NULL;
    return (0);
}

void up_change(fight2_t *fig, sfRenderWindow *window)
{
    if (fig->f1 == 1) {
        fig->f1 = 0;
        if (fig->ene3.name != NULL)
            fig->f3 = 1;
        else if (fig->ene2.name != NULL)
            fig->f2 = 1;
        else
            fig->f1 = 1;
    }
    else
        up_change_2(fig, window);
    sfMusic_play(fig->select);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
}
