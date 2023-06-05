/*
** EPITECH PROJECT, 2022
** game1
** File description:
** first part of the game
*/

#include "hunter.h"

void win(game *game)
{
    game->scl1.x = 1.22;
    game->scl1.y = 1.22;
    game->mode.width = 1080;
    game->mode.height = 860;
    game->mode.bitsPerPixel = 32;
    game->event;
    game->scl2.x = 1;
    game->scl2.y = 1;
    game->clock = sfClock_create();
    game->ms.x = 0;
    game->ms.y = 0;
    game->win = sfRenderWindow_create(game->mode,"ScapeX",sfDefaultStyle,NULL);
}

void close_win(game *game)
{
    while (sfRenderWindow_pollEvent(game->win, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfRenderWindow_close(game->win);
        }
    }
}

void gamefp(game *game)
{
    game->rect.top = 0;
    game->rect.width = 100;
    game->rect.height = 70;
    game->t1 = sfTexture_createFromFile("back.png", NULL);
    game->t2 = sfTexture_createFromFile("aviator.png", NULL);
    game->s1 = sfSprite_create();
    game->s2 = sfSprite_create();
}

void text(game * game)
{
    sfSprite_setTexture(game->s1, game->t1, sfTrue);
    sfSprite_setScale(game->s1, game->scl1);
    sfSprite_setTexture(game->s2, game->t2, sfTrue);
    sfSprite_setScale(game->s2, game->scl2);
}

void draw(game *game)
{
    sfRenderWindow_drawSprite(game->win, game->s1, NULL);
    sfSprite_setTextureRect(game->s2, game->rect);
    sfRenderWindow_drawSprite(game->win,game->s2, NULL);
    sfRenderWindow_display(game->win);
}