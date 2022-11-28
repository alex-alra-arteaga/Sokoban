/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Japanese videogame displayed and fully playable in terminal
*/

#include "my.h"
#include "sokoban_structs.h"

t_position *set_position_box_values()
{
    t_position *box;
    box = malloc(sizeof(t_position));
    box->x = 0;
    box->y = 0;

    return (box);
}

t_position *set_position_initial_player_values()
{
    t_position *initial_player;
    initial_player = malloc(sizeof(t_position));
    initial_player->y = 0;
    initial_player->y = 0;
    return (initial_player);
}

t_position *set_position_player_values()
{
    t_position *player;
    player = malloc(sizeof(t_position));
    player->x = 0;
    player->y = 0;
    return (player);
}

t_position *set_position_storage_values()
{
    t_position *storage;
    storage = malloc(sizeof(t_position));
    storage->x = 0;
    storage->y = 0;
    return (storage);
}
t_map *set_map_values(char **argv)
{
    t_map *map;
    char **map_splitted;
    map = malloc(sizeof(t_map));
    map_splitted = read_n_print_map(argv);
    map->col = my_getnbr(map_splitted[0]);
    map->row = my_strlen(map_splitted[1]);
    map->initial_map = my_arrdup(map_splitted, map->row);
    map->upd_map = my_arrdup(map_splitted, map->row);
    map->num_of_storage = 0;
    map->storage_positions = NULL;
    return (map);
}

t_sokoban *set_game_values(char **argv)
{
    t_sokoban *game;
    game = malloc(sizeof(t_sokoban));
    game->map = set_map_values(argv);
    game->storage = set_position_storage_values();
    game->player= set_position_player_values();
    game->initial_player = set_position_initial_player_values();
    game->box = set_position_box_values();
    return (game);
}