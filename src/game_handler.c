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
    exit(0);
}

void free_game() {}

menu_t init_menu()
{
    menu_t buffer;
    buffer.univer_selection = malloc(sizeof(sfSprite *) * 4);
    buffer.univer_selection[0] = create_sprite("resources/images/jmj.jpg", 150, 450, 0.2);
    buffer.univer_selection[1] = create_sprite("resources/images/gotham.jpg", 750, 450, 0.2);
    buffer.univer_selection[2] = create_sprite("resources/images/plage.jpg", 1400, 450, 0.2);
    buffer.univer_selection[3] = NULL;
    return buffer;
}

void display_menu(game_t g)
{
    sfSprite *logo = create_sprite("resources/images/logo.png", 775, 100, 1);
    sfRenderWindow_drawSprite(g.window, logo, 0);
    for (int i = 0; g.menu.univer_selection[i] != NULL; i++) {
        sfRenderWindow_drawSprite(g.window, g.menu.univer_selection[i], 0);
    }
}

int check_univers(game_t g, sfVector2i mouse)
{
    sfFloatRect shape;
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
    switch (g.state) {
        case 1:
            sfSprite_setPosition(g.charlo, (sfVector2f){1194, 1009});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            break;
        case 2:
            sfSprite_setPosition(g.charlo, (sfVector2f){510, 663});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            break;
        case 3:
            sfSprite_setPosition(g.charlo, (sfVector2f){1782, 567});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            break;
        default:
            break;
    }
    return g;
}

int check_charlo(game_t g, sfVector2i mouse)
{
    sfFloatRect shape = sfSprite_getGlobalBounds(g.charlo);
        if (sfFloatRect_contains(&shape, mouse.x, mouse.y)) {
            return (-1);
        }
    return g.state;
}

void display_game(game_t g)
{
    sfRenderWindow_display(g.window);
    sfRenderWindow_drawSprite(g.window, g.current_background, 0);
    sfRenderWindow_drawSprite(g.window, g.charlo, 0);
}

game_t update_game(game_t g)
{
    sfRenderWindow_clear(g.window, sfBlack);
    switch (g.state) {
        case 1:
            g.current_background = create_sprite("resources/images/jmj.jpg", 0, 0, 1);
            break;
        case 2:
            g.current_background = create_sprite("resources/images/gotham.jpg", 0, 0, 1);
            break;
        case 3:
            g.current_background = create_sprite("resources/images/plage.jpg", 0, 0, 1);
            break;
        default:
            break;
    }
    return g;
}

game_t game_loop(game_t g)
{
    sfVector2i mouse;
    g = update_game(g);
    while (sfRenderWindow_isOpen(g.window)) {
        mouse = sfMouse_getPosition(g.window);
         while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            if (g.event.type == sfEvtClosed)
                    sfRenderWindow_close(g.window);
            if (g.event.type == sfEvtKeyPressed && g.event.key.code == sfKeyEscape)
                    sfRenderWindow_close(g.window);
            if (g.event.type == sfEvtMouseButtonPressed && g.event.mouseButton.button == sfMouseLeft) {
                g.state = check_charlo(g, mouse);
            }
        }
        if (g.state == -1) {
            printf("gagné\n");
            exit(0);
        }
        display_game(g);
    }
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
        }
            if (g.state > 0)
                g = game_loop(set_charlo(g));
            sfRenderWindow_display(g.window);
            display_menu(g);
    }
    sfRenderWindow_clear(g.window, sfBlack);
    free_menu(g.window);
    return 0;
}


