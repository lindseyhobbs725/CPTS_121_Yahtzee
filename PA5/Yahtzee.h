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




#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

int game_menu(void);
// prints 3 game menu options, and obtains user input on how to proceed

void print_scorecard(void);
//prints the scorecard for YAHTZEE

void print_game_rules(void);
// prints rules for game of YAHTZEE 

void exit_game(void);
//prints goodbye message and closes program

void start_game(void);
//prints scorecard and are you ready message

void player1_turn(void);
//prints message to indicate player 1's turn

void player2_turn(void);
//prints message to indicate player 2's turn

int roll_dice(void);
// rolls one die. this function should randomly generate a value between 1-6
// returns the value of the die

void print_dice(int die1, int die2, int die3, int die4, int die5);
//prints the dice rolled and the sum of all the dice

int roll_five_die(int *die1, int *die2, int *die3, int *die4, int *die5);
// rolls five die using the roll_dice function

int sum_dice(int die1, int die2, int die3, int die4, int die5);
//finds the sum of the five dice

int potential_reroll(void);
// asks if want to reroll

int reroll_option(int* die1, int* die2, int* die3, int* die4, int* die5);
// counts the number of rolls per round. Limit 3

int score_option(void);
// asks the player what option to choose and records options chosen

void keep_score(int die1, int die2, int die3, int die4, int die5, int* tot_score, int *top_sec_score, int *bottom_sec_score);
// allows player to score for that round

void add_35points(int* tot_score, int top_sec_score, int bottom_sec_score);
// sees whether a player gets and addition 35 points added to their final score

void announce_winner(int p1_score, int p2_score);
// announces the winner of the game

int replay_game(void);
// prompts the players to see if they want to play again

#endif //
