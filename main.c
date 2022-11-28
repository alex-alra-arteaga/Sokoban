/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** Japanese videogame displayed and fully playable in terminal
*/

// If all boxes are on storage locations, the player wins and the program must return 0.
// Otherwise, if none of the boxes can be moved anymore, he loses and the program must return 1.
// The game must be reset by pressing the space bar.
// Redimensioning the terminal must be handled
// As long as the terminal is too small to display the whole
//map, a centered message, asking the user to enlarge the terminal, must be displayed
// Play with arrows
// A valid map can only contains the characters SPACE, ‘\n’, ‘#’, ‘X’, ‘O’ and ‘P’.
// Need a -h flag
//• malloc, free, exit
//• (f)open, (f)close, (f)read, (f)write
//• getline, ioctl, usleep, sigaction, signal
//• stat, lstat, fstat

#include <fcntl.h>
#include "lib/my/utils/my.h"
#include "lib/my/utils/sokoban_structs.h"
#include <curses.h>

void error_handling_sokoban_n_h_flag(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr_stderr("Invalid number of arguments\n");
        exit (84);
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n\t./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tmap  ");
        my_putstr("file representing the warehouse map, ");
        my_putstr("containing ‘#’ for walls,\n");
        my_putstr("\t     ‘P’ for the player, ‘X’ for boxes and ‘O’ ");
        my_putstr("for storage locations.\n");
        exit(0);
    }
}

char **read_n_print_map(char **argv)
{
    char *buff;
    struct stat sb;
    int offset = 0;
    int len;
    int fd;
    char **map_splitted;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        my_putstr_stderr("\"ls: cannot open file '");
        my_putstr_stderr(argv[1]);
        my_putstr_stderr(": Permission denied\n");
        exit(84);
    }
    stat(argv[1], &sb);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    buff[0] = '\0';
    while ((len = read(fd, buff +offset, sb.st_size -offset)) > 0)
        offset = offset + len;
    if (buff == NULL)
        exit(84);
    buff[offset] = '\0';
    map_splitted = my_split(buff, '\n');
    return (map_splitted);
}

void copy_initial_map(t_sokoban *game)
{
    int i = 1;
    int j = 0;

    while (i < game->map->row) {
        while (j < game->map->col) {
            game->map->upd_map[i][j] = game->map->initial_map[i][j];
            j++;
        }
        j = 0;
        i++;
    }
}

int main(int argc, char **argv)
{
    t_sokoban *game;
    game = set_game_values(argv);
    error_handling_sokoban_n_h_flag(argc, argv);
    int is_running = -1;
    int i = 1;
    int row_ter = 0;
    int col_ter = 0;
    int key;
    game->map->num_of_storage = count_storage(game);
    game->map->storage_positions = store_storage_pos(game);

    // TODO: ERROR HANDLING, SOME EASY BONUSES
    keypad(initscr(), TRUE);
    cbreak();
    noecho();
    clear();
    wrefresh(stdscr);
    while (is_running == -1) {
        clear();
        check_storage_display(game);
        is_running = check_boxes_mobility_n_storage_correlation(game);
        if (key == 32)
            copy_initial_map(game);
        get_player_position(game);
        while (i < game->map->row) {
            row_ter = getmaxy(stdscr);
            col_ter = getmaxx(stdscr);
            mvprintw(((row_ter - game->map->row) / 2) + i, (col_ter - game->map->col) / 2, "%s", game->map->upd_map[i]);
            i++;
        }
        i = 1;
        if (row_ter < game->map->row || col_ter < game->map->col) {
            clear();
            row_ter = getmaxy(stdscr);
            col_ter = getmaxx(stdscr);
            mvprintw(((row_ter - game->map->row) / 2), (col_ter - game->map->col) / 2, "ENLARGE WINDOW");
        }
        key = wgetch(stdscr);
        switch (key) {
            case KEY_UP: move_up(game); break;
            case KEY_DOWN: move_down(game); break;
            case KEY_LEFT: move_left(game); break;
            case KEY_RIGHT: move_right(game); break;
        }
        // re-read map and if there are no X, return 0 and display win
        wrefresh(stdscr);
        if (key == 10) {
            wclear(stdscr);
            wrefresh(stdscr);
            break;
        }
    }
    endwin();
    return (is_running);
}
