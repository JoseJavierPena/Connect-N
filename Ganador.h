#ifndef GANADOR_H
#define GANADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool game_won(char** board, int rows, int cols, int pieces_to_win);
bool game_tie(char** board, int rows, int cols, int pieces_to_win);
bool row_win(char** board, int rows, int cols, int pieces_to_win);
bool col_win(char** board, int rows, int cols, int pieces_to_win);
bool diagonal_win(char** board, int rows, int cols, int pieces_to_win);
bool right_diagonal_win(char** board, int rows, int cols, int pieces_to_win);
bool left_diagonal_win(char** board, int rows, int cols, int pieces_to_win);
void declare_winner(char** board, int turn, int rows, int cols, int pieces_to_win);

#endif // GANADOR_H
