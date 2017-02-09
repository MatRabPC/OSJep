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
#define NUM_PLAYERS 2

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
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
    }

  //  for(int i=1; i<=NUM_PLAYERS; i++){  printf("%s\n", players[i].name); }


//display categories and value amounts
  display_categories();
  
  //Accept input to choose category
  
  fgets(buffer, BUFFER_LEN, stdin);
buffer[strlen(buffer)-1] = '\0';
  for(int j = 0; j < 3; j++){
      if (strcmp(buffer, categories[j]) == 0){ // ***********String compare broken?
      //if category exists, set buffer to *category for display_question
        printf("I hope you know a lot about %s\n", categories[j]); 
        break;
        //prompt dollar amount question
      }
      else
      printf("%s uh oh, not found\n", categories[j]);

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
