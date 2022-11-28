/*
** EPITECH PROJECT, 2022
** fnc_ptr_ls.h
** File description:
** Contains the prototypes of all the structs
*/

#ifndef BSQ_STRUCTS_H_
    #define BSQ_STRUCTS_H_

    #include <stdbool.h>

    typedef struct s_position {
        int x;
        int y;
    }t_position;

    typedef struct s_map {
        char **initial_map;
        char **upd_map;
        int col;
        int row;
        int num_of_storage;
        t_position *storage_positions;
    }t_map;

    typedef struct s_sokoban {
        t_position *box;
        t_position *player;
        t_position *initial_player;
        t_position *storage;
        t_map *map;
    }t_sokoban;
#endif
