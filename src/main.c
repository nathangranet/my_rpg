/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "rpg.h"
#include "map.h"

void error(void)
{
    write(2, "\"./my_rpg\" No more args\n", 25);
    write(2, "retry with -h\n", 14);
}

void loop_game(gestion_t *gest, scene_t **scenes, game_t *game)
{
    while (sfRenderWindow_isOpen(gest->window)) {
        if (game->alive == 0)
            gest->current_scene = 3;
        if (game->win == 1)
            game_win(gest, game, scenes[3]);
        if (gest->current_scene == 1 && game->win == 0) {
            sfRenderWindow_setView(gest->window, game->view);
            my_map(gest, scenes[1], game);
        }
        if (gest->current_scene != 1 && game->win == 0) {
            sfRenderWindow_setView(gest->window, gest->view);
            analyse_events(gest, scenes[gest->current_scene]);
            draw_scene(gest, scenes[gest->current_scene]);
        }
    }
}

void destroy_music(gestion_t *gest, game_t *game)
{
    sfMusic_destroy(gest->music);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->pickup);
    sfMusic_destroy(game->need_key);
    sfMusic_destroy(game->music_door);
    sfMusic_destroy(game->music_boss);
    sfMusic_destroy(game->music_santa);
    sfMusic_destroy(game->music_cycl);
    sfMusic_destroy(game->music_mino);
    sfMusic_destroy(game->music_glad);
    sfMusic_destroy(game->music_switch);
}

int my_rpg(void)
{
    gestion_t *gest;
    scene_t **scenes;
    game_t *game = init_game();

    game->fig = malloc(sizeof(fight2_t));
    game->view = sfView_createFromRect(getfrect(0, 0, 1920, 1080));
    gest = init_struct();
    gest->view = sfView_createFromRect(getfrect(0, 0, 1920, 1080));
    scenes = malloc(sizeof(*scenes) * 4);
    scenes[0] = create_start_scene();
    scenes[1] = create_game_scene();
    scenes[2] = create_pause_scene();
    scenes[3] = create_end_scene();
    sfRenderWindow_setFramerateLimit(gest->window, 60);
    sfMusic_play(game->music);
    game->fig = malloc(sizeof(fight2_t));
    init_things(game->fig);
    init_text(game->fig);
    my_rpg2(game, gest, scenes);
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1){
        error();
        return (84);
    }
    if (env[0] == NULL){
        write(1, "Error, env missing !\n", 21);
        return (84);
    }
    if (av[0][0] == '.')
        my_rpg();
    return (0);
}
