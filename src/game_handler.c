/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** game_handler
*/

#include "include/jam.h"

void free_menu(sfRenderWindow *menu_win)
{
    if (menu_win)
        sfRenderWindow_destroy(menu_win);
}

void free_game()
{

}

int game_init(void)
{
    sfRenderWindow *menu_win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "JAM", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(menu_win, 60);
    sfEvent event;
    bool is_game = false;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu_win);
    while (!is_game || sfRenderWindow_isOpen(menu_win)) {
        while (sfRenderWindow_pollEvent(menu_win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(menu_win),
                free_menu(menu_win);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                sfRenderWindow_close(menu_win),
                free_menu(menu_win);
            if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
                // Manage button click here
            }
        }
        sfRenderWindow_clear(menu_win, sfBlack);
        // Display background here
        sfRenderWindow_display(menu_win);
    }
    free_menu(menu_win);
}


