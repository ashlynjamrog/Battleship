#include "header.h"

void welcome_screen()
{
	printf("Welcome to Battleship!\n");
	printf("\n");
	printf("Rules: \n");
	printf("This is a two player game, where you will play against Click (the computer).\n");
	printf("The object of Battleship is to try and sink all of Click's ships before \n");
	printf("he sinks all of yours. All of Click's ships are somewhere on his board.\n");
	printf("You try and hit them by calling out the coordinates of one of the squares on the board. \n");
	printf("Click also tries to hit your ships by calling out coordinates. \n");
	printf("Neither you nor Click can see eachothers ships so you must try to guess \n");
	printf("where they are. You will see 2 boards, yours and a blank board where you will record your guesses.\n");
	printf("\n");
	printf("Click: Hello there! Are you ready to lose at Battleship? Your ships are going down... literally!\n");
	
	/*int num = 0;

	for (int x = 0; x != '/0'; x++) {
		scanf("%c", &name[x]);
		num = x;
	}
	name[num] = '/0';*/
	//continue_game();
}


char get_ch_option()
{
	char option = '/0';

	scanf("%c", &option);
	printf("%c\n", option);
	return option;

}

	
int get_option(void)
{
	int option = 0;

	scanf("%d", &option);

	return option;
}

int get_rand_num()
{
	int option = 0; 
	option = rand() % 10;
	return option;
}
void initialize_game_board(char board[][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			board[x][y] = '-';
		}
	}

}

void manually_place_ships_on_board(char board[][10])
{
	int num_ships = 0, row = 0, col = 0;
	char direction = '/0';
	while (num_ships < 5)
	{
		if (num_ships == 0)
		{
			do {
				print_board(board);
				printf("Do you want to go vertical or horizontal for the carrier (has 5 cells)? ('v' or 'h')\n");
				direction = get_ch_option();
				system("cls");
			} while (direction != 'v' && direction != 'h');
			
			if (direction == 'v') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the carrier in?  (has 5 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the carrier in? (has 5 cells)\n");
					col = get_option();
					system("cls");
				} while ((row + 5) > 10);
				for (int row1 = row; row1 < (row + 5); row1++) {
					board[row1][col] = 'c';
				}
			} 
			if (direction == 'h') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the carrier in?  (has 5 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the carrier in? (has 5 cells)\n");
					col = get_option();
					system("cls");
				} while ((col + 5) > 10);
				for (int col1 = col; col1 < (col + 5); col1++) {
					board[row][col1] = 'c';
				}
			}
			}//end if (num_ships == 0)

		if (num_ships == 1) {
			do {
				print_board(board);
				printf("Do you want to go vertical or horizontal for the battleship (has 4 cells)? ('v' or 'h')\n");
				direction = get_ch_option();
				system("cls");
			} while (direction != 'v' && direction != 'h');

			if (direction == 'v') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the battleship in?  (has 4 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the battleship in? (has 4 cells)\n");
					col = get_option();
					system("cls");
				} while (((row + 4) > 10) || (board[row][col] != '-' || board[row+1][col] != '-' || board[row + 2][col] != '-' || board[row + 3][col] != '-'));
				for (int row1 = row; row1 < (row + 4); row1++) {
					board[row1][col] = 'b';
				}
			}
			if (direction == 'h') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the battleship in?  (has 4 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the battleship in? (has 4 cells)\n");
					col = get_option();
					system("cls");
				} while (((col + 4) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-' || board[row][col + 3] != '-'));
				for (int col1 = col; col1 < (col + 4); col1++) {
					board[row][col1] = 'b';
				}
			}


		} // end if(num_ships == 1)

		if (num_ships == 2) {
			do {
				print_board(board);
				printf("Do you want to go vertical or horizontal for the cruiser (has 3 cells)? ('v' or 'h')\n");
				direction = get_ch_option();
				system("cls");
			} while (direction != 'v' && direction != 'h');

			if (direction == 'v') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the cruiser in?  (has 3 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the cruiser in? (has 3 cells)\n");
					col = get_option();
					system("cls");
				} while (((row + 3) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-' || board[row + 2][col] != '-'));
				for (int row1 = row; row1 < (row + 3); row1++) {
					board[row1][col] = 'r';
				}
			}
			if (direction == 'h') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the cruiser in?  (has 3 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the cruiser in? (has 3 cells)\n");
					col = get_option();
					system("cls");
				} while (((col + 3) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-'));
				for (int col1 = col; col1 < (col + 3); col1++) {
					board[row][col1] = 'r';
				}
			}


		} // end if(num_ships == 2)

		if (num_ships == 3) {
			do {
				print_board(board);
				printf("Do you want to go vertical or horizontal for the submarine (has 3 cells)? ('v' or 'h')\n");
				direction = get_ch_option();
				system("cls");
			} while (direction != 'v' && direction != 'h');

			if (direction == 'v') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the submarine in?  (has 3 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the submarine in? (has 3 cells)\n");
					col = get_option();
					system("cls");
				} while (((row + 3) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-' || board[row + 2][col] != '-'));
				for (int row1 = row; row1 < (row + 3); row1++) {
					board[row1][col] = 's';
				}
			}
			if (direction == 'h') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the submarine in?  (has 3 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the submarine in? (has 3 cells)\n");
					col = get_option();
					system("cls");
				} while (((col + 3) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-'));
				for (int col1 = col; col1 < (col + 3); col1++) {
					board[row][col1] = 's';
				}
			}


		} // end if(num_ships == 3)

		if (num_ships == 4) {
			do {
				print_board(board);
				printf("Do you want to go vertical or horizontal for the destroyer (has 2 cells)? ('v' or 'h')\n");
				direction = get_ch_option();
				system("cls");
			} while (direction != 'v' && direction != 'h');

			if (direction == 'v') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the destroyer in?  (has 2 cells)\n");
					row = get_option();
					printf("What column do you want to place your first cell of the destroyer in? (has 2 cells)\n");
					col = get_option();
					system("cls");
				} while (((row + 2) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-'));
				for (int row1 = row; row1 < (row + 2); row1++) {
					board[row1][col] = 'd';
				}
			}
			if (direction == 'h') {
				do {
					print_board(board);
					printf("What row do you want to place your first cell of the destroyer in?  (has 2 cells)\n");
					row = get_option();
					printf("What Column do you want to place your first cell of the destroyer in? (has 2 cells)\n");
					col = get_option();
					system("cls");
				} while (((col + 2) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-'));
				for (int col1 = col; col1 < (col + 2); col1++) {
					board[row][col1] = 'd';
				}
			}


		} // end if(num_ships == 4)

		num_ships++;
	} // end of while loop
} // end of function

void randomly_place_ships_on_board(char board[][10]) {
	int num_ships = 0, row = 0, col = 0, val = 0;
	char direction = '/0';
	while (num_ships < 5)
	{
		if (num_ships == 0)
		{
			val = rand() % 2;
			if (val == 1)
				direction = 'v';
			else
				direction = 'h';

			if (direction == 'v') {
				do{ 
					row = get_rand_num();
					col = get_rand_num();
				} while ((row + 5) > 10);
				for (int row1 = row; row1 < (row + 5); row1++) {
					board[row1][col] = 'c';
				}
			}
			if (direction == 'h') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while ((col + 5) > 10);
				for (int col1 = col; col1 < (col + 5); col1++) {
					board[row][col1] = 'c';
				}
			}
		}//end if (num_ships == 0)

		if (num_ships == 1) {
				val = rand() % 2;
				if (val == 1)
					direction = 'v';
				else
					direction = 'h';

			if (direction == 'v') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((row + 4) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-' || board[row + 2][col] != '-' || board[row + 3][col] != '-'));
				for (int row1 = row; row1 < (row + 4); row1++) {
					board[row1][col] = 'b';
				}
			}
			if (direction == 'h') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((col + 4) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-' || board[row][col + 3] != '-'));
				for (int col1 = col; col1 < (col + 4); col1++) {
					board[row][col1] = 'b';
				}
			}


		} // end if(num_ships == 1)

		if (num_ships == 2) {
			val = rand() % 2;
			if (val == 1)
				direction = 'v';
			else
				direction = 'h';

			if (direction == 'v') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((row + 3) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-' || board[row + 2][col] != '-'));
				for (int row1 = row; row1 < (row + 3); row1++) {
					board[row1][col] = 'r';
				}
			}
			if (direction == 'h') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((col + 3) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-'));
				for (int col1 = col; col1 < (col + 3); col1++) {
					board[row][col1] = 'r';
				}
			}


		} // end if(num_ships == 2)

		if (num_ships == 3) {
			val = rand() % 2;
			if (val == 1)
				direction = 'v';
			else
				direction = 'h';

			if (direction == 'v') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((row + 3) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-' || board[row + 2][col] != '-'));
				for (int row1 = row; row1 < (row + 3); row1++) {
					board[row1][col] = 's';
				}
			}
			if (direction == 'h') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((col + 3) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-' || board[row][col + 2] != '-'));
				for (int col1 = col; col1 < (col + 3); col1++) {
					board[row][col1] = 's';
				}
			}


		} // end if(num_ships == 3)

		if (num_ships == 4) {
			val = rand() % 2;
			if (val == 1)
				direction = 'v';
			else
				direction = 'h';

			if (direction == 'v') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((row + 2) > 10) || (board[row][col] != '-' || board[row + 1][col] != '-'));
				for (int row1 = row; row1 < (row + 2); row1++) {
					board[row1][col] = 'd';
				}
			}
			if (direction == 'h') {
				do {
					row = get_rand_num();
					col = get_rand_num();
				} while (((col + 2) > 10) || (board[row][col] != '-' || board[row][col + 1] != '-'));
				for (int col1 = col; col1 < (col + 2); col1++) {
					board[row][col1] = 'd';
				}
			}


		} // end if(num_ships == 4)

		num_ships++;
	} // end of while loop 
	
}


void print_board(char board[][10]) {
	printf(" \t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\n\n");
	
	for (int row = 0; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			if(col == 0)
			{
				printf("%d\t", row);
			}
			printf("%c\t", board[row][col]);
		}
		printf("\n\n");
	}
}

int is_hit_or_miss(char board[][10], int guess_row, int guess_col)
{
	if (board[guess_row][guess_col] == '-')
		return 0;
	else
		return 1;
}
// hit = 0 when its a miss
//hit = 1 when its a hit
void set_hit_or_miss(char board[][10], int row, int col, int hit)
{
	if (hit == 0)
		board[row][col] = 'm';
	else if (hit == 1)
		board[row][col] = '*';

}

void player1_turn(char player2_board[][10], char player1_guess[][10], char name[][100], FILE *outfile, int *pHit1, int *pMiss1)
{
	int guess_row = 0, guess_col = 0, hit_miss = 0;
	char option = '/0';
	do {
		printf("Click's board: \n");
		print_board(player1_guess);
		printf("%s, what is the row of the target you would like to attack? \t", name);
		guess_row = get_option();
		printf("What is the column of the target you would like to attack? \t");
		guess_col = get_option();
		system("cls");
	} while (player1_guess[guess_row][guess_col] != '-' || guess_row > 9 || guess_row < 0 || guess_col > 9 || guess_col < 0);

	player1_guess[guess_row][guess_col] = 'g';
	hit_miss = is_hit_or_miss(player2_board, guess_row, guess_col);
	set_hit_or_miss(player1_guess, guess_row, guess_col, hit_miss);
	set_hit_or_miss(player2_board, guess_row, guess_col, hit_miss);
	
	//printf("\nhit_miss: %d\n", hit_miss);
	if (hit_miss == 1)
		pHit1++;
	else
		pMiss1++;

	system("cls");
	//print_board(player2_board);
	printf("Click's board: \n");
	print_board(player1_guess);

	//if (hit_miss == 1)
	//{
	//	char string[5] = { 'H','i', 't','!' };
	//}
	//else if (hit_miss == 0)
	//{
	//	char string[5] = { 'M','i', 's','s' };
	//}
	

	//fprintf(outfile, "%s- %d,%d - %s", name, guess_row, guess_col, string);
	//continue_game();



}
// = 1 if game over and player 1 wins
// = 2 if game over and player 2 wins
// = 0 if game is still going
int game_over(char player1[][10], char player2[][10])
{
	int count1 = 0, count2 = 0;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			//print_board(player1);
			if (player1[x][y] == 'r' || player1[x][y] == 's' || player1[x][y] == 'd' || player1[x][y] == 'c' || player1[x][y] == 'b')
				count1++;
			if (player2[x][y] == 'r' || player2[x][y] == 's' || player2[x][y] == 'd' || player2[x][y] == 'c' || player2[x][y] == 'b')
				count2++;

		}
	}
	//printf("%d\n", count1);
	//printf("%d\n", count2);
	if (count1 > 0 && count2 > 0)
		return 0;
	else if (count1 > count2)
		return 1;
	else
		return 2;
}

void player2_turn(char player1_board[][10], char player2_guess[][10], char name[][100], FILE *outfile, int *pHit2, int *pMiss2) {
	int guess_row = 0, guess_col = 0, hit_miss = 0;
	char option = '/0', string[4] = { '\0' };
	do {
		guess_row = rand() % 10;
		guess_col = rand() % 10;

	} while (player2_guess[guess_row][guess_col] != '-');

	player2_guess[guess_row][guess_col] = 'g';
	hit_miss = is_hit_or_miss(player1_board, guess_row, guess_col);
	set_hit_or_miss(player2_guess, guess_row, guess_col, hit_miss);
	set_hit_or_miss(player1_board, guess_row, guess_col, hit_miss);
	printf("%s's Board after Click attacked!\n", name);
	print_board(player1_board);
	if (hit_miss == 1)
		*pHit2++;
	else
		*pMiss2++;

	//continue_game();

	/*if (hit_miss == 1)
	{
		string[0] = 'H';
		string[1] = 'i';
		string[2] = 't';
		string[3] = '!';
		string[4] = '\0';
	}
	else if (hit_miss == 0)
	{
		string[0] = 'M';
		string[1] = 'i';
		string[2] = 's';
		string[3] = 's';
		string[4] = '\0';
	}*/
	
	

	//fprintf(outfile, "Click - %d,%d - %s", guess_row, guess_col, string);

}

void continue_game() {
	int variable = 0;
	do {
		
		printf("Press 1 to continue\n");
		variable = get_option();
		system("cls");

	} while (variable != 1);
}
void stat (FILE *outfile, int winner, int hits1, int misses1, int hits2, int misses2) {
	fprintf("Player 1 misses: %d\n", misses1);
	fprintf("Player 1 hits: %d\n", hits1);
	fprintf("Player 2 misses: %d\n", misses2);
	fprintf("Player 2 hits: %d\n", hits2);
}
