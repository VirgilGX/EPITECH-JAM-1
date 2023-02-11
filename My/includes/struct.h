/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** Structure for Hunter's project
*/

#include "jam.h"

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct PARAMETER {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
} PARAMETER_T;

typedef struct IMG {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f scale;
	sfVector2f locate;
    sfVector2f origin;
} IMG_T;

typedef struct TME {
	sfClock *clock;
	sfTime time;
	sfIntRect rect;
} TME_T;

typedef struct GLOBAL {
    PARAMETER_T settings;
} GLOBAL_T;

#endif /* STRUCT_H_ */