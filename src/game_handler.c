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

menu_t init_menu()
{
    menu_t buffer;
    buffer.univer_selection = malloc(sizeof(sfSprite *) * 4);
    buffer.univer_selection[0] = create_sprite("assets/pictures/batman.jpg", 850, 350, 0.35);
    buffer.univer_selection[1] = create_sprite("assets/pictures/black_panther.jpg", 150, 350, 0.17);
    buffer.univer_selection[2] = create_sprite("assets/pictures/shang_chi.jpg", 1400, 350, 0.25);
    buffer.univer_selection[3] = NULL;
    return buffer;
}

void display_menu(sfWindow *window, menu_t menu)
{
    for (int i = 0; menu.univer_selection[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window, menu.univer_selection[i], 0);
    }
}

int check_univers(menu_t univers, sfVector2i mouse)
{
    sfFloatRect shape;
    printf("%d, %d\n", mouse.x, mouse.y);
    for (int i = 0; univers.univer_selection[i] != NULL; i++) {
        shape = sfSprite_getGlobalBounds(univers.univer_selection[i]);
        if (sfFloatRect_contains(&shape, mouse.x, mouse.y)) {
            printf("%d\n", i);
        }
    }
}

int game_init(void)
{
    sfRenderWindow *menu_win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "JAM", sfClose, NULL);
    menu_t menu = init_menu();
    sfRenderWindow_setFramerateLimit(menu_win, 60);
    sfEvent event;
    bool is_game = false;
    sfVector2i mouse = sfMouse_getPosition(menu_win);
    while (!is_game || sfRenderWindow_isOpen(menu_win)) {
        mouse = sfMouse_getPosition(menu_win);
        while (sfRenderWindow_pollEvent(menu_win, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(menu_win),
                free_menu(menu_win);
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
                sfRenderWindow_close(menu_win),
                free_menu(menu_win);
            if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
                check_univers(menu, mouse);
            }
        }
        sfRenderWindow_display(menu_win);
        display_menu(menu_win, menu);
    }
    sfRenderWindow_clear(menu_win, sfBlack);
    // free_menu(menu_win);
    return 0;
}


