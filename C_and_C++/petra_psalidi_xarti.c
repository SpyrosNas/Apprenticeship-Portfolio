#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    system("clear"); // or "cls" depending on the system
}

char getPlayerChoice() {
    char choice;
    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &choice);
    return choice;
}

int determineWinner(char player1, char player2) {
    if (player1 == player2) {
        printf("It's a tie!\n");
        return 0;
    }
    else if ((player1 == 'R' && player2 == 'S') ||
             (player1 == 'P' && player2 == 'R') ||
             (player1 == 'S' && player2 == 'P')) {
        printf("Player 1 wins!\n");
        return 1;
    }
    else {
        printf("Player 2 wins!\n");
        return 2;
    }
}

void waitForUser() {
    printf("Press Enter to continue...");
    getchar(); // consume the newline left in the buffer
    getchar(); // wait for the user to press Enter
}

int main() {
    char player1Choice, player2Choice;
    int playAgain = 1;

    printf("Enter the name of Player 1: ");
    char player1Name[50];
    scanf("%s", player1Name);

    printf("Enter the name of Player 2: ");
    char player2Name[50];
    scanf("%s", player2Name);

    while (playAgain) {
        int rounds = 3;
        int player1Wins = 0, player2Wins = 0;

        for (int i = 0; i < rounds; ++i) {
            clearScreen();
            printf("Round %d\n", i + 1);

            printf("%s:\n", player1Name);
            player1Choice = getPlayerChoice();
            clearScreen();

            printf("%s:\n", player2Name);
            player2Choice = getPlayerChoice();
            clearScreen();

            int result = determineWinner(player1Choice, player2Choice);

            printf("%s chose: %c\n", player1Name, player1Choice);
            printf("%s chose: %c\n", player2Name, player2Choice);

            if (result == 1) {
                player1Wins++;
            }
            else if (result == 2) {
                player2Wins++;
            }

            waitForUser(); // wait for user input before clearing the screen
        }

        clearScreen();
        if (player1Wins > player2Wins) {
            printf("%s wins the game!\n", player1Name);
        }
        else if (player2Wins > player1Wins) {
            printf("%s wins the game!\n", player2Name);
        }
        else {
            printf("It's a tie in the overall game!\n");
        }

        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        scanf("%d", &playAgain);
        clearScreen();
    }

    printf("Thanks for playing!\n");
    return 0;
}