#include "Ganador.h"

bool game_won(char** board, int rows, int cols, int pieces_to_win)
{
    return row_win(board, rows, cols, pieces_to_win) || col_win(board, rows, cols, pieces_to_win) || diagonal_win(board, rows, cols, pieces_to_win);
}

bool game_tie(char** board, int rows, int cols, int pieces_to_win)
{
    int i, k;
    char blank_space = "*";

    for(i = 0; i < rows; ++i)
    {
        for(k = 0; k < cols; ++k)
        {
            if(board[i][k] == blank_space)
                return false;
        }
    }

    return !game_won(board, rows, cols, pieces_to_win);
}

bool diagonal_win(char** board, int rows, int cols, int pieces_to_win)
{
    return right_diagonal_win(board, rows, cols, pieces_to_win) || left_diagonal_win(board, rows, cols ,pieces_to_win);
}

