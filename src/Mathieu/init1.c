/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner
*/

#include <map.h>
#include <rpg.h>

void init_ennemies(game_t *game)
{
    game->santa = init_sprite("ressources/map/santa.png");
    game->santa.rect = getirect(0, 0, 288, 90);
    sfSprite_setTextureRect(game->santa.sprite, game->santa.rect);
    sfSprite_setPosition(game->santa.sprite, getvector(2505, 75));
    game->santa.alive = 1;
    game->cycl = init_sprite("ressources/map/cycl.png");
    game->cycl.rect = getirect(0, 0, 192, 192);
    sfSprite_setTextureRect(game->cycl.sprite, game->cycl.rect);
    sfSprite_setPosition(game->cycl.sprite, getvector(2080, 100));
    game->cycl.alive = 1;
    game->mino = init_sprite("ressources/map/mino.png");
    game->mino.rect = getirect(0, 0, 200, 288);
    sfSprite_setTextureRect(game->mino.sprite, game->mino.rect);
    sfSprite_setPosition(game->mino.sprite, getvector(1135, -650));
    game->mino.alive = 1;
    game->glad = init_sprite("ressources/map/glad.png");
    game->glad.rect = getirect(0, 0, 96, 96);
    sfSprite_setTextureRect(game->glad.sprite, game->glad.rect);
    sfSprite_setPosition(game->glad.sprite, getvector(2510, -695));
    game->glad.alive = 1;
}

void init_boss(game_t *game)
{
    sfText_setString(game->quest, "Find the key to escape !");
    game->need_key = sfMusic_createFromFile("ressources/map/0705.WAV");
    game->pickup = sfMusic_createFromFile("ressources/map/0455.WAV");
    game->music = sfMusic_createFromFile("ressources/map/music.ogg");
    game->music_door = sfMusic_createFromFile("ressources/map/door.WAV");
    game->music_boss = sfMusic_createFromFile("ressources/map/boss.WAV");
    game->music_santa = sfMusic_createFromFile("ressources/map/santa.WAV");
    game->music_cycl = sfMusic_createFromFile("ressources/map/cycl.WAV");
    game->music_mino = sfMusic_createFromFile("ressources/map/mino.WAV");
    game->music_glad = sfMusic_createFromFile("ressources/map/glad.WAV");
    game->music_switch = sfMusic_createFromFile("ressources/map/switch.WAV");
    game->boss = init_sprite("ressources/map/boss2.png");
    game->boss.rect = getirect(0, 0, 268, 128);
    sfSprite_setTextureRect(game->boss.sprite, game->boss.rect);
    sfSprite_setPosition(game->boss.sprite, getvector(2205, -1275));
    game->boss.alive = 1;
}

void init_ressources(game_t *game)
{
    game->background = init_sprite("ressources/map/background.png");
    sfSprite_setPosition(game->background.sprite, getvector(-105, -1930));
    game->wall = init_sprite("ressources/map/wall.png");
    sfSprite_setPosition(game->wall.sprite, getvector(-105, -1930));
    game->gate = init_sprite("ressources/map/gate.png");
    sfSprite_setPosition(game->gate.sprite, getvector(-105, -1930));
    game->key = init_sprite("ressources/map/key.png");
    sfSprite_setPosition(game->key.sprite, getvector(2395, 350));
    game->gold1 = init_sprite("ressources/map/gold1.png");
    sfSprite_setPosition(game->gold1.sprite, getvector(1985, 85));
    game->gold2 = init_sprite("ressources/map/gold2.png");
    sfSprite_setPosition(game->gold2.sprite, getvector(967, -565));
    game->door = init_sprite("ressources/map/door.png");
    sfSprite_setTextureRect(game->door.sprite, getirect(0, 0, 169, 167));
    sfSprite_setPosition(game->door.sprite, getvector(931, 322));
    game->lever = init_sprite("ressources/map/lever.png");
    sfSprite_setTextureRect(game->lever.sprite, getirect(0, 0, 60, 88));
    sfSprite_setPosition(game->lever.sprite, getvector(1752, -539));
}

void init_particles(game_t *game)
{
    for (int i = 0; i != 50; i++) {
        game->rain[i] = init_sprite("ressources/map/rain.png");
        game->rain[i].position = get_vector(0, 0);
        game->rain[i].position.x = rand() % 1920;
        game->rain[i].position.y -= rand() % 1020;
    }
    for (int i = 0; i != 3; i++) {
        game->walk[i] = init_sprite("ressources/map/walk.png");
        game->walk[i].position = get_vector(0, 0);
    }
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    init_settings(game);
    init_boss(game);
    init_particles(game);
    init_ressources(game);
    init_ennemies(game);
    return (game);
}