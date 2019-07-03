/*
** EPITECH PROJECT, 2019
** gestion
** File description:
** gestion
*/

#include "rpg.h"
#include "map.h"

char *my_revstr(char *str)
{
    char a = 0;
    char b = 0;
    char c;
    while (str[a] != '\0') {
        a++;
    }
    a--;
    while (a >= b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a--;
        b++;
    }
    return (str);
}

char *to_array(int nb)
{
    char *str = NULL;
    int n = nb;
    int c;

    for (c = 0; n != 0; c++)
        n /= 10;
    str = malloc(sizeof(char) * c);
    n = nb;
    for (c = 0; n != 0; c++) {
        str[c] = n % 10 + 48;
        n /= 10;
    }
    str[c] = '\0';
    str = my_revstr(str);
    return (str);
}

sfIntRect get_rect(float a, float b, float c, float d)
{
    sfIntRect rect;

    rect.left = a;
    rect.top = b;
    rect.width = c;
    rect.height = d;
    return (rect);
}

sfVector2f get_vector(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2i get_vectori(int x, int y)
{
    sfVector2i vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}
