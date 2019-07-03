/*
** EPITECH PROJECT, 2019
** fight2
** File description:
** a fight2
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

void change_hero(fight2_t *fig, sfRenderWindow *window)
{
    if (fig->hero == 0) {
        if (fig->kris_2.name == NULL && fig->kris_3.name == NULL)
            fig->hero = 3;
        else if (fig->kris_2.name == NULL)
            fig->hero = 2;
        else
            fig->hero = 1;
    }
    else if (fig->hero == 1) {
        if (fig->kris_3.name == NULL)
            fig->hero = 3;
        else
            fig->hero = 2;
    }
    else
        change_hero2(fig);
}

void init_things2(fight2_t *fig)
{
    sfVector2f pos;

    fig->kris_2.f_rect.left = 0;
    pos.x = 250;
    pos.y = 550;
    fig->kris_2.f_text = sfTexture_createFromFile("src/fight/kris1.png", NULL);
    fig->kris_2.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->kris_2.f_pers, fig->kris_2.f_text, 1);
    sfSprite_setPosition(fig->kris_2.f_pers, pos);
    fig->hero = 0;
    fig->def = 0;
    fig->def3 = 0;
    fig->def2 = 0;
    fig->ev = 0;
    fig->ev1 = 0;
    fig->ev2 = 0;
}

void init_things(fight2_t *fig)
{
    sfVector2f pos;

    pos.x = 250;
    pos.y = 180;
    fig->kris.f_rect.left = 0;
    fig->cloque = sfClock_create();
    fig->cloque2 = sfClock_create();
    fig->cloque3 = sfClock_create();
    fig->cloque5 = sfClock_create();
    fig->f_text_back = sfTexture_createFromFile("src/fight/background.png",
                                                NULL);
    fig->f_back = sfSprite_create();
    sfSprite_setTexture(fig->f_back, fig->f_text_back, 1);
    fig->kris.f_text = sfTexture_createFromFile("src/fight/kris.png", NULL);
    fig->kris.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->kris.f_pers, fig->kris.f_text, 1);
    sfSprite_setPosition(fig->kris.f_pers, pos);
    init_things2(fig);
}

int event_handle(sfRenderWindow *window, sfEvent event, int ev)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == 36)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeySpace)
            return (1);
        if (event.key.code == 2)
            return (2);
        if (event.key.code == 73)
            return (3);
        if (event.key.code == 74)
            return (4);
        if (event.key.code == 3)
            return (5);
        if (event.key.code == 18)
            return (6);
    }
    else
        return (ev);
    return (0);
}

void anim_kris(fight2_t *fig, sfRenderWindow *window)
{
    fig->kris.f_rect.top = 0;
    fig->kris.f_rect.width = 150;
    fig->kris.f_rect.height = 105;
    if (fig->time.microseconds > 200000) {
        fig->kris.f_rect.left += 155;
        if (fig->kris.f_rect.left == 930)
            fig->kris.f_rect.left = 0;
        sfClock_restart(fig->cloque);
    }
    sfSprite_setTextureRect(fig->kris.f_pers, fig->kris.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
}
