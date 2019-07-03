/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** launch_fight
*/

#include <map.h>

void draw_everything(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->santa.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->mino.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->cycl.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->glad.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->player.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->wall.sprite, NULL);
    sfRenderWindow_drawText(window, game->fight_text, NULL);
    sfRenderWindow_display(window);
}

void launch_fight(sfRenderWindow *window, game_t *game, int nb)
{
    int cond = 0;
    sfTime time = sfClock_getElapsedTime(game->clocke);
    float seconds = time.microseconds / 1000000.0;
    sfVector2f pos = sfView_getCenter(game->view);

    pos.x -= 290;
    pos.y += 360;
    sfClock_restart(game->clockf);
    while (cond == 0) {
        time = sfClock_getElapsedTime(game->clocke);
        seconds = time.microseconds / 1000000.0;
        sfText_setString(game->fight_text, "\t\tfezhfejgkdshj !");
        sfText_setPosition(game->fight_text, pos);
        draw_everything(window, game);
        if (seconds > 0.5)
            cond = fight(game->fig, window, nb);
        if (cond == 2)
            game->alive = 0;
    }
}
