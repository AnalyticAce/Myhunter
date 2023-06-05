/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** Omega
*/

#include "hunter.h"

void movereact(game *game)
{
    if (game->rect.left < 700 - game->offset) {
        (game->rect.left = game->rect.left + game->offset);
    } else {
        game->rect.left = 0;
    }
}

void move_space(game *game)
{
    game->t = sfClock_getElapsedTime(game->clock);
    game->sec = game->t.microseconds / 10000.0;
    if (game->sec > 1.5) {
        movereact(game);
        sfClock_restart(game->clock);
        game->ms.x += 5;
        sfSprite_setPosition(game->s2, game->ms);
        if (game->ms.x > 1080) {
            game->ms.x = 0; game->ms.y = rand() % 800;
        }
    }
}

void kill_bird(game *game)
{
    game->w = sfSprite_getPosition(game->s2);
    game->h = sfMouse_getPositionRenderWindow(game->win);
    if (game->event.type = sfEvtMouseButtonPressed) {
        if ((game->h.x > game->ms.x && game->h.x < (game->ms.x + 70))
            && ((game->h.y > game->ms.y) && game->h.y < (game->ms.y + 70))) {
            game->ms.x = 1;
            game->ms.y = rand() % 800;
        }
    }
}

int main (int ac, char **av)
{
    if(ac != 1 && (av[1][0] == '-' && av[1][1] == 'h')) {
        my_putstr("\t_The obj of the game is to take down the spaceship.\n");
        my_putstr("\t_To EXIT the game press the (X) button\n");
        my_putstr("HAVE FUN (:\n");
        return 0;
    }
    game *Game = malloc(sizeof(game));
    win(Game);
    gamefp(Game);
    while (sfRenderWindow_isOpen(Game->win)) {
        close_win(Game);
        move_space(Game);
        movereact(Game);
        text(Game);
        draw(Game);
        kill_bird(Game);
    }
    return 0;
    free(Game);
}
