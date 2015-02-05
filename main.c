/**********************************/
/*	Rock, Paper, Scissors	  */
/*      Made by: Kevin Modding    */
/**********************************/

#include <stdio.h> //Input/Output
#include <stdlib.h> //For rand, srand
#include <stdbool.h> //For booleans
#include <time.h> //For the seed



/*Global data related to rock, paper, scissors*/
typedef enum{
	ROCK = 0,
	PAPER,
	SCISSORS
}Moves_t;

typedef enum{
	VICTORY,
	DRAW,
	DEFEAT
}Result;


/*Returns a char array to output both moves*/
char* getMove(Moves_t move){
	char* out = "Invalid";

	switch (move){
	case ROCK:
		out = "Rock";
		break;
	case PAPER:
		out = "Paper";
		break;
	case SCISSORS:
		out = "Scissors";
		break;
	}

	return out;

}

/*Returns the result*/
Result getVictory(Moves_t my, Moves_t opp){

	int out = 0;

	switch (my){

	case ROCK:
		if (opp == PAPER){ out = DEFEAT; }
		else if (opp == ROCK){ out = DRAW; }
		else{ out = VICTORY; }
		break;

	case PAPER:
		if (opp == SCISSORS){ out = DEFEAT; }
		else if (opp == PAPER){ out = DRAW; }
		else{ out = VICTORY; }
		break;

	case SCISSORS:
		if (opp == ROCK){ out = DEFEAT; }
		else if (opp == SCISSORS){ out = DRAW; }
		else{ out = VICTORY; }
		break;

	}
	return out;

}



int main(int argc, char** argv){

	Moves_t myMove, oppMove; //Player's move, Opponent's move
	int myScore = 0, oppScore = 0; //Current score for both players
	char input = 0; //Input of the player
	bool isPlaying = true; //Bool to help the main game loop
	bool wrongInput = false; //Bool to restart the input if the user doesn't specify a valid move
	Result result = DRAW;


	char* menuText =
		"You: %i           Opp: %i\n" 
		"***************************\n"
		"*        (R)ock           *\n"
		"*        (P)aper          *\n"
		"*        (S)cissors       *\n"
		"***************************\n"
		"Enter a letter(R, P, S): "; //end of menuText


	srand(time(NULL));



	while (isPlaying){

		wrongInput = false; //reset our flag
		system("cls"); //clean the screen, WARNING: only for windows..

		/*Show the instructions*/
		printf(menuText, myScore, oppScore);

		/*Get the player's move*/
		input = fgetchar();

		switch (input){

		case 'R': case 'r':
			myMove = ROCK;
			break;

		case 'P': case 'p':
			myMove = PAPER;
			break;

		case 'S': case 's':
			myMove = SCISSORS;
			break;

		default:
			printf("\n\nYou have to choose either 'r', 'p' or 's'!\n\n");
			getchar();
			wrongInput = true; //set our flag to true
			break;
		}

		if (wrongInput){ continue; } //restart the input, invalid move was selected..
		else{

			/*Generate opponent's move*/
			oppMove = (Moves_t)rand() / (RAND_MAX / 3 + 1);

			printf("You: %s\nOpponent: %s\n\n", getMove(myMove), getMove(oppMove));
			result = getVictory(myMove, oppMove);


			/*Output the result and update the score*/
			switch (result){
			case VICTORY:
				printf("You Win!");
				myScore++;
				break;

			case DRAW:
				printf("DRAW !");
				break;

			case DEFEAT:
				printf("Opponent Wins!");
				oppScore++;
				break;
			}

			getchar(); getchar();



		}

	}




}
