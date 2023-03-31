int userInput(void) {
	int input = -1;
	do {
		printf("please enter column: ");
		scanf("%i", &input);
	} while ((input < 0) || (input > 6));
}

bool winCondition(char board[7][7]) {
	return false;
}
