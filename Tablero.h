#ifndef TABLERO_H
#define TABLERO_H

#include <stdbio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "Ganador.h"

/*
#define PLAYER 1
#define PLAYER 2

#define LEFT 1
#define RIGHT 2
#define DROP 3
#define SWITCH 4

#define PLAYER_1_SYMBOL "X"
#define PLAYER_2_SYMBOL "0"
#define EMPTY_SYMBOL "*"
*/

// Prototipos de funciones
char** create_board(int rows, int cols);
void print_board(char** board, int rows, int cols);
void play_game(int rows, int cols, int pieces_to_win);
void play_move(char** board, int turn, int user_move, int rows);
bool play_is_valid(int number_args_read, int number_args_needed, double value, int cols, char** board);
bool game_over(char** board, int rows, int cols, int pieces_to_win);
bool is_blank_space(char** board, int value);
void change_turn(int* turn);
int get_play(char** board, int turn, int cols);
void destroy_board(char** board, int rows);
void read_args(int argc);


#endif // TABLERO_H
