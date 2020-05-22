/*
playTicTacToe.cpp

Tic-Tac-Toe
An interactive C++ terminal game
by Tate Mauzy
*/

# include <iostream>
# include <vector>
# include <string>
# include "ticTacToe.hpp"

int main() {

    greetPlayers();
    bool startGame = getPlayerResponse();
    // terminates program upon player responding "n"
    if (startGame == false) {return 1;}

    std::string player1Name = getPlayerName(1);
    std::string player2Name = getPlayerName(2);

    std::vector<int> gameBoard = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool gameOver = false;
  
    int currentPlayer = 1;
    int gameWinner;

    while (gameOver == false) {

        drawBoard(gameBoard);
        
        int playerMove;
        
        if (currentPlayer == 1) { playerMove = getPlayerInput(player1Name, gameBoard); }
        else { playerMove = getPlayerInput(player2Name, gameBoard); }

        gameBoard = updateBoard(gameBoard, playerMove, currentPlayer);

        if (checkForWin(gameBoard)) {
            gameOver = true;
            gameWinner = currentPlayer;
        }
        else if (checkForCat(gameBoard)) {
            gameOver = true;
            gameWinner = 0; // no winner, since it will either be +1 or -1
        }

        currentPlayer *= -1;
    }

    drawBoard(gameBoard);

    printWinMessage(gameWinner, player1Name, player2Name);
    printGoodbye();
    
}