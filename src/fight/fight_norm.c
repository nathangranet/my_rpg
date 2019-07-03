/*
** EPITECH PROJECT, 2019
** making some norm
** File description:
** getting points
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

void change_hero2(fight2_t *fig)
{
    if (fig->hero == 2)
        fig->hero = 3;
    else if (fig->hero == 3) {
        if (fig->kris.name == NULL && fig->kris_2.name == NULL)
            fig->hero = 2;
        else if (fig->kris.name == NULL)
            fig->hero = 1;
        else
            fig->hero = 0;
    }
    fig->mana += 1;
}

void up_change_2(fight2_t *fig, sfRenderWindow *window)
{
    if (fig->f3 == 1) {
        fig->f3 = 0;
        if (fig->ene2.name != NULL)
            fig->f2 = 1;
        else if (fig->ene1.name != NULL)
            fig->f1 = 1;
        else
            fig->f3 = 1;
    }
    else if (fig->f2 == 1) {
        fig->f2 = 0;
        if (fig->ene1.name != NULL)
            fig->f1 = 1;
        else if (fig->ene3.name != NULL)
            fig->f3 = 1;
        else
            fig->f2 = 1;
    }
}

void verif_replace(fight2_t *fig)
{
    if (fig->f1 == 1 && fig->ene1.name == NULL) {
        fig->f1 = 0;
        if (fig->ene2.name != NULL)
            fig->f2 = 1;
        else
            fig->f3 = 1;
    }
    if (fig->f2 == 1 && fig->ene2.name == NULL) {
        fig->f2 = 0;
        if (fig->ene3.name != NULL)
            fig->f3 = 1;
        else
            fig->f1 = 1;
    }
    if (fig->f3 == 1 && fig->ene3.name == NULL) {
        fig->f3 = 0;
        if (fig->ene2.name != NULL)
            fig->f1 = 1;
        else
            fig->f2 = 1;
    }
}

void down_change2(fight2_t *fig, sfRenderWindow *window)
{
    if (fig->f3 == 1) {
        fig->f3 = 0;
        if (fig->ene1.name != NULL)
            fig->f1 = 1;
        else if (fig->ene2.name != NULL)
            fig->f2 = 1;
        else
            fig->f3 = 1;
    }
    else if (fig->f2 == 1) {
        fig->f2 = 0;
        if (fig->ene3.name != NULL)
            fig->f3 = 1;
        else if (fig->ene1.name != NULL)
            fig->f1 = 1;
        else
            fig->f2 = 1;
    }
}

void down_change(fight2_t *fig, sfRenderWindow *window)
{
    if (fig->f1 == 1) {
        fig->f1 = 0;
        if (fig->ene2.name != NULL)
            fig->f2 = 1;
        else if (fig->ene3.name != NULL)
            fig->f3 = 1;
        else
            fig->f1 = 1;
    }
    else
        down_change2(fig, window);
    sfMusic_play(fig->select);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
}
