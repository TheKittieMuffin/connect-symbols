int userInput(void) {
	int input = -1;
	do {
		printf("please enter column: ");
		scanf("%i", &input);
	} while ((input < 0) || (input > 6));
}

bool winCondition(char board[7][7]) {
	//vertical win conditions
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((isalpha(board[j][i])) && (board[j][i] == board[j+1][i]) &&
				       	(board[j][i] == board[j+2][i]) && (board[j][i] == board[j+3][i])) {
				printf("%c has won!\n", board[j][i]);
				return true;
			}
		}
	}


	//horizontal win conditions
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((isalpha(board[j][i])) && (board[j][i] == board[j][i+1]) &&
					(board[j][i] == board[j][i+2]) && (board[j][i] == board[j][i+3])) {
				printf("%c has won!\n", board[j][i]);
				return true;
			}
		}
	}

	//diagonal down win conditions
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((isalpha(board[j][i])) && (board[j][i] == board[j+1][i+1]) &&
					(board[j][i] == board[j+2][i+2]) && (board[j][i] == board[j+3][i+3])) {
				printf("%c has won!\n", board[j][i]);
				return true;
			}
		}
	}

        //diagonal up win conditions
        for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 7; j++) {
                        if ((isalpha(board[j][i])) && (board[j][i] == board[j+1][i-1]) &&
                                        (board[j][i] == board[j+2][i-2]) && (board[j][i] == board[j+3][i-3])) {
                                printf("%c has won!\n", board[j][i]);
                                return true;
                        }
                }
        }
	return false;
}
