#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define guess_limit 5

typedef struct
{
	int index, guess_list[guess_limit], attemp_count, result, secret;	
}hand; // I know it can be more useful than now if i define secret or guess_list as string but,
       // I want to use all of them as same type and also want to use atoi() function.

void bulls_cows(char arr1[],char arr2[],int size,int *bull, int *cow);
int check_alpha(char arr[], int size);
void integer_to_string(char arr1[],int arr2[],int size);
void generate_number(int arr[], int size);