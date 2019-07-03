/*
** EPITECH PROJECT, 2019
** more_anim
** File description:
** look the definition of animation
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

void kris_def(sfRenderWindow *window, fight2_t *fig, int lim)
{
    static int ini = 0;

    if (ini == 0) {
        fig->kris.f_rect.top = 560;
        fig->kris.f_rect.left = 0;
        fig->kris.f_rect.width = 85;
        fig->kris.f_rect.height = 90;
        ini = 1;
    }
    if (fig->time.microseconds > 150000) {
        if (fig->kris.f_rect.left < 300)
            fig->kris.f_rect.left += 83;
        sfClock_restart(fig->cloque);
    }
    if (fig->hero == 3 && lim == 0) {
        ini = 0;
    }
    sfSprite_setTextureRect(fig->kris.f_pers, fig->kris.f_rect);
    sfRenderWindow_drawSprite(window, fig->kris.f_pers, NULL);
}

void init_text(fight2_t *fig)
{
    sfVector2f pos;
    sfFont *type;

    pos.x = 270;
    pos.y = 800;
    fig->mana = 0;
    fig->tex = sfText_create();
    type = sfFont_createFromFile("ressources/map/JAGUAR.ttf");
    sfText_setPosition(fig->tex, pos);
    sfText_setFont(fig->tex, type);
    sfText_setCharacterSize(fig->tex, 40);
    pos.x = 1250;
    fig->tex_ene = sfText_create();
    fig->tex_mana = sfText_create();
    sfText_setPosition(fig->tex_ene, pos);
    pos.x = 770;
    sfText_setPosition(fig->tex_mana, pos);
    sfText_setFont(fig->tex_mana, type);
    sfText_setFont(fig->tex_ene, type);
    sfText_setCharacterSize(fig->tex_ene, 42);
    sfText_setCharacterSize(fig->tex_mana, 42);
}

void init_stats(fight2_t *fig)
{
    sfFont *type = sfFont_createFromFile("ressources/map/JAGUAR.ttf");

    fig->kris.name = "kris";
    fig->kris.hp = 28;
    fig->kris.atk = 5;
    fig->kris.def = 2;
    fig->kris.conc = 3;
    fig->kris.item = 1;
    fig->kris.tet = sfText_create();
    fig->kris.dmgs = 0;
    fig->kris_2.name = "ralsei";
    fig->kris_2.hp = 21;
    fig->kris_2.atk = 4;
    fig->kris_2.def = 3;
    fig->kris_2.conc = 5;
    fig->kris_2.item = 3;
    fig->kris_2.tet = sfText_create();
    sfText_setFont(fig->tex_mana, type);
    sfText_setFont(fig->tex_ene, type);
    fig->kris_2.dmgs = 0;
    fig->kris_3.name = NULL;
}

void init_enemies31(fight2_t *fig, sfVector2f pos)
{
    fig->ene2.f_rect.left = 50;
    fig->ene3.f_text = sfTexture_createFromFile("src/fight/bat.png", NULL);
    fig->ene3.f_pers = sfSprite_create();
    sfSprite_setTexture(fig->ene3.f_pers, fig->ene3.f_text, 1);
    sfSprite_setPosition(fig->ene3.f_pers, pos);
    fig->ene3.name = "bat";
    fig->ene3.hp = 10;
    fig->ene3.atk = 10;
    fig->ene3.def = 0;
    fig->ene2.name = "cyclop";
    fig->ene2.hp = 20;
    fig->ene2.atk = 9;
    fig->ene2.def = 2;
    fig->ene1.name = "bat";
    fig->ene1.hp = 10;
    fig->ene1.atk = 10;
    fig->ene1.def = 0;
}

void init_enemies3(fight2_t *fig, int lvl, sfVector2f pos)
{
    if (lvl == 3) {
        pos.x = 800;
        pos.y = -150;
        fig->ene1.f_rect.left = 50;
        fig->ene1.f_text = sfTexture_createFromFile("src/fight/bat.png", NULL);
        fig->ene1.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene1.f_pers, fig->ene1.f_text, 1);
        sfSprite_setPosition(fig->ene1.f_pers, pos);
        pos.x = 1000;
        pos.y = 160;
        fig->ene2.f_rect.left = 50;
        fig->ene2.f_text = sfTexture_createFromFile("src/fight/cycl.png", NULL);
        fig->ene2.f_pers = sfSprite_create();
        sfSprite_setTexture(fig->ene2.f_pers, fig->ene2.f_text, 1);
        sfSprite_setPosition(fig->ene2.f_pers, pos);
        pos.x = 800;
        pos.y = 320;
        init_enemies31(fig, pos);
    }
    init_enemies4(fig, lvl, pos);
}
