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

void check_storage_display(t_sokoban *game)
{
    int i = 0;
    int j = 0;
    int cnt = 0;

    while (cnt < game->map->num_of_storage) {
        while (i < game->map->row) {
            while (j < game->map->col) {
                (i == game->map->storage_positions[cnt].y && j == game->map->storage_positions[cnt].x
                 && game->map->upd_map[i][j] == ' ') ?
                (game->map->upd_map[i][j] = 'O', j++) : j++;
            }
            j = 0;
            i++;
        }
        i = 0;
        cnt++;
    }
}

bool includes_two_adyacent_walls(t_sokoban *game, int i, int j)
{
    if ((game->map->upd_map[i +1][j] == '#' && game->map->upd_map[i][j +1] == '#')
        || (game->map->upd_map[i +1][j] == '#' && game->map->upd_map[i][j -1] == '#')
        || (game->map->upd_map[i -1][j] == '#' && game->map->upd_map[i][j +1] == '#')
        || (game->map->upd_map[i -1][j] == '#' && game->map->upd_map[i][j -1] == '#'))
        return (true);
    return (false);
}

int check_boxes_mobility_n_storage_correlation(t_sokoban *game)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int cnt_boxes = 0;

    while (cnt < game->map->num_of_storage) {
        while (i < game->map->row) {
            while (j < game->map->col) {
                (i == game->map->storage_positions[cnt].y && j == game->map->storage_positions[cnt].x
                 && game->map->upd_map[i][j] == 'X') ?
                (cnt_boxes++, j++) : j++;
            }
            if (cnt_boxes == game->map->num_of_storage)
                return (1);
            j = 0;
            i++;
        }
        i = 0;
        cnt++;
    }
    i = 0;
    j = 0;
    cnt = 0;
    while (i < game->map->row) {
        while (j < game->map->col) {
            (game->map->upd_map[i][j] == 'X' && includes_two_adyacent_walls(game, i, j)) ?
            (j++, cnt++) : j++;
            if (cnt == game->map->num_of_storage)
                return (0);
        }
        j = 0;
        i++;
    }
    return (-1);
}
