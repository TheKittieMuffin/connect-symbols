#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcs.h"

char board[7][7] = {{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '}};
int turn = 0;
bool winCheck = false;
bool inputCheck = false;
int column;

int main(int argc, char* argv[]) {
	do {
		//get user input
		do {
			column = userInput();
			for (int i = 6; i >= 0; i--) {
				if (!isalpha(board[i][column])) {
					if ((turn % 2) == 0) {
						board[i][column] = 'X';
						i = 0;
						inputCheck = true;
					} else if ((turn % 2) != 0) {
						board[i][column] = 'O';
						i = 0;
						inputCheck = true;
					} else {
						printf("try again!\n");
					}
				}
			}
		} while (inputCheck == false);

		//print board on screen
		printf("[0][1][2][3][4][5][6]\n");
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				printf("[%c]", board[i][j]);
			}
			printf("\n");
		}

		winCheck = winCondition(board);
		turn = turn + 1;
		inputCheck = false;
	} while (winCheck == false);
	return EXIT_SUCCESS;
}
