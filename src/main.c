/*
** EPITECH PROJECT, 2023
** JAM 1
** File description:
** main
*/

#include "include/jam.h"

int display_usage(void)
{
    printf("USAGE\n     ./jam\n\nDESCRIPTION\n     Shoot all planets to destroy them without lose life\n     You lose the game when you shoot and destroy Pluton\n");
    fflush(stdout);
    return (GOOD_EXIT);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        if (strcmp(argv[1], "-h") == 0)
            return display_usage();
    return game_init();
}
