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
#include "questions.h"

question quest[NUM_QUESTIONS] = {

{
    "Beatles",
    "This one was married to Yoko Ono",
    "JOHN",
    100,
    false
},

{
    "Beatles",
    "This one played bass",
    "PAUL",
    200,
    false
},

{
    "Beatles",
    "This one died in 1966",
    "PAUL", 
    300,
    false
},

{
    "Beatles",
    "This one lifts 850 times its body mass",
    "HERCULES",
    400,
    false
},

{
    "Insects",
    "This one spins a web",
    "SPIDER",
    100,
    false
},
{
    "Insects",
    "This one is named after its mode of transportation",
    "FLY",
    200,
    false
},

{
    "Insects",
    "This one crawls on the ground",
    "WORM",
     300,
    false
},

{
    "Insects",
    "This one is not margerine and doesn't walk",
    "BUTTERFLY",
    400,
    false
},

{
    "Bugs",
    "Number when page not found",
    "404",
    100,
    false
},

{
    "Bugs",
    "I couldn't think of another one",
"404",
    200,
    false
},

{
    "Bugs",
     "I couldn't think of one more'",
  "404",
    300,
    false
},

{
    "Bugs",
    "Name in Hyrule",
    "ERROR",
    400,
    false
}
};

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
  
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("On the menu tonight:\n");
    for (int i = 0; i < 3; i++)
    {
        if (quest[0+i].answered || quest[1+i].answered || quest[2+i].answered || quest[3+i].answered == false)
        {
            printf ("%-5s %-5s\t", categories[i], "for");
 
                for (int j = 0; j < 4; j++)
                {
                    if (quest[i*4 + j].answered == false)
                    {
                        printf("%-2d \t", quest[i*4 +j].value);
                    }
			else printf("%-2s\t", " ");
                }
        }
        printf("\n"); //this spacing is necessary, it was getting on my nerves
    }
    
    printf("Pick your poison: ");
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
   //printf("%s  %d\n", category, value);
for (int i=0; i<NUM_QUESTIONS; i++)
{
if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
{
printf("\033[1;34m%s\033[0m\n", quest[i].question);
}
}
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
for (int i=0; i<NUM_QUESTIONS; i++)
{
	if ( ( strcmp(quest[i].category, category) == 0 ) && (quest[i].value == value) )
	{
		if ( strcmp(quest[i].answer, answer) == 0 ) 
		{
			return true;
		}
		else { return false; }
	}
}
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
