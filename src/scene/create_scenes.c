/*
** EPITECH PROJECT, 2019
** scenes
** File description:
** scenes
*/

#include "rpg.h"
#include "map.h"

scene_t *create_end_scene(void)
{
    scene_t *create = malloc(sizeof(*create));
    button_t **buttons = malloc(sizeof(*buttons) * 4);
    object_t **objects = malloc(sizeof(*objects) * 4);

    buttons[0] = malloc(sizeof(*buttons) * 6);
    init_button(buttons[0],
                get_vector(620, 820), get_vector(640, 210), close_window);
    objects[0] = create_object("ressources/quit_button2.png",
                            get_vector(620, 770), get_rect(0, 0, 640, 210));
    objects[1] = create_object("ressources/game_over.png",
                            get_vector(0, 0), get_rect(0, 0, 1920, 1080));
    objects[2] = create_object("ressources/you_win.png",
                            get_vector(0, 0), get_rect(0, 0, 1920, 1080));
    create->buttons = buttons;
    create->objs = objects;
    create->nb_objs = 1;
    create->click = 0;
    return (create);
}

scene_t *create_pause_scene(void)
{
    scene_t *create = malloc(sizeof(*create));
    button_t **buttons = malloc(sizeof(*buttons) * 4);
    for (int i = 0; i < 3; i++)
        buttons[i] = malloc(sizeof(*buttons) * 6);

    init_button(buttons[0],
                get_vector(600, 330), get_vector(640, 210), previous_scene);
    init_button(buttons[1],
                get_vector(600, 560), get_vector(640, 210), next_scene);
    init_button(buttons[2],
                get_vector(600, 790), get_vector(640, 210), close_window);
    create->objs = get_objs_pause();
    create->buttons = buttons;
    create->nb_objs = 4;
    create->click = 0;
    return (create);
}

scene_t *create_game_scene(void)
{
    scene_t *create = malloc(sizeof(*create));

    create->buttons = NULL;
    create->objs = get_objs_game();
    create->nb_objs = 21;
    create->click = 0;
    return (create);
}

scene_t *create_start_scene(void)
{
    scene_t *create = malloc(sizeof(*create));
    button_t **buttons = malloc(sizeof(*buttons) * 4);

    for (int i = 0; i < 2; i++)
        buttons[i] = malloc(sizeof(*buttons) * 6);
    init_button(buttons[0], get_vector(620, 400),
                get_vector(640, 210), next_scene);
    init_button(buttons[1], get_vector(620, 700),
                get_vector(640, 210), close_window);
    create->buttons = buttons;
    create->objs = get_objs_start();
    create->nb_objs = 1;
    create->click = 0;
    return (create);
}
