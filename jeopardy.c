/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 3

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

int winner();

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);

int winner(player *players)
{
int max = 0;
int best = 0;
int i = 1;
for (i = 1; i <=NUM_PLAYERS; i++)
{
if (&players[i].score > max)
{
max = &players[i].score;
best = i;
}

}

return best;
}

int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS+1];
    
int qsleft = NUM_QUESTIONS; //track number of questions left
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    printf("Welcome to a cheap rendition of jeprody *sigh*.\n");


    // Prompt for players names & initialize each of the players in the array
    for(int i=1; i<=NUM_PLAYERS; i++)
    {
        printf("Yo, Player %d, enter a name (and try not to embarrass yourself)\n", i);
        fgets(players[i].name, BUFFER_LEN, stdin);
        if (players[i].name[strlen(players[i].name)-1] == '\n') {
            players[i].name[strlen(players[i].name)-1] = '\0';
        }
        while (player_exists(players, i, players[i].name))
        {
            printf("Name exists (but I'm pretty sure you knew that). Please be at least sligthly more original.\n");
            fgets(players[i].name, BUFFER_LEN, stdin);
            if (players[i].name[strlen(players[i].name)-1] == '\n') {
            players[i].name[strlen(players[i].name)-1] = '\0';
        }
        }
	players[i].score = 0;
    }
system("clear");

  //  for(int i=1; i<=NUM_PLAYERS; i++){  printf("%s\n", players[i].name); }


//display categories and value amounts
  
  
  //Accept input to choose category
char cat[BUFFER_LEN] = { 0 };
char much[BUFFER_LEN] = { 0 };
char *token;
int playah = 1;

while (1)
{
printf("A'right, %s. \n", players[playah].name);
display_categories();
fgets(buffer, BUFFER_LEN, stdin);
buffer[strlen(buffer)-1] = '\0';
if (strcmp(buffer, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }
token = strtok(buffer, " ");
strcpy(cat, token);
token = strtok(NULL, " ");
strcpy(much, token);

  for(int j = 0; j < 3; j++){
      if ( (strcmp(cat, categories[j]) == 0) ){ 
      //if category exists, set buffer to *category for display_question
        printf("I hope you know a lot about %s. We've got %s on the line.\n", categories[j], much); 
	display_question(&categories[j], atoi(much));
	fgets(buffer, BUFFER_LEN, stdin);
	buffer[strlen(buffer)-1] = '\0';
	if (valid_answer(&categories[j], atoi(much), buffer))
	{
		if (atoi(much) == 100)
			printf("Pfft, too easy.\n");
		else if (atoi(much) == 200)
				printf("That wasn't that hard.\n");
		else if (atoi(much) == 300)
				printf("Fine, you win this one.\n");
		else if (atoi(much) == 400)
				printf("I'm impressed you got that. But that wasn't a compliment.\n");
		else printf("Wut\n");
		
		update_score(players, playah, much); //not working
	}
	else
	{
		if (atoi(much) == 100)
			printf("Couldn't even get that?\n");
		else if (atoi(much) == 200)
				printf("Nope.\n");
		else if (atoi(much) == 300)
				printf("Try again. Not.\n");
		else if (atoi(much) == 400)
				printf("Try something more in your league.\n");
		else printf("Wut\n");
	}
if (qsleft)
{
qsleft--;
printf("Qs left: %d\n", qsleft); 
	if (playah == NUM_PLAYERS)
	{
	printf("Let's show them the leaderboard: (imagine a leaderboard)\nNew round, let's get this over with.");
	getchar();
	playah = 1;
	}

	else
	{	
	printf("So we have %s with %d points, kapiche?\n", players[playah].name, players[playah].score);
	printf("Let's go to the next player");
playah += 1;
getchar();//pause
	}
	system("clear");//clear screen
	
        break;
}
else
{

printf("Game over, the winner is %s with %d points\n", players[winner(players)].name, players[winner(players)].score);
return EXIT_SUCCESS;
}
        //prompt dollar amount question
      }
    //  else
     // printf("%s uh oh, not found\n", categories[j]); //We shouldnt print the missed cats

  }

}

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {

        if (buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        
        if (strcmp(buffer, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }


        // Call functions from the questions and players source files
      
        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
