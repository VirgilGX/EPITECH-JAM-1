/*
** EPITECH PROJECT, 2022
** menu.c
** File description:
** Duck Hunt new version
*/

#include "../includes/jam.h"

void window_menu(GLOBAL_T *ALL)
{
    MODE.bitsPerPixel = 32;
    MODE.height = 1080;
    MODE.width = 1920;
    WIN = sfRenderWindow_create(MODE, "JAM", sfResize | sfClose, NULL);
    sfWindow_setFramerateLimit(WIN, 80);
}

void univers1(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 853 && mouse.x <= 1074) {
        if (mouse.y >= 352 && mouse.y <= 509) {
            if (event.type == sfEvtMouseButtonPressed) {
                batman_univers(window, event);
            }
        }
    }
}

void univers2(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 150 && mouse.x <= 475) {
        if (mouse.y >= 350 && mouse.y <= 536) {
            if (event.type == sfEvtMouseButtonPressed) {
                panther_univers(window, event);
            }
        }
    }
}

void univers3(sfRenderWindow *window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= 1401 && mouse.x <= 1720) {
        if (mouse.y >= 351 && mouse.y <= 529) {
            if (event.type == sfEvtMouseButtonPressed) {
                shang_chi_univers(window, event);
            }
        }
    }
}

void loop_game(GLOBAL_T *ALL)
{
    int batx = 100;
    sfTexture *bat_text = sfTexture_createFromFile("./image/Man bat.png", NULL);
    sfSprite *bat_s = sfSprite_create();
    sfVector2f bat_scl = {4, 4};
    sfVector2f bat_loc = {batx, 50};
    sfClock *bat_clock = sfClock_create();
    sfIntRect bat_rect = { 0, 0, 76, 76 };
    //sfMusic *bat_music = sfMusic_createFromFile("./song/Man-Bat-Tribute.ogg");
    sfSprite_setTexture(bat_s, bat_text, sfTrue);
    sfSprite_setTextureRect(bat_s, bat_rect);
    sfSprite_setPosition(bat_s, bat_loc);
    sfSprite_setScale(bat_s, bat_scl);
    //sfMusic_play(bat_music);

    int bat2x = 1700;
    sfTexture *bat2_text = sfTexture_createFromFile("./image/Man bat.png", NULL);
    sfSprite *bat2_s = sfSprite_create();
    sfVector2f bat2_scl = {4, 4};
    sfVector2f bat2_loc = {bat2x, 700};
    sfClock *bat2_clock = sfClock_create();
    sfIntRect bat2_rect = { 0, 0, 76, 76 };
    sfSprite_setTexture(bat2_s, bat2_text, sfTrue);
    sfSprite_setTextureRect(bat2_s, bat2_rect);
    sfSprite_setPosition(bat2_s, bat2_loc);
    sfSprite_setScale(bat2_s, bat2_scl);

    sfTexture *img = sfTexture_createFromFile("./image/Univers batman.jpg", NULL);
    sfSprite *img_s = sfSprite_create();
    sfVector2f img_scl = {0.3, 0.3};
    sfVector2f img_loc = {850, 350};
    sfSprite_setTexture(img_s, img, sfTrue);
    sfSprite_setPosition(img_s, img_loc);
    sfSprite_setScale(img_s, img_scl);

    sfTexture *img2 = sfTexture_createFromFile("./image/Univers Black Panther.jpg", NULL);
    sfSprite *img2_s = sfSprite_create();
    sfVector2f img2_scl = {0.17, 0.17};
    sfVector2f img2_loc = {150, 350};
    sfSprite_setTexture(img2_s, img2, sfTrue);
    sfSprite_setPosition(img2_s, img2_loc);
    sfSprite_setScale(img2_s, img2_scl);

    sfTexture *img3 = sfTexture_createFromFile("./image/Univers Shang Chi.jpg", NULL);
    sfSprite *img3_s = sfSprite_create();
    sfVector2f img3_scl = {0.25, 0.25};
    sfVector2f img3_loc = {1400, 350};
    sfSprite_setTexture(img3_s, img3, sfTrue);
    sfSprite_setPosition(img3_s, img3_loc);
    sfSprite_setScale(img3_s, img3_scl);

    while (sfRenderWindow_isOpen(WIN)) {
        while (sfRenderWindow_pollEvent(WIN, &EVENT)) {
            if (EVENT.type == sfEvtClosed) {
                sfRenderWindow_close(WIN);
            } else if (((EVENT.type == sfEvtKeyPressed) &&
                (EVENT.key.code == sfKeyM))) {
                sfRenderWindow_close(WIN);
            }
        }

        sfTime bat_time = sfClock_getElapsedTime(bat_clock);
        if (bat_time.microseconds > 200000.0) {
            if (bat_rect.left < 152) {
                sfSprite_setTextureRect(bat_s, bat_rect);
                bat_rect.left = bat_rect.left + 76;
            } else if (bat_rect.left >= 152) {
                sfSprite_setTextureRect(bat_s, bat_rect);
                bat_rect.left = 0;
            }
            sfClock_restart(bat_clock);
        }
        batx = batx + 4;
        sfVector2f vilain = { batx, 50 };
        sfSprite_setPosition(bat_s, vilain);
        if (batx >= 1920) {
            batx = 0;
        }

        sfTime bat2_time = sfClock_getElapsedTime(bat2_clock);
        if (bat2_time.microseconds > 200000.0) {
            if (bat2_rect.left < 152) {
                sfSprite_setTextureRect(bat2_s, bat2_rect);
                bat2_rect.left = bat2_rect.left + 76;
            } else if (bat2_rect.left >= 152) {
                sfSprite_setTextureRect(bat2_s, bat2_rect);
                bat2_rect.left = 0;
            }
            sfClock_restart(bat2_clock);
        }
        bat2x = bat2x - 4;
        sfVector2f vilain2 = { bat2x, 700 };
        sfSprite_setPosition(bat2_s, vilain2);
        if (bat2x <= 0) {
            bat2x = 1920;
        }

        sfRenderWindow_clear(WIN, sfBlack);
        sfRenderWindow_drawSprite(WIN, img_s, NULL);
        sfRenderWindow_drawSprite(WIN, img2_s, NULL);
        sfRenderWindow_drawSprite(WIN, img3_s, NULL);
        sfRenderWindow_drawSprite(WIN, bat_s, NULL);
        sfRenderWindow_drawSprite(WIN, bat2_s, NULL);
        sfRenderWindow_display(WIN);
        univers1(WIN, EVENT);
        univers2(WIN, EVENT);
        univers3(WIN, EVENT);
    }
}
