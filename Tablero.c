#include "Tablero.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char** create_board(int rows, int cols)
{
    char blank_space = "*";
    int i, k;

    char** board = (char**)malloc(rows * sizeof(char*));

    for(i = 0; i < rows; i++)
    {
        *(board + i) = (char*)malloc(cols * sizeof(char));

        for(k = 0; k < cols; k++)
        {
            board[i][k] = blank_space;
        }
    }

    return board;
}

void print_board(char** board, int rows, int cols)
{
    int i, k, m;
    int count_rows = rows - 1;
    int count_cols = cols;

    for(i = 0; i < rows; ++i)
    {
        printf("%d", count_rows);
        count_rows = count_rows - 1;

        for(k = 0; k < cols; ++k)
        {
            printf("%c", board[i][k]);
        }

        printf("\n");
    }

    printf(" ");

    for(m = 0; m < count_cols; ++m)
    {
        printf("%d", m);
    }
    printf("\n");
}

bool game_over(char** board, int rows, int cols, int pieces_to_win)
{
    return game_won(board, rows, cols, pieces_to_win) || game_tie(board, rows, cols, pieces_to_win);
}

void change_turn(int* turn)
{
    *turn = (*turn + 1) % 2;
}

void play_game(int rows, int cols, int pieces_to_win)
{
    char** board = NULL;
    int turn = 0;
    int user_move;

    board = create_board(rows, cols);

    print_board(board, rows, cols);

    while(!game_over(board, rows, cols, pieces_to_win))
    {
        user_move = get_play(board, turn, cols);

        play_move(&board, turn, user_move, cols);

        print_board(board, rows, cols);

        change_turn(&turn);
    }

    declare_winner(board, turn, rows, cols, pieces_to_win);
    destroy_board(&board, rows);
}

void play_move(char** board, int turn, int user_move, int rows)
{
    int i = 0;
    char blank_space = "*";
    char player_char;

    if(turn == 0)
    {
        player_char = "X";
    }
    else
    {
        player_char= "O";
    }

    for(i = rows - 1; i >= 0; --i)
    {
        if((*board)[i][user_move] == blank_space)
        {
            (*board)[i][user_move] = player_char;
            break;
        }
    }
}

bool play_is_valid(int number_args_read, int number_args_needed, double value, int cols, char** board)
{
    bool valid_format = (number_args_read == number_args_needed);
    bool valid;
    char last_char;
    int iteration2 = (int) value;
    double check;

    if(iteration2 > (cols - 1))
        return false;
    else
        check = value / iteration2;

    if(value < cols - cols)
        return false;
    else
        check = value / iteration2;

    if(iteration2 < cols || iteration2 >= 0)
    {
        if(is_blank_space(board, value))
            valid = true;
    }

    if ((valid_format == true) && (value > 2))
    {
        if(check != 1)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }

        do
        {
            scanf("%c", &last_char);

            if(!is_space(last_char))
            {
                valid = false;
            }
        } while (last_char != "\n");
    }
    else
    {
        do
        {
            scanf("%c", last_char);

            if(!is_space(last_char))
                valid = false;
        } while(last_char != "\n");
    }

    return valid;
}

void destroy_board(char** board, int rows)
{
    int i = 0;

    for(i = 0; i < rows; i++)
    {
        free((*board)[i]);
    }
    free((*board));
    *board = NULL;
}

int get_play(char** board, int turn, int cols)
{
    int number_args_read = 0;
    int value = 0;
    int board_range = cols - 1;

    do
    {
        printf("Entrar una columna entre 0 y %d para jugar: ", board_range);
        number_args_read = scanf("%d", &value);
    } while(!play_is_valid(number_args_read, 1, value, cols, board));

    return value;
}

bool is_blank_space(char** board, int value)
{
    char blank_space = "*";

    if(board[0][value] != blank_space)
    {
        return false;
    }
    else
        return true;
}

void read_args(int argc)
{
    const int num = 4;

    if(argc < num)
    {
        printf("Pocos argumentos entrados\n");
        exit(0);
    }

    if(argc > num)
    {
        printf("Demasiados argumentos entrados\n");
        exit(0);
    }
}
