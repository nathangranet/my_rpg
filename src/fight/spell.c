/*
** EPITECH PROJECT, 2019
** spell
** File description:
** cast spells
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

void spell1(fight2_t *fig)
{
    if (fig->f1 == 1)
        fig->ene1.hp = fig->ene1.hp - fig->kris.atk - fig->kris.conc;
    else if (fig->f3 == 1)
        fig->ene3.hp = fig->ene3.hp - fig->kris.atk - fig->kris.conc;
    else if (fig->f2 == 1)
        fig->ene2.hp = fig->ene2.hp - fig->kris.atk - fig->kris.conc;
    if (fig->ene1.hp <= 0)
        fig->ene1.name = NULL;
    if (fig->ene2.hp <= 0)
        fig->ene2.name = NULL;
    if (fig->ene3.hp <= 0)
        fig->ene3.name = NULL;
    fig->mana -= 20;
}

void spell2(fight2_t *fig)
{
    fig->kris.hp += fig->kris_2.conc * 1.6;
    fig->kris_2.hp += fig->kris_2.conc * 1.3;
    fig->mana -= 20;
}

void item11(fight2_t *fig)
{
    if (fig->kris.item == 3) {
        fig->kris.item = 0;
        if (fig->f1 == 1)
            fig->ene1.hp = fig->ene1.hp - 15 + fig->ene1.def;
        else if (fig->f3 == 1)
            fig->ene3.hp = fig->ene3.hp - 15 + fig->ene3.def;
        else if (fig->f2 == 1)
            fig->ene2.hp = fig->ene2.hp - 15 + fig->ene2.def;
        if (fig->ene1.hp <= 0)
            fig->ene1.name = NULL;
        if (fig->ene2.hp <= 0)
            fig->ene2.name = NULL;
        if (fig->ene3.hp <= 0)
            fig->ene3.name = NULL;
    }
}

void item1(fight2_t *fig)
{
    if (fig->kris.item == 1) {
        fig->kris.item = 0;
        fig->kris.hp += 10;
    }
    if (fig->kris.item == 2) {
        fig->kris.item = 0;
        fig->mana += 13;
    }
    item11(fig);
}

void fill_mana(fight2_t *fig)
{
    char *str = malloc(15);
    int nbr = 8;

    str[0] = 'm';
    str[1] = 'a';
    str[2] = 'n';
    str[3] = 'a';
    str[4] = ' ';
    str[5] = ' ';
    str[6] = ' ';
    str[7] = ' ';
    if (fig->mana >= 10) {
        str[nbr] = fig->mana / 10 + 48;
        nbr++;
    }
    str[nbr] = fig->mana % 10 + 48;
    str[nbr + 1] = '\0';
    sfText_setString(fig->tex_mana, str);
}
