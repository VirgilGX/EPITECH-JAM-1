/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** Duck Hunt new version
*/

#include "../includes/jam.h"

void display_h()
{
    my_putstr("USAGE\n");
    my_putstr("     ");
    my_putstr("./jam");
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("DESCRIPTION\n");
    my_putchar('\n');
    my_putstr("     ");
    my_putstr("Shoot all planets to destroy them without lose life\n");
    my_putstr("     ");
    my_putstr("You lose the game when you shoot and destroy Pluton\n");
    my_putchar('\n');
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            display_h();
        }
        return (0);
    }
    GLOBAL_T ALL;
    window_menu(&ALL);
    loop_game(&ALL);
    return (0);
}
