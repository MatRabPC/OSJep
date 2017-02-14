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

#define BUFFER_LEN 256
#define NUM_PLAYERS 3


// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Process winner
int winner();

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players);

int main()
{
    // An array of 4 players (+1 for offset, as players are secondarily identified as players 1-4)
    player players[NUM_PLAYERS+1];
    
    int qsleft = NUM_QUESTIONS - 1; //track number of questions left
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    printf("Welcome to a cheap rendition of jeopardy *sigh*.\n");

    // Prompt for players names & initialize each of the players in the array
    for(int i=1; i<=NUM_PLAYERS; i++)
    {
        printf("Yo, Player %d, enter a name (and try not to embarrass yourself)\n", i);
        fgets(players[i].name, BUFFER_LEN, stdin);
        
        while (player_exists(players, i, players[i].name))
        {
            printf("Name exists (but I'm pretty sure you knew that). Please be at least sligthly more original.\n");
            fgets(players[i].name, BUFFER_LEN, stdin);

        }

    if (players[i].name[strlen(players[i].name)-1] == '\n') { players[i].name[strlen(players[i].name)-1] = '\0'; } //remove newline     
	players[i].score = 0; // initialise score to 0
    
    }
    
    system("clear"); //clear screen

  //  for(int i=1; i<=NUM_PLAYERS; i++){  printf("%s\n", players[i].name); } //DEBUG


    char cat[BUFFER_LEN] = { 0 }; //category
    int value = 0;
    char *token;
    int playah = 1;

    while (1) //actual game part
    {
        printf("A'right, %s. \n", players[playah].name);
        display_categories();
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strlen(buffer)-1] = '\0';
        
        if (strcmp(buffer, "quit") == 0)
            {
                return EXIT_SUCCESS; //DEBUG
            }
        
        token = strtok(buffer, " ");
        strcpy(cat, token);
        token = strtok(NULL, " ");
        value = atoi(token);

        for(int j = 0; j < 3; j++) 
        {

            if ( (strcmp(cat, categories[j]) == 0) ){ 
            //if category exists, set buffer to *category for display_question
                printf("I hope you know a lot about %s. We've got %d on the line.\n", categories[j], value); 
                display_question(&categories[j], value);
                fgets(buffer, BUFFER_LEN, stdin);
                buffer[strlen(buffer)-1] = '\0';

            if (valid_answer(&categories[j], value, buffer))
            {
                if (value == 100)
                    printf("Pfft, too easy.\n");
                else if (value == 200)
                        printf("That wasn't that hard.\n");
                else if (value == 300)
                        printf("Fine, you win this one.\n");
                else if (value == 400)
                        printf("I'm impressed you got that. But that wasn't a compliment.\n");
                else printf("Wut\n");
                
                update_score(players, playah, value); 
            }

            else
            {
                if (value == 100)
                    printf("Couldn't even get that?\n");
                else if (value == 200)
                        printf("Nope.\n");
                else if (value == 300)
                        printf("Try again. Not.\n");
                else if (value == 400)
                        printf("Try something more in your league.\n");
                else printf("Wut\n");
            }
            
            // see if there are still questions left
            if (qsleft)
            {
                qsleft--;
                //printf("Qs left: %d\n", qsleft);  //DEBUG
                if (playah == NUM_PLAYERS)
                {
                    printf("Let's show them the leaderboard: \n");
                    show_results(players);
                    printf("New round, let's get this over with.");
                    fgets(buffer, BUFFER_LEN, stdin); //wait for enter
                    playah = 1;
                }

                else
                {	
                    printf("So we have %s with %d points, kapiche?\n", players[playah].name, players[playah].score);
                    printf("Let's go to the next player");
                    playah += 1;
                    fgets(buffer, BUFFER_LEN, stdin); //pause
                }
            
                system("clear");//clear screen
                
                }
        
            else //if we run out of questions
            {
            printf("Game over, the winner is %s with %d points. Congratulations on wasting all that time.\n", players[winner(players)].name, players[winner(players)].score);
            return EXIT_SUCCESS;
            }
                
            }
            
        }

        }

    return EXIT_SUCCESS; // END
}



int winner(player *players)
{
    int max = 0;
	int best = 0;
	
    for (int i = 1; i <=NUM_PLAYERS; i++)
	{
	    if (players[i].score > max) //if player score is bigger than max...
	    {
            max = players[i].score; //...set max to player score
            best = i; //and set player number to best
        }

	}

	return best; //TODO add tie breaker
}

void show_results(player *players)
{
    printf("\n\033[1m\033[30m~LEADERBOARD~\n\033[0m");
    for (int i =1; i<=NUM_PLAYERS; i++)
    {
        printf("%s: %-5d", players[i].name, players[i].score);
    }
    printf("\n");
 
}
