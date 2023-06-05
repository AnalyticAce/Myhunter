/*
** EPITECH PROJECT, 2022
** makefile
** File description:
** hunter
*/

#ifndef hunter_
    #define hunter_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>

typedef struct game {
    sfRenderWindow *win;
    int offset;
    sfVideoMode mode;
    sfEvent event;
    sfTexture *t1;
    sfSprite *s1;
    sfTexture *t2;
    sfSprite *s2;
    sfVector2f scl1;
    sfVector2f scl2;
    sfIntRect rect;
    int a;
    int b;
    sfVector2f ms;
    sfClock *clock;
    sfTime t;
    sfVector2f pos;
    float sec;
    sfVector2i h;
    sfVector2f w;
}game;

void my_putchar(char c);
int my_putstr(char *str);
void text(game * game);
void win(game *game);
void close_win(game *game);
void draw(game *game);
void gamefp(game *game);
void movereact(game *game);
void move_space(game *game);
void kill_bird(game *game);
#endif
