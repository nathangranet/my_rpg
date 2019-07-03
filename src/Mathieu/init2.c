/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include <map.h>
#include <rpg.h>

void create_map(char **map)
{
    map[0] = create_line("XXXXXXXXXXXXXXXX");
    map[1] = create_line("XX***********XXX");
    map[2] = create_line("XX*XXXXXXXXXXXXX");
    map[3] = create_line("XX*************X");
    map[4] = create_line("XX***XXXXXXXXXOX");
    map[5] = create_line("XXXXXX*******M*X");
    map[6] = create_line("X**M*X*******X*X");
    map[7] = create_line("X**X*X***XXXXX*X");
    map[8] = create_line("X*XX*XXXXX*****X");
    map[9] = create_line("X*X********XXXXX");
    map[10] = create_line("XXX*****XXXX**XX");
    map[11] = create_line("X****XXXX**X*M*X");
    map[12] = create_line("X****XXXXXMX*X*X");
    map[13] = create_line("XDXXXXXXX**X*X*X");
    map[14] = create_line("X*XXX******XXX*X");
    map[15] = create_line("XP*************X");
    map[16] = create_line("XXXXXXXXXXXXXXXX");
    map[17] = NULL;
}

sprite_t init_sprite(char *texture)
{
    sprite_t sprite;

    sprite.texture = sfTexture_createFromFile(texture, NULL);
    sprite.sprite = sfSprite_create();
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfTrue);
    return (sprite);
}

char *create_line(char *src)
{
    char *dest = malloc(sizeof(char) * 17);
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

sfRenderWindow *createwindow(int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {width, height, 32};
    sfImage *img = sfImage_createFromFile("ressources/map/key.png");

    window = sfRenderWindow_create(video_mode, "well",
            sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 50, 50, sfImage_getPixelsPtr(img));
    return (window);
}

void player_rect(game_t *game, int y)
{
    sfTime time = sfClock_getElapsedTime(game->clocka);
    float seconds = time.microseconds / 1000000.0;

    game->player.rect.top = y;
    if (seconds > 0.09) {
        if (game->player.rect.left >= 208)
            game->player.rect.left = 0;
        else
            game->player.rect.left += 104;
        sfClock_restart(game->clocka);
    }
}
