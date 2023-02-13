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

sfIntRect create_intrect_bat(void)
{
    sfIntRect bat;
    bat.left = 0;
    bat.top = 0;
    bat.width = 32;
    bat.height = 32;
    return (bat);
}

game_t animate_bat(game_t g)
{
    g.bat_rect.left += 32;
    if (g.bat_rect.left >= 192)
        g.bat_rect.left = 0;
    sfSprite_setTextureRect(g.bat, g.bat_rect);
    return g;
}

game_t check_clock(game_t g)
{
    float seconds = 0;
    sfTime time = sfClock_getElapsedTime(g.clock);
    seconds = time.microseconds / 2500000.0;
    if (seconds > (0.04)) {
        g = animate_bat(g);
        sfClock_restart(g.clock);
    }
    return g;
}

menu_t init_menu()
{
    menu_t buffer;
    sfSoundBuffer *sound_buff = sfSoundBuffer_createFromFile("resources/sounds/teleport.ogg");
    buffer.teleport = sfSound_create();
    sfSound_setBuffer(buffer.teleport, sound_buff);
    buffer.ambiant = sfMusic_createFromFile("resources/sounds/menu.ogg");
    sfMusic_play(buffer.ambiant);
    sfMusic_setLoop(buffer.ambiant, sfTrue);
    buffer.univer_selection = malloc(sizeof(sfSprite *) * 4);
    buffer.univer_selection[0] = create_sprite("resources/images/jmj.jpg", 150, 450, 0.2);
    buffer.univer_selection[1] = create_sprite("resources/images/gotham.jpg", 750, 450, 0.2);
    buffer.univer_selection[2] = create_sprite("resources/images/plage.jpg", 1400, 450, 0.2);
    buffer.univer_selection[3] = NULL;
    return buffer;
}

void display_menu(game_t g)
{
    sfRenderWindow_drawSprite(g.window, g.bg, 0);
    sfRenderWindow_drawSprite(g.window, g.logo, 0);
    for (int i = 0; g.menu.univer_selection[i] != NULL; i++)
        sfRenderWindow_drawSprite(g.window, g.menu.univer_selection[i], 0);
}

int check_univers(game_t g, sfVector2i mouse)
{
    sfFloatRect shape;
    for (int i = 0; g.menu.univer_selection[i] != NULL; i++) {
        shape = sfSprite_getGlobalBounds(g.menu.univer_selection[i]);
        if (sfFloatRect_contains(&shape, mouse.x, mouse.y)) {
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
    game.bg = create_sprite("resources/images/menu-background.png", 0, 0, 1);
    game.logo = create_sprite("resources/images/logo.png", 750, 100, 1);
    game.charlo = create_sprite("resources/images/charlo.png", 1100, 100, 0.40);
    game.bat = create_sprite("resources/images/bat.png", 0, 0, 2);
    game.bat_rect = create_intrect_bat();
    sfSprite_setTextureRect(game.bat, game.bat_rect);
    menu_t menu = init_menu();
    game.menu = menu;
    sfEvent event = {0};
    game.event = event;
    game.state = 0;
    game.clock = sfClock_create();
    game.win = create_text("Victoire", 500, 500, 100);
    return game;
}

game_t set_charlo(game_t g)
{
    switch (g.state) {
        case 1:
            sfSprite_setPosition(g.charlo, (sfVector2f){1194, 1009});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            g.map_music = sfMusic_createFromFile("resources/sounds/jmj.ogg");
            sfMusic_play(g.map_music);
            break;
        case 2:
            sfSprite_setPosition(g.charlo, (sfVector2f){696, 728});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            g.map_music = sfMusic_createFromFile("resources/sounds/gotham.ogg");
            sfMusic_play(g.map_music);
            break;
        case 3:
            sfSprite_setPosition(g.charlo, (sfVector2f){1782, 567});
            sfSprite_setScale(g.charlo, (sfVector2f){0.1, 0.1});
            g.map_music = sfMusic_createFromFile("resources/sounds/plage.ogg");
            sfMusic_play(g.map_music);
            break;
        default:
            break;
    }
    sfMusic_setLoop(g.map_music, sfTrue);
    return g;
}

int check_charlo(game_t g, sfVector2i mouse)
{
    sfFloatRect shape = sfSprite_getGlobalBounds(g.charlo);
        if (sfFloatRect_contains(&shape, mouse.x, mouse.y))
            return (-1);
    return g.state;
}

game_t display_game(game_t g)
{
    sfRenderWindow_display(g.window);
    sfRenderWindow_drawSprite(g.window, g.current_background, 0);
    sfRenderWindow_drawSprite(g.window, g.charlo, 0);
    if (g.state == 2) {
        g = check_clock(g);
        sfRenderWindow_setMouseCursorVisible(g.window, false);
        sfRenderWindow_drawSprite(g.window, g.bat, 0);
    }
    return g;
}

game_t update_game(game_t g)
{
    sfRenderWindow_clear(g.window, sfBlack);
    switch (g.state) {
        case 0:
            display_menu(g);
            break;
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
        mouse = sfMouse_getPositionRenderWindow(g.window);
        sfSprite_setPosition(g.bat, (sfVector2f) {mouse.x - 30, mouse.y - 30});
        while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            if (g.event.type == sfEvtClosed)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtKeyPressed && g.event.key.code == sfKeyEscape)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtMouseButtonPressed && g.event.mouseButton.button == sfMouseLeft) {
                g.state = check_charlo(g, mouse);
            }
        }
        if (g.state == -1) {
            sfRenderWindow_setMouseCursorVisible(g.window, true);
            sfMusic_stop(g.map_music);
            sfMusic_setLoop(g.map_music, sfFalse);
            sfRenderWindow_drawText(g.window, g.win, 0);
            g.state = 0;
            update_game(g);
            return g;
        }
        g = display_game(g);
    }
    return g;
}

int game_init(void)
{
    game_t g = init_game();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(g.window);
    while (sfRenderWindow_isOpen(g.window)) {
        mouse = sfMouse_getPositionRenderWindow(g.window);
        while (sfRenderWindow_pollEvent(g.window, &g.event)) {
            if (g.event.type == sfEvtClosed)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtKeyPressed && g.event.key.code == sfKeyEscape)
                sfRenderWindow_close(g.window),
                free_menu(g.window);
            if (g.event.type == sfEvtMouseButtonPressed && g.event.mouseButton.button == sfMouseLeft)
                g.state = check_univers(g, mouse);
        }
        if (g.state > 0) {
            sfSound_play(g.menu.teleport);
            sfMusic_setLoop(g.menu.ambiant, sfFalse);
            sfMusic_stop(g.menu.ambiant);
            g = game_loop(set_charlo(g));
        }
        sfRenderWindow_display(g.window);
        display_menu(g);
    }
    sfRenderWindow_clear(g.window, sfBlack);
    return 0;
}
