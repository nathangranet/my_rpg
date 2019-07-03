/*
** EPITECH PROJECT, 2019
** init_enemi
** File description:
** init some enemies
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

int play_event(sfRenderWindow *window, fight2_t *fig, int lim)
{
    play_event1(window, fig, lim);
    play_event2(window, fig, lim);
    fig->ev2 = 0;
}

void init_enemies2(fight2_t *fig, int lvl, sfVector2f pos)
{
    if (lvl == 2) {
        pos.x = 1000;
        pos.y = 200;
        fig->ene1.f_rect.left = 50;
        fig->ene1.f_text = sfTexture_createFromFile("src/fight/mino.png", NULL);
        fig->ene1.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene1.f_pers, fig->ene1.f_text, 1);
        sfSprite_setPosition(fig->ene1.f_pers, pos);
        fig->ene1.name = "minos";
        fig->ene1.hp = 40;
        fig->ene1.atk = 9;
        fig->ene1.def = 7;
        fig->ene2.name = NULL;
        fig->ene2.hp = 0;
        fig->ene3.name = NULL;
        fig->ene3.hp = 0;
    }
    init_enemies3(fig, lvl, pos);
}

void init_enemies(fight2_t *fig, int lvl)
{
    sfVector2f pos;

    if (lvl == 1) {
        pos.x = 1000;
        pos.y = 0;
        fig->ene1.f_rect.left = 0;
        fig->ene1.f_text = sfTexture_createFromFile("src/fight/santa.png",
                                                    NULL);
        fig->ene1.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene1.f_pers, fig->ene1.f_text, 1);
        sfSprite_setPosition(fig->ene1.f_pers, pos);
        fig->ene1.name = "santa";
        fig->ene1.hp = 21;
        fig->ene1.atk = 11;
        fig->ene1.def = 2;
        init_enemies1(fig, pos);
    }
    init_enemies2(fig, lvl, pos);
}

int end(fight2_t *fig)
{
    if (fig->ene1.name == NULL && fig->ene2.name == NULL
        && fig->ene3.name == NULL)
        return (1);
    if (fig->kris.name == NULL && fig->kris_2.name == NULL
        && fig->kris_3.name == NULL)
        return (2);
    return (0);
}
