/*
** EPITECH PROJECT, 2023
** Sans titre(Espace de travail)
** File description:
** jam
*/

#ifndef JAM
    #define JAM
    #define GOOD_EXIT 0
    #define ERROR_EXIT -1
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>
    #include "../../lib/src/include/my_lib.h"

typedef struct Picture {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfIntRect rect;
} picture_t;

typedef struct Game_time {
    sfClock *clock;
    sfTime time;
    float seconds;
} game_time_t;

typedef struct menu {
    sfSprite **univer_selection;
} menu_t;

int game_init(void);
sfSprite *create_sprite(char *name, int posx, int posy, double scale);
sfText *create_text(char *str, int x, int y, unsigned s);
#endif
