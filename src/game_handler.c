/*
** EPITECH PROJECT, 2023
** JAM
** File description:
** game_handler
*/

#include "include/jam.h"

void free_menu(sfRenderWindow *w)
{
    if (w)
        sfRenderWindow_destroy(w);
}

void free_game() {}

menu_t init_menu()
{
    menu_t buffer;
    buffer.univer_selection = malloc(sizeof(sfSprite *) * 4);
    buffer.univer_selection[0] = create_sprite("resources/images/jmj.jpg", 850, 350, 0.2);
    buffer.univer_selection[1] = create_sprite("resources/images/gotham.jpg", 150, 350, 0.2);
    buffer.univer_selection[2] = create_sprite("resources/images/plage.jpg", 1400, 350, 0.2);
    buffer.univer_selection[3] = NULL;
    return buffer;
}

void display_menu(game_t g)
{
    for (int i = 0; g.menu.univer_selection[i] != NULL; i++) {
        sfRenderWindow_drawSprite(g.window, g.menu.univer_selection[i], 0);
    }
}

int check_univers(game_t g, sfVector2i mouse)
{
    sfFloatRect shape;
    printf("%d, %d\n", mouse.x, mouse.y);
    for (int i = 0; g.menu.univer_selection[i] != NULL; i++) {
        shape = sfSprite_getGlobalBounds(g.menu.univer_selection[i]);
        if (sfFloatRect_contains(&shape, mouse.x, mouse.y)) {
            printf("%d\n", i);
            return (i + 1);
        }
    }
    return g.state;
}

game_t init_game()
{
    game_t game;
    game.window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "JAM", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game.window, 60);
    game.charlo = create_sprite("resources/images/charlo.png", 0, 0, 1);
    menu_t menu = init_menu();
    game.menu = menu;
    sfEvent event;
    game.event = event;
    game.state = 0;
    return game;
}

game_t set_charlo(game_t g)
{
    return g;
}

game_t game_loop(game_t g)
{
    printf("%d\n", g.state);
    exit(0);
}

int game_init(void)
{
    game_t g = init_game();
    sfVector2i mouse = sfMouse_getPosition(g.window);
    while (sfRenderWindow_isOpen(g.window)) {
        mouse = sfMouse_getPosition(g.window);
        while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            if (g.event.type == sfEvtClosed)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtKeyPressed && g.event.key.code == sfKeyEscape)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtMouseButtonPressed && g.event.mouseButton.button == sfMouseLeft) {
                g.state = check_univers(g, mouse);
            }
            if (g.state > 0)
                g = game_loop(set_charlo(g));
            sfRenderWindow_display(g.window);
            display_menu(g);
        }
    }
    sfRenderWindow_clear(g.window, sfBlack);
    // free_menu(g.window);
    return 0;
}


