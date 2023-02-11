/*
** EPITECH PROJECT, 2022
** JAM.h
** File description:
** Protoype of many function
*/

#ifndef JAM_H_
    #define JAM_H_

    #include <SFML/Window/Mouse.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include "struct.h"
    #include <stdio.h>
    #include <time.h>

    /* MACRO OF MY STRUCTURE */
    #define WIN ALL->settings.window
    #define MODE ALL->settings.mode
    #define	EVENT ALL->settings.event
    /*#define TME ALL->pan
    #define IMG  ALL->pictures*/

/* BASIC FUNCTION */
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);

/* FUNCTION FOR MENU'S PROJECT */
void loop_game(GLOBAL_T *ALL);
void window_menu(GLOBAL_T *ALL);
void batman_univers(sfRenderWindow *window, sfEvent event);
void panther_univers(sfRenderWindow *window, sfEvent event);

#endif /* HUNTER_H_ */