/*
** EPITECH PROJECT, 2019
** atk_ene
** File description:
** atack of the enemies
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

int ene_atk1(sfRenderWindow *window, fight2_t *fig)
{
    static int ini = 0;
    sfTime tim = sfClock_getElapsedTime(fig->cloque3);

    if (ini == 0) {
        fig->ene1.f_rect.top = 672;
        fig->ene1.f_rect.left = 0;
        fig->ene1.f_rect.height = 672;
        fig->ene1.f_rect.width = 669;
        ini = 1;
    }
    if (tim.microseconds > 77778) {
        fig->ene1.f_rect.left += 669;
        if (fig->ene1.f_rect.left >= 6021 - 669) {
            ini = 0;
            fig->ene1.f_rect.left = 0;
        }
        sfClock_restart(fig->cloque3);
    }
    sfSprite_setTextureRect(fig->ene1.f_pers, fig->ene1.f_rect);
    sfRenderWindow_drawSprite(window, fig->ene1.f_pers, NULL);
    return (1);
}

void init_enemies51(fight2_t *fig, sfVector2f pos)
{
    pos.x = 1000;
    fig->ene3.f_rect.left = 50;
    fig->ene3.f_text = sfTexture_createFromFile("src/fight/imp.png", NULL);
    fig->ene3.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->ene3.f_pers, fig->ene3.f_text, 1);
    sfSprite_setPosition(fig->ene3.f_pers, pos);
    fig->ene1.name = "imp";
    fig->ene1.hp = 15;
    fig->ene1.atk = 11;
    fig->ene1.def = 9;
    fig->ene2.name = "???";
    fig->ene2.hp = 40;
    fig->ene2.atk = 9;
    fig->ene2.def = 3;
    fig->ene3.name = "imp";
    fig->ene3.hp = 15;
    fig->ene3.atk = 11;
    fig->ene3.def = 9;
}

void init_enemies5(fight2_t *fig, int lvl, sfVector2f pos)
{
    if (lvl == 5) {
        pos.x = 1000;
        pos.y = -50;
        fig->ene1.f_rect.left = 50;
        fig->ene1.f_text = sfTexture_createFromFile("src/fight/imp.png", NULL);
        fig->ene1.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene1.f_pers, fig->ene1.f_text, 1);
        sfSprite_setPosition(fig->ene1.f_pers, pos);
        pos.y = 120;
        pos.x = 800;
        fig->ene2.f_rect.left = 50;
        fig->ene2.f_text = sfTexture_createFromFile("src/fight/boss.png", NULL);
        fig->ene2.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene2.f_pers, fig->ene2.f_text, 1);
        sfSprite_setPosition(fig->ene2.f_pers, pos);
        pos.y = 300;
        init_enemies51(fig, pos);
    }
}

void init_enemies41(fight2_t *fig, sfVector2f pos)
{
    fig->ene3.f_rect.left = 50;
    fig->ene3.f_text = sfTexture_createFromFile("src/fight/spider.png", NULL);
    fig->ene3.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->ene3.f_pers, fig->ene3.f_text, 1);
    sfSprite_setPosition(fig->ene3.f_pers, pos);
    fig->ene1.name = "gladiator";
    fig->ene1.hp = 24;
    fig->ene1.atk = 8;
    fig->ene1.def = 4;
    fig->ene2.name = "dwarf";
    fig->ene2.hp = 20;
    fig->ene2.atk = 8;
    fig->ene2.def = 5;
    fig->ene3.name = "spider";
    fig->ene3.hp = 15;
    fig->ene3.atk = 13;
    fig->ene3.def = 0;
}

void init_enemies4(fight2_t *fig, int lvl, sfVector2f pos)
{
    if (lvl == 4) {
        pos.x = 1000;
        pos.y = -50;
        fig->ene1.f_rect.left = 50;
        fig->ene1.f_text = sfTexture_createFromFile("src/fight/glad.png", NULL);
        fig->ene1.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene1.f_pers, fig->ene1.f_text, 1);
        sfSprite_setPosition(fig->ene1.f_pers, pos);
        pos.y = 120;
        fig->ene2.f_rect.left = 50;
        fig->ene2.f_text = sfTexture_createFromFile("src/fight/dwarf.png",
                                                    NULL);
        fig->ene2.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene2.f_pers, fig->ene2.f_text, 1);
        sfSprite_setPosition(fig->ene2.f_pers, pos);
        pos.y = 300;
        init_enemies41(fig, pos);
    }
    init_enemies5(fig, lvl, pos);
}
