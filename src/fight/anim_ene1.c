/*
** EPITECH PROJECT, 2019
** anim_ene1
** File description:
** animate the enemise
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

void anim_enem1(fight2_t *fig, sfRenderWindow *window, stat2_t *ene)
{
    sfTime tim = sfClock_getElapsedTime(fig->cloque3);

    ene->f_rect.top = 0;
    ene->f_rect.width = 669;
    ene->f_rect.height = 630;
    if (tim.microseconds > 140000) {
        ene->f_rect.left += 672;
        if (ene->f_rect.left >= 3345)
            ene->f_rect.left = 50;
        sfClock_restart(fig->cloque3);
    }
    sfSprite_setTextureRect(ene->f_pers, ene->f_rect);
    sfRenderWindow_drawSprite(window, ene->f_pers, NULL);
}

void anim_enem2(fight2_t *fig, sfRenderWindow *window, stat2_t *ene)
{
    sfTime tim = sfClock_getElapsedTime(fig->cloque4);

    ene->f_rect.top = 0;
    ene->f_rect.width = 669;
    ene->f_rect.height = 630;
    if (tim.microseconds > 140000) {
        ene->f_rect.left += 672;
        if (ene->f_rect.left >= 3345)
            ene->f_rect.left = 50;
        sfClock_restart(fig->cloque4);
    }
    sfSprite_setTextureRect(ene->f_pers, ene->f_rect);
    sfRenderWindow_drawSprite(window, ene->f_pers, NULL);
}

void anim_enem3(fight2_t *fig, sfRenderWindow *window, stat2_t *ene)
{
    sfTime tim = sfClock_getElapsedTime(fig->cloque5);

    ene->f_rect.top = 0;
    ene->f_rect.width = 669;
    ene->f_rect.height = 630;
    if (tim.microseconds > 140000) {
        ene->f_rect.left += 672;
        if (ene->f_rect.left >= 3345)
            ene->f_rect.left = 50;
        sfClock_restart(fig->cloque5);
    }
    sfSprite_setTextureRect(ene->f_pers, ene->f_rect);
    sfRenderWindow_drawSprite(window, ene->f_pers, NULL);
}

void init_enemies1(fight2_t *fig, sfVector2f pos)
{
    pos.x = 1000;
    pos.y = 250;
    fig->ene2.f_rect.left = 50;
    fig->ene2.f_text = sfTexture_createFromFile("src/fight/snow.png", NULL);
    fig->ene2.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->ene2.f_pers, fig->ene2.f_text, 1);
    sfSprite_setPosition(fig->ene2.f_pers, pos);
    fig->ene2.name = "snowbaal";
    fig->ene2.hp = 22;
    fig->ene2.atk = 6;
    fig->ene2.def = 0;
    fig->ene3.name = NULL;
    fig->ene3.hp = 0;
}
