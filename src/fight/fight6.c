/*
** EPITECH PROJECT, 2019
** fight6
** File description:
** the sith fight
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

int fight_6(fight2_t *fig, sfRenderWindow *window, int lim)
{
    lim = 0;
    play_event(window, fig, lim);
    enemies_atk(fig, window);
    if (fig->def == 1)
        fig->kris.def -= 2;
    if (fig->def2 == 1)
        fig->kris_2.def -= 2;
    if (fig->def3 == 1)
        fig->kris_3.def -= 2;
    fig->ev = 0;
    fig->ev1 = 0;
    fig->ev2 = 0;
    fig->def = 0;
    fig->def2 = 0;
    fig->def3 = 0;
    fig->kris.f_rect.left = 0;
    fig->kris_2.f_rect.left = 0;
    fig->kris_3.f_rect.left = 0;
    return (lim);
}

int fight_5(fight2_t *fig, sfRenderWindow *window)
{
    sfEvent event;

    if (end(fig) == 2)
        return (2);
    if (end(fig) == 1)
        return (1);
    fight_3(fig, window);
    if (fig->ene1.name != NULL)
        anim_enem1(fig, window, &fig->ene1);
    if (fig->ene2.name != NULL)
        anim_enem2(fig, window, &fig->ene2);
    if (fig->ene3.name != NULL)
        anim_enem3(fig, window, &fig->ene3);
    if (fig->ev == 0 && fig->hero == 0)
        while (sfRenderWindow_pollEvent(window, &event))
            fig->ev = event_handle(window, event, fig->ev);
    if (fig->ev1 == 0 && fig->hero == 1)
        while (sfRenderWindow_pollEvent(window, &event))
            fig->ev1 = event_handle(window, event, fig->ev1);
    return (0);
}

void fight_4(fight2_t *fig, sfRenderWindow *window, int lvl)
{
    sfView *view = sfView_createFromRect(getfrect(0, 0, 1920, 1080));

    sfRenderWindow_setView(window, view);
    init_things(fig);
    init_text(fig);
    fig->f1 = 1;
    fig->f2 = 0;
    fig->f3 = 0;
    fig->hero = 0;
    fig->kris.name = "kris";
    fig->kris_2.name = "ralsei";
    fig->kris.hp = 20;
    fig->kris_2.hp = 25;
    init_enemies(fig, lvl);
    sfText_setCharacterSize(fig->kris.tet, 30);
    sfText_setCharacterSize(fig->kris.tet, 30);
    fig->zic = sfMusic_createFromFile("src/fight/music_fight.ogg");
    sfMusic_setLoop(fig->zic, sfTrue);
    fig->select = sfMusic_createFromFile("src/fight/select.wav");
    sfMusic_play(fig->zic);
}

void draw_and_free(sfRenderWindow *window, fight2_t *fig)
{
        sfRenderWindow_drawText(window, fig->tex, NULL);
        sfRenderWindow_drawText(window, fig->tex_ene, NULL);
        sfRenderWindow_drawText(window, fig->tex_mana, NULL);
        free (fig->str);
        free (fig->str_hero);
}

int pp2(int lim, sfClock *limit)
{
    if (lim == 0) {
        lim = 1;
        sfClock_restart(limit);
    }
    return (lim);
}