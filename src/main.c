/*
** EPITECH PROJECT, 2023
** JAM 1
** File description:
** main
*/

#include "include/jam.h"

int display_usage(void)
{
    printf("USAGE\n\t./jam\n\nGOAL\n\tfind Charlo to stop him");
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
