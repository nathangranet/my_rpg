/*
** EPITECH PROJECT, 2019
** play_eve
** File description:
** play the events
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

void play_event13(sfRenderWindow *window, fight2_t *fig)
{
    if (fig->ev == 6 && fig->mana > 19) {
        fig->ev = kris_cast(window, fig);
        if (fig->ev == 0) {
            spell1(fig);
            change_hero(fig, window);
        }
    }
    else
        fig->ev = 0;
}

void play_event12(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev == 4) {
        fig->ev = 0;
        down_change(fig, window);
    }
    else if (fig->ev == 5) {
        kris_def(window, fig, lim);
        if (fig->def == 0) {
            fig->def = 1;
            fig->kris.def += 2;
            fig->mana += fig->kris.conc;
            change_hero(fig, window);
        }
    }
    else
        play_event13(window, fig);
}

void play_event11(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev == 2 && fig->kris.item != 0) {
        fig->ev = kris_use(window, fig);
        if (fig->ev == 0) {
            item1(fig);
            change_hero(fig, window);
        }
    }
    else if (fig->ev == 3) {
        fig->ev = 0;
        up_change(fig, window);
    }
    else
        play_event12(window, fig, lim);
}

void play_event1(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev == 0 && fig->kris.hp > 0)
        anim_kris(fig, window);
    else if (fig->ev == 1) {
        fig->ev = kris_atk(window, fig);
        if (fig->ev == 0) {
            dmg_enemies(fig);
            change_hero(fig, window);
        }
    }
    else
        play_event11(window, fig, lim);
}
