/*
ticTacToe.cpp

Provides the bulk of the functionality
for playTicTacToe.cpp

by Tate Mauzy
*/

# include <iostream>
# include <vector>
# include <string>

void greetPlayers() {

    std::cout << "Welcome to Tic-Tac Toe: \n";
    std::cout << "An Interactive C++ Terminal Game by Tate Mauzy\n";
    std::cout << "Would you like to play? [y/n].";

}

// waits for player to either start game or terminate the program
bool getPlayerResponse() {

    bool startGame = false;
    bool quitGame = false;
    std::string playerResponse;

    while (startGame == false && quitGame == false) {
        
        std::getline(std::cin, playerResponse);

        if (playerResponse == "y"){startGame = true;}
        else if (playerResponse == "n"){quitGame = true;}
        else {
            std::cout << "Please enter a valid response [y/n].";
        }

    }

    // startGame should be false if player wants to terminate program
    return startGame;

}

// gets the name of each ticTacToe player
std::string getPlayerName(int playerNumber){

    bool nameConfirm = false;
    std::string playerName;
    std::string playerConfirmation;

    while (nameConfirm == false){

        std::cout << "Player " << playerNumber << ", please enter your name: ";

        std::getline(std::cin, playerName);

        bool playerNameChecked = false;

        // while loop to confirm player's name is right
        while (playerNameChecked == false) {
            std::cout << "Your name is: " << playerName << ". Is this correct?";
            std::cout << "[y/n]";

            std::getline(std::cin, playerConfirmation);
            
            if (playerConfirmation == "y"){
                playerNameChecked = true;
                nameConfirm = true;
            }
            else if (playerConfirmation == "n") {playerNameChecked = true;}
            else {
                std::cout << "Please enter a valid response.\n";
            }
        }

    }
    
    return playerName;

}

void drawBoard(std::vector<int> gameBoard) {

    std::vector<std::string> drawnBoard;

    std::string currChar;

    // build drawnBoard vector
    for (int i = 0; i < 9; i++) {
        
        if (gameBoard[i] == 0) {currChar = "-";}
        else if (gameBoard[i] == 1) {currChar = "O";}
        else {currChar = "X";}

        drawnBoard.push_back(currChar);

    }

    std::cout << "The current game board is this: \n";
    std::cout << drawnBoard.at(0) << " | " << drawnBoard.at(1) << " | " << drawnBoard.at(2) << "\n";
    std::cout <<      "--"     <<            " --- "              <<     "--"      << "\n";
    std::cout << drawnBoard.at(3) << " | " << drawnBoard.at(4) << " | " << drawnBoard.at(5) << "\n";
    std::cout <<      "--"     <<            " --- "              <<     "--"      << "\n";
    std::cout << drawnBoard.at(6) << " | " << drawnBoard.at(7) << " | " << drawnBoard.at(8) << "\n";

}

int getPlayerInput(std::string playerName, std::vector<int> gameBoard) {

    std::string playerResponse;
    bool playerResponded = false;
    int cellSelection;

    while (playerResponded == false) {
        std::cout << playerName << ", please select a number between \n";
        std::cout << "0 and 8 for your move position on the game board. \n";
        std::cout << "(The numbering goes from left-to right, top-to bottom): ";
        
        std::cin >> playerResponse;
        
        // make sure player input is a digit between 0-8
        bool requirementsPassed;
        for (int i = 0; i < playerResponse.length(); i++) {
            if (i > 1 | isdigit(playerResponse[i]) == false | stoi(playerResponse) > 8) {
                requirementsPassed = false;
                break;
            }
            else { 
                requirementsPassed = true;
                cellSelection = stoi(playerResponse);
            }
        }

        if (requirementsPassed == false) {
            std::cout << "Sorry, that isn't a valid response. Please enter \n";
            std::cout << "a single digit between 0 and 8.\n";
        }
        else if (gameBoard[cellSelection] != 0) {
            std::cout << "Sorry, that position has already been taken on \n";
            std::cout << "the board. Please select another position.\n";
        }
        else { playerResponded = true; }
    }
    return cellSelection;
}

std::vector<int> updateBoard(std::vector<int> gameBoard, int playerMove, int currentPlayer) {

    std::vector<int> newBoard;
    
    for (int i = 0; i < 9; i++) {
        if (i == playerMove) {
            newBoard.push_back(currentPlayer);
        }
        else { newBoard.push_back(gameBoard[i]); }
    }

    return newBoard;

}

bool checkForWin(std::vector<int> gameBoard) {
    // 2D vector to store all possible win combinations
    std::vector<std::vector<int>> possibleWinCombos = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    bool isWin = false;

    for (int i = 0; i < possibleWinCombos.size(); i++) {
        int winSum = 0;

        for (int j = 0; j < 3; j++) {
            int coordinate = possibleWinCombos[i][j];
            winSum += gameBoard[coordinate];
        }

        if (winSum == 3 | winSum == -3) {
            isWin = true;
        }
    }
    return isWin;
}

bool checkForCat(std::vector<int> gameBoard) {

    bool isCat = true;

    for (int i = 0; i < 9; i++) {

        if (gameBoard[i] == 0) { isCat = false; } // i.e. board is not full

    }

    return isCat;
}

void printWinMessage(int gameWinner, std::string player1Name, std::string player2Name) {

    if (gameWinner == 0) { std::cout << "It was a tie!!!\n"; }
    else if (gameWinner == 1) { std::cout << "Congratulations, " << player1Name << ", you win!!!\n"; }
    else { std::cout << "Congratulations, " << player2Name << ", you win!!!\n"; }

}

void printGoodbye() {

    std::cout << "Hope you had fun playing!! \nGoodbye!! \n";

}