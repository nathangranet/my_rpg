/*
** EPITECH PROJECT, 2019
** init_struct
** File description:
** init_struct
*/

#include "rpg.h"
#include "map.h"

object_t *create_object(const char *path_to_spritesheet,
                        sfVector2f pos, sfIntRect rect)
{
    object_t *create = malloc(sizeof(*create));

    create->sprite = sfSprite_create();
    create->pos = pos;
    create->rect = rect;
    create->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    sfSprite_setTexture(create->sprite, create->texture, sfTrue);
    sfSprite_setPosition(create->sprite, create->pos);
    sfSprite_setTextureRect(create->sprite, create->rect);
    return (create);
}

void init_button(button_t *b, sfVector2f pos, sfVector2f size, void(*ptr))
{
    b->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(b->rect, pos);
    sfRectangleShape_setSize(b->rect, size);
    sfRectangleShape_setFillColor(b->rect, sfRed);
    b->callback = ptr;
}

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(*inventory));
    items_t **items = malloc(sizeof(*items) * 12);

    for (int i = 0; i < 12; i++) {
        items[i] = malloc(sizeof(*items) * 2);
        items[i]->nb = 0;
    }
    give_function_items(items);
    inventory->selec = 2;
    inventory->item = items;
    inventory->stuff = init_stuff();
    inventory->stuff2 = init_stuff();
    inventory->tab = 0;
    inventory->clock = sfClock_create();
    return (inventory);
}

void init_struct_2(gestion_t *game)
{
    sfImage *img = sfImage_createFromFile("ressources/fool.png");
    game->inventory = init_inventory();
    game->current_scene = 0;
    game->reset = 0;
    game->mode.width = 1920;
    game->mode.height = 1080;
    game->money_rect.height = 50;
    game->money_rect.width = 50;
    game->money_rect.top = 0;
    game->money_rect.left = 0;
    game->mode.bitsPerPixel = 32;
    game->money = 30;
    game->music = sfMusic_createFromFile("ressources/button.ogg");
    game->window = sfRenderWindow_create
        (game->mode, "MY_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setIcon(game->window, 147, 129, sfImage_getPixelsPtr(img));
    game->clock = sfClock_create();
    game->clock2 = sfClock_create();
}

gestion_t *init_struct(void)
{
    gestion_t *game = malloc(sizeof(*game));

    game->stats = malloc(sizeof(*game->stats) * 20);
    game->font = sfFont_createFromFile("ressources/font.otf");
    for (int i = 0; i < 12; i++) {
        game->stats[i] = sfText_create();
        sfText_setFont(game->stats[i], game->font);
        sfText_setCharacterSize(game->stats[i], 20);
    }
    game->text = sfText_create();
    game->txt_money = sfText_create();
    game->circle = init_circle();
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 20);
    sfText_setFont(game->txt_money, game->font);
    sfText_setCharacterSize(game->txt_money, 50);
    init_struct_2(game);
    return (game);
}
