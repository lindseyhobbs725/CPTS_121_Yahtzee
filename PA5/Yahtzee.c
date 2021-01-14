/*
* Programmer: Lindsey Hobbs
* Class: CPTS 121; Lab Sectin 8
* Programming Assignment: PA5
*
* Description: Based on the given assignment, the program will allow
*				a two player interactive game of Yahtzee. Points are
				obtained by rolling five 6-sided die across thirteen rounds.
				During each round, each player may roll the dice up to three
				times to make one of the possible scoring combinations. Once
				a combination has been achieved by the player, it may not be
				used again in future rounds, except for the Yahtzee combination
				may be used as many times as the player makes the combination.
				Each scoring combination has different point totals. Some of
				these totals are achieved through the accumulation of points
				across rolls and some are obtained as fixed sequences of values.
*/

#include "Yahtzee.h"

int game_menu(void)
// prints 3 game menu options, and obtains user input on how to proceed
{
	int option = 0;
	printf("YAHTZEE Game Menu:\n1. Print game rules.\n2. Start a game of Yahtzee.\n3. Exit.\n");
	printf("Enter your option:");
	scanf("%d", &option);
	if(option == 1 || option == 2 || option == 3)
	{
		return option;
	}
	else if (option > 3)
	{
		printf("\nInvalid Option...\n");
		do
		{
			printf("\nYAHTZEE Game Menu:\n1. Print game rules.\n2. Start a game of Yahtzee.\n3. Exit.\n");
			printf("Enter your option:");
			scanf("%d", &option);
			
		} while (option > 3);
	}

	return option;
}

void print_scorecard(void)
//prints the scorecard for YAHTZEE
{
	printf("SCORECARD:\n");
	printf("	NAME		COMBINATION			SCORE	\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("1.	Ones						Sum of all 1 valued dice\n");
	printf("2.	Twos						Sum of all 2 valued dice\n");
	printf("3.	Threes						Sum of all 3 valued dice\n");
	printf("4.	Fours						Sum of all 4 valued dice\n");
	printf("5.	Fives						Sum of all 5 valued dice\n");
	printf("6.	Sixes						Sum of all 6 valued dice\n");
	printf("----------------------------------------------------------------------------------\n");
	printf("7.	3 of a kind	3 dice w/ same face		Sum of all face values\n");
	printf("8.	4 of a kind	4 dice w/ same face		Sum of all face values\n");
	printf("9.	Full House	One pair & 3 of a kind		25\n");
	printf("10.	Small Straight	Sequence of 4 dice		30\n");
	printf("11.	Large Straight	Sequence of 5 dice		40\n");
	printf("12.	YAHTZEE		5 dice of the same face		50  **can be achieved multiple times\n");
	printf("13.	Chance		Any sequence of dice		Sum of all face values\n\n");


}
void print_game_rules(char *player1, char *player2)
// prints rules for game of YAHTZEE 
{
	printf("Hello, and welcome to YAHTZEE!!! The game of fun, chance, and a smidgen of chance!\n");
	printf("Here's how the game goes: There are two players (there's two of you right?), each playing to get the most points.\n");
	printf("Over thirteen rounds, each player may roll up to three times per round to get any of the possible scoring combinations\n");
	printf("Each scoring combination can only be used once except for YAHTZEE (that can be used as many times as the player rolls five of the same face).\n");
	printf("See the scoring combinations and points below.\n");
	printf("Lucky for you, we will keep your scorecard updated with your input, of course.\n");
	printf("If at the end of the game the score in the upper section is greater than or equal to 63, you get 35 points added on to your final score.\n\n");

	print_scorecard();
	
	
	printf("\n");
}


void exit_game(void)
//prints goodbye message and closes program
{
	printf("\nThat's alright, come play when you are ready!\n\n");
	system("pause");
	system("cls");
}

void start_game(void)
//prints scorecard and are you ready message
{
	print_scorecard();
	system("pause");

}

void player1_turn(void)
//prints message to indicate player 1's turn
{
	printf("\nPlayer 1, your turn! ");
	system("pause");
	printf("\n");
}

void player2_turn(void)
//prints message to indicate player 2's turn
{
	printf("\nPlayer 2, your turn! ");
	system("pause");
	printf("\n");
}

int roll_dice(void)
// rolls one die. this function should randomly generate a value between 1-6
// returns the value of the die
{
	int die = 0;
	die = rand() % 6 + 1;
	return die;
}

int sum_dice(int die1, int die2, int die3, int die4, int die5)
//finds the sum of the five dice
{
	int sum = die1 + die2 + die3 + die4 + die5;
	return sum;
}

int roll_five_die(int* die1, int* die2, int* die3, int* die4, int* die5)
// rolls five die using the roll_dice function
{
	
	*die1 = roll_dice();
	*die2 = roll_dice();
	*die3 = roll_dice();
	*die4 = roll_dice();
	*die5 = roll_dice();
	print_dice(*die1, *die2, *die3, *die4, *die5);
}

void print_dice(int die1, int die2, int die3, int die4, int die5)
//prints the dice rolled and the sum of all the dice
{
	int sum = 0;
	sum = sum_dice(die1, die2, die3, die4, die5);
	printf("\nHere's your roll: %d %d %d %d %d  Total: %d\n\n", die1, die2, die3, die4, die5, sum);
}

int potential_reroll(void)
// asks if want to reroll
{
	int reroll = 0;
	do
	{
		printf("Do you want to reroll? (1 for Yes, 2 for No): ");
		scanf("%d", &reroll);
		if (reroll > 2 || reroll < 1)
		{
			printf("Invalid Option, try again.\n");
		}
	} while (reroll > 2 || reroll < 1);
	
	return reroll;
}

int reroll_option(int *die1, int *die2, int *die3, int *die4, int *die5)
// counts the number of rolls per round. Limit 3. 
//rerolls if the player indicates they want to reroll. Rerolls the number of dice not selected
{
	int keep = -1, sum = 0;

	do
	{
		printf("How many dice do you want to keep? (0-4): ");
		scanf("%d", &keep);
		if (keep == 0)
		{
			roll_five_die(die1, die2, die3, die4, die5);
			sum = sum_dice(*die1, *die2, *die3, *die4, *die5);
		}
		else if (keep == 1)
		{
			printf("Which dice would you like to keep?(separate with space): ");
			scanf("%d", die1);
			printf("Reroll your 4 dice. ");
			system("pause");
			*die2 = roll_dice();
			*die3 = roll_dice();
			*die4 = roll_dice();
			*die5 = roll_dice();
			print_dice(die1, *die2, *die3, *die4, *die5);
		}
		else if (keep == 2)
		{
			printf("Which dice would you like to keep?(separate with space): ");
			scanf("%d%d", die1, die2);
			printf("Reroll your 3 dice. ");
			system("pause");
			*die3 = roll_dice();
			*die4 = roll_dice();
			*die5 = roll_dice();
			print_dice(*die1, *die2, *die3, *die4, *die5);
		}
		else if (keep == 3)
		{
			printf("Which dice would you like to keep?(separate with space): ");
			scanf("%d%d%d", die1, die2, die3);
			printf("Reroll your 2 dice. ");
			system("pause");
			*die4 = roll_dice();
			*die5 = roll_dice();
			print_dice(*die1, *die2, *die3, *die4, *die5);
		}
		else if (keep == 4)
		{
			printf("Which dice would you like to keep?(separate with space): ");
			scanf("%d%d%d%d", die1, die2, die3, die4);
			printf("Reroll your 1 dice. ");
			system("pause");
			*die5 = roll_dice();
			print_dice(*die1, *die2, *die3, *die4, *die5);
		}
		else
		{
			printf("Invalid Option, try again.\n");
		}
	} while (keep > 4);
}

int score_option(void)
// asks the player what option to choose and records options chosen
{
	int option = 0, index = 0;
	do
	{
		printf("Which option do you want to choose? (1-13): ");
		scanf("%d", &option);
		if (option > 13)
		{
			printf("Invalid Option, try again.\n");
		}
	} while (option > 13);
	
	//*option_chosen[index] = option;
	//++index;
	return option;
}


void keep_score(int die1, int die2, int die3, int die4, int die5, int* tot_score, int* top_sec_score, int* bottom_sec_score)
// allows player to score for that round
{
	int option = 0, total_score = 0, sum = 0;
	sum = sum_dice(die1, die2, die3, die4, die5);
	option = score_option();

	if (option == 1)
	{
		if (die1 == 1)
		{
			total_score = die1;
		}
		if (die2 == 1)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 1)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 1)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 1)
		{
			total_score = die5 + total_score;
		}
		printf("You chose ONES.  ");
	}
	else if (option == 2)
	{
		if (die1 == 2)
		{
			total_score = die1;
		}
		if (die2 == 2)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 2)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 2)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 2)
		{
			total_score = die5 + total_score;
		}
		printf("You chose TWOS.  ");
	}
	else if (option == 3)
	{
		if (die1 == 3)
		{
			total_score = die1;
		}
		if (die2 == 3)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 3)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 3)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 3)
		{
			total_score = die5 + total_score;
		}
		printf("You chose THREES.  ");
	}
	else if (option == 4)
	{
		if (die1 == 4)
		{
			total_score = die1;
		}
		if (die2 == 4)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 4)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 4)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 4)
		{
			total_score = die5 + total_score;
		}
		printf("You chose FOURS.  ");
	}
	else if (option == 5)
	{
		if (die1 == 5)
		{
			total_score = die1;
		}
		if (die2 == 5)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 5)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 5)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 5)
		{
			total_score = die5 + total_score;
		}
		printf("You chose FIVES.  ");
	}
	else if (option == 6)
	{
		if (die1 == 6)
		{
			total_score = die1;
		}
		if (die2 == 6)
		{
			total_score = die2 + total_score;
		}
		if (die3 == 6)
		{
			total_score = die3 + total_score;
		}
		if (die4 == 6)
		{
			total_score = die4 + total_score;
		}
		if (die5 == 6)
		{
			total_score = die5 + total_score;
		}
		printf("You chose SIXES.  ");
	}
	else if (option == 7)
	{
		if (die1 = die2)
		{
			if (die1 = die3)
			{
				total_score = sum;
			}
			else if (die1 = die4)
			{
				total_score = sum;
			}
			else if (die1 = die5)
			{
				total_score = sum;
			}

		}
		else if (die1 = die3)
		{
			if (die1 = die4)
			{
				total_score = sum;
			}
			else if (die1 = die5)
			{
				total_score = sum;
			}
		}
		else if (die1 = die4)
		{
			if (die1 = die5)
			{
				total_score = sum;
			}
		}
		else if (die2 = die3)
		{
			if (die2 = die4)
			{
				total_score = sum;
			}
			else if (die2 = die5)
			{
				total_score = sum;
			}
		}
		else if (die3 = die4)
		{
			if (die3 = die5)
			{
				total_score = sum;
			}
		}
		else
		{
			total_score = 0;
		}
		printf("You chose 3 OF A KIND.  ");			
	}
	else if (option == 8)
	{	
		if (die1 = die2)
		{
			if (die1 = die3)
			{
				if (die1 = die4)
				{
					total_score = sum;
				}
				else if (die1 = die5)
				{
					total_score = sum;
				}
			}
			else if (die1 = die4)
			{
				total_score = sum;
			}
		}
		else if (die3 = die4)
		{
			total_score = sum;
		}
		else
		{
			total_score = 0;
		}
		printf("You chose 4 OF A KIND.  ");
	}
	else if (option == 9)
	{	
		if (sum > 7 && sum < 24 && sum != 10 && sum != 15 && sum != 20)
		{
			total_score = 25;
		}
		else
		{
			total_score = 0;
		}
		printf("You chose FULL HOUSE.  ");
	}
	else if (option == 10)
	{
		int remain = 0;
		remain = sum % 100;
		if (remain == 1 || remain == 14 || remain == 18)
		{
			total_score = 30;
		}
		else
		{
			total_score = 0;
		}	
		printf("You chose SMALL STRAIGHT.  ");
	}
	else if (option == 11)
	{
		if (sum == 15 || sum == 20)
		{
			total_score = 40;
		}
		else
		{
			total_score = 0;
		}
		printf("You chose LARGE STRAIGHT.  ");
	}
	else if (option == 12)
	{
		if(sum == 5||sum == 10||sum == 15||sum == 20||sum == 25||sum == 30)
		{
			total_score = 50;
		}
		else
		{
			total_score = 0;
		}
		printf("You chose YAHTZEE!!  ");
	}
	else if (option == 13)
	{
	sum = total_score;
	printf("You chose CHANCE.  ");
	}


	//total_score = total_score + tot_score;
	if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
	{
		*top_sec_score = total_score + *top_sec_score;
	}
	else
	{
		*bottom_sec_score = total_score + *bottom_sec_score;
	}

	*tot_score = *top_sec_score + *bottom_sec_score;
	
	printf("Your score: %d\n", *tot_score);
	return total_score;
}

void add_35points(int* tot_score, int top_sec_score, int bottom_sec_score)
// sees whether a player gets and addition 35 points added to their final score
{
	if (top_sec_score >= 63)
	{
		*tot_score = top_sec_score + bottom_sec_score + 35;
	}
	else
	{
		*tot_score = top_sec_score + bottom_sec_score;
	}
}

void announce_winner(int p1_score, int p2_score)
// announces the winner of the game
{
	if (p1_score > p2_score)
	{
		printf("PLAYER 1 is the WINNER!!!!\n");
	}
	else if (p1_score < p2_score)
	{
		printf("PLAYER 2 is the WINNER!!!!\n");
	}
}

int replay_game(void)
// prompts the players to see if they want to play again
{
	int replay = 0;
	printf("That was AWESOME!!! Do you both want to play again? (1 to play again, 2 to close game): \n");
	scanf("%d", &replay);
	if (replay == 1)
	{
		printf("\nYES! Let's do this!!! ");
	}
	else
	{
		printf("Alright have a lovely day!");
		system("pause");
		replay = 0;
		
	}
			
	
	return replay;
}