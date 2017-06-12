#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

/* I'm ready to be servant of my teacher who teach me all things what i've learnt or only one letter. It doesn't matter how much you teach me.
   Regards... Ahmet Oðuzhan Günöz */
int main()
{
	FILE *fp;

	hand object;
	char *secret_number_S, guess[11], *choice;
	int *secret_number_I, digit_count, i, j, index = 0, attempt = 0, bulls = 0, cows = 0, limit = 0;

	choice = (char *)malloc(3*sizeof(char) + 1);
	strcpy(choice,"yes");

	fp = fopen("history.txt","w");

	if((fp = fopen("history.txt","w")) == NULL)
	{
		printf("Can`t open %s\n", "history.txt"); 
		exit(1);
	}

	printf("***Welcome to The Bulls & Cows Game***\n");

	while((strcmp(choice,"yes")) == 0)
	{
		printf("Enter the digit count that you desire(max 10): ");
		scanf("%d", &digit_count);

		secret_number_S = (char *)malloc((digit_count*sizeof(char)) + 1); //Dynamically allocation is easier and faster.
		secret_number_I = (int *)malloc(digit_count*sizeof(int));

		if(secret_number_S == NULL)
		{
			printf("Something went wrong_1\n");
			exit(EXIT_FAILURE);
		}

		if(secret_number_I == NULL)
		{
			printf("Something went wrong_2\n");
			exit(EXIT_FAILURE);
		}
		
		generate_number(secret_number_I, digit_count);  // Create number whose digits are different each other

		integer_to_string(secret_number_S,secret_number_I,digit_count); // Convert number to a string form

		free(secret_number_I); // Do not need it anymore
		object.secret = atoi(secret_number_S);    // Get the full number without array by the help of atoi() function
		++index;
		object.index = index;

		printf("Ok, I have chosen a number.\n");
	
		while(limit < guess_limit)
		{
			start:
			printf("Enter your guess(Guess limit is 5): ");
			scanf(" %s", guess);
			if(strcmp(guess,"quit") == 0)
			{
				object.attemp_count = attempt;
				printf("You lose!\n"); object.result = 0; free(secret_number_S); break;
			}
			else if(strlen(guess) != digit_count)
			{
				printf("Guess must have lenght of %d, try again\n", digit_count); goto start;
			}
			else if(strcmp(guess,secret_number_S) == 0)
			{
				object.attemp_count++;
				object.guess_list[limit] = atoi(guess);
				printf("You win!\n"); object.result = 1; free(secret_number_S); break;
			}
			else if(check_alpha(guess, digit_count))
			{
				printf("Contains non-numbers, try again\n");
				goto start; 
			}
			else
			{
				attempt++;
				object.attemp_count = attempt;
				object.guess_list[limit] = atoi(guess);
				limit++;
				bulls_cows(guess, secret_number_S, digit_count, &bulls, &cows);
				printf("Bulls:%d Cows:%d \n", bulls, cows);
				cows = 0;
				bulls = 0;
				if(limit == 5)
				{
					printf("You lose!\n"); printf("Number was: %d\n", object.secret); object.result = 0; free(secret_number_S); break;
				}

			}
		}
		
		limit = 0; // Updating those values for next game.
		attempt = 0;

		fprintf(fp,"%d ",object.secret);
		for(i = 0 ; i < object.attemp_count ; i++)
		{
			fprintf(fp,"%d ", object.guess_list[i]);
		}
		fprintf(fp,"%d ", object.attemp_count);
		fprintf(fp,"%d\n", object.result);

		printf("Do you want to play again (yes/no): ");
		scanf(" %s", choice);
	}

	fclose(fp);

	return 0;
}
		


	
	


	


	