/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Japanese videogame displayed and fully playable in terminal
*/

#include <fcntl.h>
#include "my.h"
#include "sokoban_structs.h"
#include <curses.h>

void move_up(t_sokoban *game)
{
    int r = game->player->y;
    int c = game->player->x;

    if (r -2 < game->map->row && game->map->upd_map[r -1][c] == 'X' && (game->map->upd_map[r -2][c] == ' ' || game->map->upd_map[r -2][c] == 'O')) {
        game->map->upd_map[r -1][c] = ' ';
        game->map->upd_map[r -2][c] = 'X';
    }
    if (r -1 < game->map->row && game->map->upd_map[r -1][c] == ' ' || game->map->upd_map[r -1][c] == 'O') {
        game->map->upd_map[r][c] = ' ';
        game->map->upd_map[r -1][c] = 'P';
    }
}

void move_down(t_sokoban *game)
{
    int r = game->player->y;
    int c = game->player->x;

    if (r +2 < game->map->row && game->map->upd_map[r +1][c] == 'X' && (game->map->upd_map[r +2][c] == ' ' || game->map->upd_map[r +2][c] == 'O')) {
        game->map->upd_map[r +1][c] = ' ';
        game->map->upd_map[r +2][c] = 'X';
    }
    if (r +1 < game->map->row && (game->map->upd_map[r +1][c] == ' ' || game->map->upd_map[r +1][c] == 'O')) {
        game->map->upd_map[r][c] = ' ';
        game->map->upd_map[r +1][c] = 'P';
    }
}

void move_left(t_sokoban *game)
{
    int r = game->player->y;
    int c = game->player->x;

    if (c -2 < game->map->col && game->map->upd_map[r][c -1] == 'X' && (game->map->upd_map[r][c -2] == ' ' || game->map->upd_map[r][c -2] == 'O')) {
        game->map->upd_map[r][c -1] = ' ';
        game->map->upd_map[r][c -2] = 'X';
    }
    if (c -1 < game->map->col && (game->map->upd_map[r][c -1] == ' ' || game->map->upd_map[r][c -1] == 'O')) {
        game->map->upd_map[r][c] = ' ';
        game->map->upd_map[r][c -1] = 'P';
    }
}

void move_right(t_sokoban *game)
{
    int r = game->player->y;
    int c = game->player->x;

    if (c +2 < game->map->col && game->map->upd_map[r][c +1] == 'X' && (game->map->upd_map[r][c +2] == ' ' || game->map->upd_map[r][c +2] == 'O')) {
        game->map->upd_map[r][c +1] = ' ';
        game->map->upd_map[r][c +2] = 'X';
    }
    if (c +1 < game->map->col && (game->map->upd_map[r][c +1] == ' ' || game->map->upd_map[r][c +1] == 'O') ) {
        game->map->upd_map[r][c] = ' ';
        game->map->upd_map[r][c +1] = 'P';
    }
}