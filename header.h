/* 
Battleship! PA 6
Ashlyn Jamrog
11/06/17

was not able to compute the stats
*/#pragma once


#ifndef header_H
#define header_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void continue_game();


void welcome_screen();
char get_ch_option();
int get_option(void);
void initialize_game_board(char board[][10]);
void manually_place_ships_on_board(char board[][10]);
void print_board(char board[][10]);
void randomly_place_ships_on_board(char board[][10]);
int get_rand_num();
int is_hit_or_miss(char board[][10], int guess_row, int guess_col);
int game_over(char player1[][10], char player2[][10]);
void player1_turn(char player2_board[][10], char player1_guess[][10], char name[][100], FILE *outfile, int *pHit1, int *pMiss1);
void set_hit_or_miss(char board[][10], int row, int col, int hit);
void player2_turn(char player1_board[][10], char player2_guess[][10], char name[][100], FILE *outfile, int *pHit2, int *pMiss2);
void stat(FILE *outfile, int winner, int hits1, int misses1, int hits2, int misses2);
#endif