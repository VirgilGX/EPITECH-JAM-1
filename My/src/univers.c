/*
** EPITECH PROJECT, 2022
** univers.c
** File description:
** Duck Hunt new version
*/

#include "../includes/jam.h"

void batman_univers(sfRenderWindow *window, sfEvent event)
{
    sfTexture *uni = sfTexture_createFromFile("./image/Univers batman.jpg", NULL);
    sfMusic *music = sfMusic_createFromFile("./song/Dark-Knight.ogg");
    sfSprite *uni_s = sfSprite_create();
    sfVector2f uni_scl = {2.56, 2};
    sfSprite_setTexture(uni_s, uni, sfTrue);
    sfSprite_setScale(uni_s, uni_scl);
    sfMusic_play(music);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            } else if (((event.type == sfEvtKeyPressed) &&
                (event.key.code == sfKeyM))) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, uni_s, NULL);
        sfRenderWindow_display(window);
    }
}

void panther_univers(sfRenderWindow *window, sfEvent event)
{
    sfTexture *uni = sfTexture_createFromFile("./image/Univers Black Panther.jpg", NULL);
    sfSprite *uni_s = sfSprite_create();
    sfMusic *music = sfMusic_createFromFile("./song/Waterfall-Fight.ogg");
    sfSprite_setTexture(uni_s, uni, sfTrue);
    sfMusic_play(music);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            } else if (((event.type == sfEvtKeyPressed) &&
                (event.key.code == sfKeyM))) {
                sfRenderWindow_close(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, uni_s, NULL);
        sfRenderWindow_display(window);
    }
}