#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"

void bulls_cows(char arr1[],char arr2[],int size,int *bull, int *cow) // This function checks bulls and cows. I don't know that prefixes may be dangerous but i use.
{
	int i,j;
	for(i = 0; i < size; i++)
	{
		if(arr1[i] == arr2[i])
			++(*bull);
		for(j = 0; j < size; j++ )
		{	
			if(arr1[i] == arr2[j])
				++(*cow); 
		}	
	}
}

int check_alpha(char arr[], int size) // This function, as you understand its' name , check alphabet characters in string.
{
	int i;
	for(i = 0;i < size; i++)
	{
		if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
		{
			return 1;
		}		 
	}

	return 0;
}

void integer_to_string(char arr1[],int arr2[],int size) // This function converts integer array to string array but it needs 1 empty character array
{                                                       // to fill up.
	int i;

	for(i = 0;i < size;i++)
	{
		switch(arr2[i])
			{
		case 0:arr1[i] = '0'; break;
		case 1:arr1[i] = '1'; break;
		case 2:arr1[i] = '2'; break;
		case 3:arr1[i] = '3'; break;
		case 4:arr1[i] = '4'; break;
		case 5:arr1[i] = '5'; break;
		case 6:arr1[i] = '6'; break;
		case 7:arr1[i] = '7'; break;
		case 8:arr1[i] = '8'; break;
		case 9:arr1[i] = '9'; break;
			}
	}
	arr1[size] = '\0';
}
void generate_number(int arr[], int size) // The most difficult problem i've ever seen but thanks to our teacher i solved.
{                                         // This function creates random number whose digits are different each other.
	int *incrementer, j, flag = 1;

	srand(time(NULL));

	*arr = rand() % 10;
	incrementer = arr;

	while(flag < size)
	{
		incrementer++;
		check:
		*incrementer = rand() % 10;
		for(j = 0; j < flag ; j++)
		{
			if(arr[j] == *incrementer)
				goto check;
		}		
		flag++;
	}
}