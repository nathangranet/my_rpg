/*
** EPITECH PROJECT, 2019
** enemies_atk
** File description:
** contain where the enemies attack
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

void enemies_atk4(fight2_t *fig, int vise)
{
    if (fig->kris.hp <= 0)
        fig->kris.name = NULL;
    if (fig->kris_2.hp <= 0)
        fig->kris_2.name = NULL;
    vise = rand() % 2;
    if (vise == 0 && fig->ene3.name != NULL) {
        if (fig->kris.name != NULL)
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene3.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene3.atk;
        else
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene3.atk;
    }
    if (vise == 1 && fig->ene3.name != NULL) {
        if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene3.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene3.atk;
        else
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene3.atk;
    }
}

void enemies_atk3(fight2_t *fig, int vise)
{
    if (vise == 0 && fig->ene2.name != NULL) {
        if (fig->kris.name != NULL)
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene2.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene2.atk;
        else
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene2.atk;
    }
    if (vise == 1 && fig->ene2.name != NULL) {
        if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene2.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene2.atk;
        else
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene2.atk;
    }
    enemies_atk4(fig, vise);
}

void enemies_atk2(fight2_t *fig, int vise)
{
    if (fig->kris.hp <= 0)
        fig->kris.name = NULL;
    if (fig->kris_2.hp <= 0)
        fig->kris_2.name = NULL;
    vise = rand() % 2;
    enemies_atk3(fig, vise);
}

void enemies_atk1(fight2_t *fig, sfRenderWindow *window)
{
    int vise = 0;

    srand(time(NULL));
    vise = rand() % 2;
    if (vise == 0 && fig->ene1.name != NULL) {
        if (fig->kris.name != NULL)
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene1.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene1.atk;
        else
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene1.atk;
    }
    if (vise == 1 && fig->ene1.name != NULL) {
        if (fig->kris_2.name != NULL)
            fig->kris_2.hp = fig->kris_2.hp + fig->kris_2.def - fig->ene1.atk;
        else if (fig->kris_2.name != NULL)
            fig->kris_3.hp = fig->kris_3.hp + fig->kris_3.def - fig->ene1.atk;
        else
            fig->kris.hp = fig->kris.hp + fig->kris.def - fig->ene1.atk;
    }
    enemies_atk2(fig, vise);
}
