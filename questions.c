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

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
  
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    printf("On the menu tonight:\n ");
    for (int i = 0; i < 3; i++)
    {
        if (qs[0+i].answered || qs[1+i].answered || qs[2+i].answered || qs[3+i].answered == false)
        {
            printf ("%s for  ", categories[i]);

                for (int j = 0; j < 4; j++)
                {
                    if (qs[j + 4*i ].answered == false)
                    {
                        printf("%d ", qs[i+j].value);
                    }
                }
        }
        printf("\n"); //this spacing is necessary, it was getting on my nerves
    }
    
    printf("Pick your poison\n");
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
   
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
