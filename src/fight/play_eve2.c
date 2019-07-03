/*
** EPITECH PROJECT, 2019
** play_eve2
** File description:
** the events of second ally
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

void play_event23(sfRenderWindow *window, fight2_t *fig)
{
    if (fig->ev1 == 6 && fig->mana > 18) {
        fig->ev1 = kris_cast1(window, fig);
        if (fig->ev1 == 0) {
            spell2(fig);
            change_hero(fig, window);
        }
    }
    else
        fig->ev1 = 0;
}

void play_event22(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev1 == 4) {
        fig->ev1 = 0;
        down_change(fig, window);
    }
    else if (fig->ev1 == 5) {
        kris_def1(window, fig, lim);
        if (fig->def2 == 0) {
            fig->def2 = 1;
            fig->kris_2.def += 2;
            fig->mana += fig->kris_2.conc;
            change_hero(fig, window);
        }
    }
    else
        play_event23(window, fig);
}

void play_event21(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev1 == 2 && fig->kris_2.item != 0) {
        fig->ev1 = kris_use1(window, fig);
        if (fig->ev1 == 0) {
            item2(fig);
            change_hero(fig, window);
        }
    }
    else if (fig->ev1 == 3) {
        fig->ev1 = 0;
        up_change(fig, window);
    }
    else
        play_event22(window, fig, lim);
}

void play_event2(sfRenderWindow *window, fight2_t *fig, int lim)
{
    if (fig->ev1 == 0 && fig->kris_2.hp > 0)
        anim_kris1(fig, window);
    else if (fig->ev1 == 1) {
        fig->ev1 = kris_atk1(window, fig);
        if (fig->ev1 == 0) {
            dmg_enemies1(fig);
            change_hero(fig, window);
        }
    }
    else
        play_event21(window, fig, lim);
}
