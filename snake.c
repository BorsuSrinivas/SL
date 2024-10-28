#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100

// Function to roll a die
int rollDie() {
    return (rand() % 6) + 1;
}

// Function to get the new position after moving
int movePlayer(int currentPosition, int roll) {
    currentPosition += roll;

    // Check for ladders
    if (currentPosition == 3) return 22; // Ladder from 3 to 22
    if (currentPosition == 5) return 8;  // Ladder from 5 to 8
    if (currentPosition == 11) return 26; // Ladder from 11 to 26
    if (currentPosition == 20) return 29; // Ladder from 20 to 29
    if (currentPosition == 17) return 4;  // Snake from 17 to 4
    if (currentPosition == 19) return 7;  // Snake from 19 to 7
    if (currentPosition == 21) return 9;  // Snake from 21 to 9
    if (currentPosition == 27) return 1;  // Snake from 27 to 1
    // Additional snakes and ladders can be added here

    // Check for overshooting the board
    if (currentPosition > BOARD_SIZE) {
        currentPosition = BOARD_SIZE - (currentPosition - BOARD_SIZE);
    }

    return currentPosition;
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int player1Position = 0, player2Position = 0;
    int currentPlayer = 1; // Start with player 1

    while (player1Position < BOARD_SIZE && player2Position < BOARD_SIZE) {
        int roll = rollDie();
        printf("Player %d rolled a %d\n", currentPlayer, roll);

        if (currentPlayer == 1) {
            player1Position = movePlayer(player1Position, roll);
            printf("Player 1 is now on square %d\n", player1Position);
            if (player1Position >= BOARD_SIZE) {
                printf("Player 1 wins!\n");
                break;
            }
            currentPlayer = 2; // Switch to player 2
        } else {
            player2Position = movePlayer(player2Position, roll);
            printf("Player 2 is now on square %d\n", player2Position);
            if (player2Position >= BOARD_SIZE) {
                printf("Player 2 wins!\n");
                break;
            }
            currentPlayer = 1; // Switch to player 1
        }
    }

    return 0;
}
