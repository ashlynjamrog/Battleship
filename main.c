#include "header.h"

int main(void)
{
	int playagain = 0;
	FILE *outfile = NULL;
	outfile = fopen("battleshipLog.txt", "w");
	srand((unsigned int)time(NULL));
	welcome_screen();
	while (playagain == 0) {
		// player1_a == player1's game board
		//player1_b == player1's guesses
		// player2_a == player2's game board
		// player2_b == players2's guesses
		char player1_a[10][10] = { '/0' }, player1_b[10][10] = { '/0' }, player2_a[10][10] = { '/0' }, player2_b[10][10] = { '/0' };
		int game = 0, who_goes_first = 0, player1, player2, val = 0, hit1 = 0, hit2 = 0, miss1 = 0, miss2 = 0;
		char option = '/0';
		initialize_game_board(player1_a);
		initialize_game_board(player2_a);
		initialize_game_board(player1_b);
		initialize_game_board(player2_b);

		

		printf("\n");
		who_goes_first = rand() % 2;


		continue_game();
		printf("\nWhat is your name?\n");
		char name[100];
		fgets(name, 100, stdin);
		//strcpy(dtm, "Saturday March 25 1989");
		scanf("%[^\n]%*c", name);
		//printf("%s\n", name);
		system("cls");
		if (who_goes_first == 0)
		{
			printf("%s goes first!\n", name);
			player1 = 0;
			player2 = 1;
		}
		else
		{
			printf("Click goes first!\n");
			player1 = 1;
			player2 = 0;
		}
		printf("\n");


		/*for (int x = 0; x != '/0'; x++)
		{
			printf("%c", name[x]);

		}*/
		//printf("%s", name);
		//continue_game();
		do {
			printf("%s, Would you like to (1)manually place your ships on the game board, or (2)have your ships randomly placed?\n", name);
			val = get_option();
		} while (val < 1 || val > 2);
		if (val == 1)
			manually_place_ships_on_board(player1_a);
		else
			randomly_place_ships_on_board(player1_a);

		randomly_place_ships_on_board(player2_a);
		//continue_game();
		system("cls");
		while (game == 0) {
			if (player2 == 0) {
				printf("Player 2's turn!\n");
				player2_turn(player1_a, player2_b, name, outfile, hit2, miss2);
				//fprintf(outfile, "%d", game);
				/*do {
					printf("Ready to go on?\n");
					printf("Press 'Y' for player 2's turn!\n");
					option = get_ch_option();
					printf("%c", option);

				} while (option != 'Y' && option != 'y');*/
				//fprintf(outfile, 5);
				continue_game();
				//system("cls");
				player1 = 0;
				player2 = 1;
			}
			else {
				printf("%s's turn\n", name);
				//print_board(player2_a);
				player1_turn(player2_a, player1_b, name, outfile, hit1,miss1);
				//system("cls");
				player1 = 1;
				player2 = 0;
			}
			//printf("Miss 1 : %d", miss1);
			//printf("Miss 2 : %d", miss2);
			//stat(outfile, game, hit1, miss1, hit2, miss2);
			game = game_over(player1_a, player2_a);


		}// end while loop


		system("cls");

		if (game == 1)
		{
			printf("%s defeated all Player 2's ships! Goodjob!\n\n", name);
		}
		else
			printf("Player 2 defeated all your ships!\n\n");

		int point = 0;
		do {
			printf("Would you like to play again? Press 1 to play again and 2 to exit.\n");
			point = get_option();
		} while (point > 2 || point < 1);

		if (point == 2)
			playagain = 1;

		
	}
	fclose(outfile);
	

	return 0;
}