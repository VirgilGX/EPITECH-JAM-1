/*
** EPITECH PROJECT, 2023
** create sprite
** File description:
** tkt
*/

#include "include/jam.h"

sfSprite *create_sprite(char *name, int posx, int posy, double scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *my_texture = sfTexture_createFromFile(name, NULL);
    sfVector2f my_pos = {posx, posy};
    sfVector2f scaler = {scale, scale};
    sfSprite_setScale(sprite, scaler);
    sfSprite_setPosition(sprite, my_pos);
    sfSprite_setTexture(sprite, my_texture, sfFalse);
    return (sprite);
}

sfText *create_text(char *str, int x, int y, unsigned s)
{
    sfVector2f text_vec = {x, y};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/minecraft.ttf");
    sfText_setCharacterSize(text, s);
    sfText_setPosition(text, text_vec);
    sfText_setFont(text, font);
    sfText_setString(text, str);
    return (text);
}
