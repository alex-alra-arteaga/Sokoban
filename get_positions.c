/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Japanese videogame displayed and fully playable in terminal
*/

#include <fcntl.h>
#include "lib/my/utils/my.h"
#include "lib/my/utils/sokoban_structs.h"
#include <curses.h>

void get_player_position(t_sokoban *game)
{
    int j = 0;
    int i = 1;
    static int pass = 0;

    while (i < game->map->row) {
        while (game->map->upd_map[i][j]) {
            if (game->map->upd_map[i][j] == 'P') {
                game->player->x = j;
                game->player->y = i;
                if (pass++ == 0) {
                    game->initial_player->x = j;
                    game->initial_player->y = i;
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
}

int count_storage(t_sokoban *game)
{
    int i = 0;
    int j = 0;
    int cnt = 0;

    while (i < game->map->row) {
        while (j < game->map->col) {
            (game->map->upd_map[i][j] == 'O') ? cnt++, j++ : j++;
        }
        j = 0;
        i++;
    }
    return (cnt);
}

t_position *store_storage_pos(t_sokoban *game)
{
    int i = 0;
    t_position *storages_pos;
    if (game->map->num_of_storage == 0)
        exit(84);
    storages_pos = malloc(sizeof(t_position) * game->map->num_of_storage);
    while (i < game->map->num_of_storage) {
        storages_pos[i] = get_storage_position(game);
        i++;
    }
    // store them with struct t_position
    // iterate map and if in his position there's not any 'P' or 'X', print itself
    return (storages_pos);
}

t_position get_storage_position(t_sokoban *game)
{
    static int j = 0;
    static int i = 1;
    t_position s1 = {0, 0};
    int pass = 0;

    while (i < game->map->row) {
        while (j < game->map->col) {
            (game->map->upd_map[i][j] == 'O') ? (s1.x = j, s1.y = i, j++, pass++) : j++;
        }
        if (pass == 1)
            break;
        j = 0;
        i++;
    }
    return (s1);
}
