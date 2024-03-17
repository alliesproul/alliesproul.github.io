// Allie Sproul
// Fund Comp Lab 7
// playlife.c 
// asproul

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "lifefunc.h"

#define SIZE 40
#define SPACE ' '

int main (int argc, char *argv[]) {

// declare variables 
	char infile[20]; 
	FILE *fp; 
	char arr[SIZE][SIZE];  
	char arr2[SIZE][SIZE];
	char argument;  
	int row; 
	int col; 

// if the user chooses interactive mode 
	if (argc == 1) {

//initialize, display, and print menu options for user
		initialize(arr);
		initialize(arr2);  
		display(arr); 
		printMenu(); 
		printf("Command: "); 
		scanf(" %c", &argument);  

// run while loop until user quits
		while (argument != 'q'){   
			switch(argument) {
// if user chooses a, add x
				case 'a': 
					scanf("%d %d", &row, &col);
					add(row, col, arr);  
					display(arr); 
					break; 
// if user choose r, remove x 
				case 'r': 
					scanf("%d %d", &row, &col);  
					rmv(row, col, arr); 
					display(arr); 
					break; 
// if user chooses n, advance game by one
				case 'n': 
					advance(arr, arr2);
					display(arr); 	
					break; 
// stop program 
				case 'q': 
					break;
// run game forever  
				case 'p': 
					while (1) {
						advance(arr, arr2); 
						display(arr); 
						usleep(100000);
					}
					break; 
				default:
					printf("invalid argument"); 
					
			}
			getchar();
			printMenu();  
			printf("Command: "); 
			scanf("%c", &argument); 
		} 
	}
// if user chooses batch mode 
	else if (argc == 2) { 
// get file from user and connect to it  
		strcpy(infile, argv[1]); 
		fp = fopen(infile, "r"); 
		initialize(arr); 
		if(!fp) {
			printf("error: can't open file %s\n", infile); 
			return 1; 
		}
// enter while loop to play game 
		while (1) {
			fscanf(fp, "%c", &argument); 

// perform actions based on input from text file 
			switch(argument) {
				case 'a': 
					fscanf(fp, "%d %d", &row, &col);
					arr[row][col] = 'x';   
					display(arr); 
					break; 
				case 'r': 
					fscanf(fp, "%d %d", &row, &col);  
					arr[row][col] = ' ';  
					display(arr); 
					break; 
				case 'n':
					advance(arr, arr2);
					display(arr); 	
					break; 
				case 'q': 
					break; 
				case 'p': 
					while (1) {
						advance(arr, arr2); 
						display(arr); 
						usleep(100000);
					}
					break; 
				default:
					printf("invalid argument"); 	
			}
		}
	}
// if user inputted too many arguments 
	else {
		printf("too many arguments");
		return 1;  
	}

	return 0; 
}

