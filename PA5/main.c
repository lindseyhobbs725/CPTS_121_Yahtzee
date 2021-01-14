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

int main(void)
{
	int print_game_menu = 0, first_roll = 0, replay = 0, 
		die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, reroll = 0,
		p1_score = 0, p1_top_sec = 0, p1_bottom_sec = 0, 
		p2_score = 0, p2_top_sec = 0, p2_bottom_sec = 0; 
	do
	{
		print_game_menu = game_menu();
		if (print_game_menu == 1)
		{
			print_game_rules();
		}
		else if (print_game_menu == 3)
		{
			exit_game();
		}
		else
		{
			start_game();
		}

		srand((unsigned int)time(NULL));
		for (int rounds = 0; rounds < 14; ++rounds)
		{
			player1_turn();
			first_roll = roll_five_die(&die1, &die2, &die3, &die4, &die5);
			reroll = potential_reroll();
			for(int rolls = 1; reroll == 1 && rolls < 3; ++rolls)
			{
					reroll_option(&die1, &die2, &die3, &die4, &die5);
					reroll = potential_reroll();
			} 
			keep_score(die1, die2, die3, die4, die5, &p1_score, &p1_top_sec, &p1_bottom_sec);
			player2_turn();
			first_roll = roll_five_die(&die1, &die2, &die3, &die4, &die5);
			reroll = potential_reroll();
			for (int rolls = 1; reroll == 1 && rolls < 3; ++rolls)
			{
				reroll_option(&die1, &die2, &die3, &die4, &die5);
				reroll = potential_reroll();
			}
			keep_score(die1, die2, die3, die4, die5, &p2_score, &p2_top_sec, &p2_bottom_sec);
		}

		add_35points(&p1_score, p1_top_sec, p1_bottom_sec);
		add_35points(&p2_score, p2_top_sec, p2_bottom_sec);
		printf("Player 1, your total score is %d \n", p1_score);
		printf("Player 2, your total score is %d \n", p2_score);
		announce_winner(p1_score, p2_score);

		replay = replay_game();
	} while (replay == 1);
	
	system("cls");
	return 0;
}