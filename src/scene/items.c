/*
** EPITECH PROJECT, 2019
** items
** File description:
** items
*/

#include "rpg.h"
#include "map.h"

stuff_t **init_stuff(void)
{
    stuff_t **stuff = malloc(sizeof(*stuff) * 8);
    for (int i = 0; i < 3; i++) {
        stuff[i] = malloc(sizeof(*stuff) * 4);
        stuff[i]->exist = 0;
        stuff[i]->type = 0;
        stuff[i]->bonus = 0;
    }
    return (stuff);
}

void give_function_items(items_t **items)
{
    items[0]->function = add_sword;
    items[1]->function = add_sword;
    items[2]->function = add_sword;
    items[3]->function = add_sword;
    items[4]->function = add_shield;
    items[5]->function = add_shield;
    items[6]->function = add_shield;
    items[7]->function = add_shield;
    items[8]->function = add_armor;
    items[9]->function = add_armor;
    items[10]->function = add_armor;
    items[11]->function = add_armor;
}
