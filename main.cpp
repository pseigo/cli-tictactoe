#include <iostream>
#include <cstdlib> // rng
#include <ctime> // time
#include <string>
#include <fstream> // scoreboard file io

#include "Ai.h"

using namespace std;

// Globals
int scoreboardWins = 0,
    scoreboardLosses = 0,
    scoreboardTies = 0;

// Function Prototypes
void pcOneTurn(int board[3][3], int round, int player);
void pcTwoTurn(int board[3][3], int round, int player);
bool aiOneTurn(int board[3][3], int &round, Ai AiOne);
bool aiTwoTurn(int board[3][3], int &round, Ai AiTwo);

bool gameOver(const int board[3][3], int &round, int pcPlayer); // return, 0: game isn't over, 1: game is over
void resetBoard(int board[3][3]);   // resets all board values to 0 (blank)
void printBoard(const int board[3][3]);   // prints current board to screen
bool checkWin(const int board[3][3], int pcPlayer);     // pcPlayer 0: no scoreboard for pc/pc or ai/ai, 1: pc is X, 2: pc is O
bool checkTie(const int board[3][3], int round);     // checks for tie
void playMove(int board[3][3], int player);

void loadScoreboard();      // loads current values from ./doc/scoreboard.txt to global variables
void updateScoreboard(const int gameResult);    // 0: win, 1: losses, 2: ties
void printScoreboard();
void resetScoreboard();     // reset scoreboard to 0

void clearScreen();

// --------------------------------------------------------------------------
int main()
{
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
    bool gameRunning = 1,
        saveConfig = 0,
        saveConfigDontAsk = 0;

    srand( unsigned(time(0)) ); // AI rng seed

    loadScoreboard();   // should this be loaded at launch, or before each win/loss/tie/scoreboard view?

    /*
     * GAME TEMPLATE!

    // ## START OF GAME
    clearScreen();
    cout << "################ \n"
            "New game started! \n"
            "################ \n" << endl;

    // new game variables
    int winner = 0;
    int round = 0;
    // Ai AiOne(2, 2); // O, medium

    while (true) {
        // PLAYER 1: pcOne
        pcOneTurn(board, round, 1);

        if (gameOver(board, round, 1)) {
            break;
        }
        clearScreen();

        // PLAYER 2: AiOne
        if (!aiOneTurn(board, round, AiOne))
            break; // break if an error occurs

        if (gameOver(board, round, 1)) {
            break;
        }
    }
    // ## END OF GAME

     *
    */



    // ## START OF gameRunning main loop
    do {
        int choicePcAi,  // 1: pc/ai, 2: pc/pc
            choicePcOrder, // 1: pc 1, 2: pc 2, 3: random
            choicePcSymbol, // 1: X (1/2), 2: O (3/4)
            choiceAiSymbol, // opposite of choicePcSymbol
            choicePcDifficulty;

        /// IDEA: add menu
        /// 0: quit, 1: play game, 2: scoreboard

        clearScreen();
        cout << "\t####################### \n"
                "\tWELCOME TO TIC TAC TOE! \n"
                "\t####################### \n\n"
                "Before you play, please set your options. \n"
                "Type a number to choose an option. \n"
                << endl;

        cout << "Play with against a computer (PC vs AI) or a friend (PC vs PC)? \n"
                "\t1: PC vs AI    2: PC vs PC" << endl;

        while (true) {
            cout << ">> ";
            cin >> choicePcAi;
            cout << endl;
            if (!cin.good() || (choicePcAi != 1 && choicePcAi != 2) ) {
                cout << "Invalid option. Choices are 1 or 2." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else {
                break;
            }
        }

        // skip order of play question and symbol if playing PC/PC
        if (choicePcAi == 1) {
            cout << "Do you want to play first, second, or choose randomly? \n"
                    "\t1: Play first    2: Play second    3: Choose randomly" << endl;

            while (true) {
                cout << ">> ";
                cin >> choicePcOrder;
                cout << endl;
                if (!cin.good() || (choicePcOrder != 1 && choicePcOrder != 2 && choicePcOrder != 3) ) {
                    cout << "Invalid option. Choices are 1, 2 or 3." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }

            cout << "Do you want to play as X or O? \n"
                    "\t1: X    2: O" << endl;

            while (true) {
                cout << ">> ";
                cin >> choicePcSymbol;
                cout << endl;
                if (!cin.good() || (choicePcSymbol != 1 && choicePcSymbol != 2) ) {
                    cout << "Invalid option. Choices are 1 or 2." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }

            if (choicePcSymbol == 1) {
                choiceAiSymbol = 2;
            } else {
                choiceAiSymbol = 1;
            }

            cout << "Play on Easy, Medium, or Hard? \n"
                    "\t1: Easy    2: Medium    3: Hard" << endl;

            while (true) {
                cout << ">> ";
                cin >> choicePcDifficulty;
                cout << endl;
                if (!cin.good() || (choicePcDifficulty != 1 && choicePcDifficulty != 2 && choicePcDifficulty != 3) ) {
                    cout << "Invalid option. Choices are 1, 2 or 3." << endl;
                    cin.clear();
                    cin.ignore(128, '\n');
                } else {
                    break;
                }
            }
        }
        // END OF CONFIG

        // ## START OF saveConfig loop
        do
        {
        // game variables init
        resetBoard(board);

        // pc or ai? 1: pc/ai, 2: pc/pc
        if (choicePcAi == 2) {
            // ## START OF GAME: pc/pc
            clearScreen();
            cout << "  ################ \n"
                    "  New game started! \n"
                    "  ################ \n" << endl;

            int round = 0;

            while (true) {
                // PLAYER 1: pcOne
                pcOneTurn(board, round, 1);

                if (gameOver(board, round, 0)) {
                    break;
                }
                clearScreen();

                // PLAYER 2: aiOne
                pcTwoTurn(board, round, 2);

                if (gameOver(board, round, 0)) {
                    break;
                }
                clearScreen();
            }
            // ## END OF GAME

        } else {    // pc/ai

            // Who goes first?
            if (choicePcOrder == 1) {   // pc goes first
                // ## START OF GAME: pc/ai, pc goes first
                clearScreen();
                cout << "  ################ \n"
                        "  New game started! \n"
                        "  ################ \n" << endl;

                int round = 0;
                Ai AiOne(choiceAiSymbol, choicePcDifficulty);

                while (true) {
                    // PLAYER 1: pcOne
                    pcOneTurn(board, round, choicePcSymbol);

                    if (gameOver(board, round, choicePcSymbol)) {
                        break;
                    }
                    clearScreen();

                    // PLAYER 2: AiOne
                    if (!aiOneTurn(board, round, AiOne))
                        break; // break if an error occurs

                    if (gameOver(board, round, choicePcSymbol)) {
                        break;
                    }
                }
                // ## END OF GAME

            } else if (choicePcOrder == 2) {    // ai goes first
                // ## START OF GAME: pc/ai, ai goes first
                clearScreen();
                cout << "  ################ \n"
                        "  New game started! \n"
                        "  ################ \n" << endl;

                int round = 0;
                Ai AiOne(choiceAiSymbol, choicePcDifficulty);

                while (true) {
                    // PLAYER 1: AiOne
                    if (!aiOneTurn(board, round, AiOne))
                        break; // break if an error occurs

                    if (gameOver(board, round, choicePcSymbol)) {
                        break;
                    }

                    // PLAYER 2: pcOne
                    pcOneTurn(board, round, choicePcSymbol);

                    if (gameOver(board, round, choicePcSymbol)) {
                        break;
                    }
                    clearScreen();

                }
                // ## END OF GAME


            } else {    // random order
                // ## START LOOP: pc/ai, order is random, pc is X

                if ( (rand() % (3 - 2 + 1) + 2) == 2) {
                    // random play order loop #1
                    // ## START OF GAME: pc/ai, pc goes first
                    clearScreen();
                    cout << "  ################ \n"
                            "  New game started! \n"
                            "  ################ \n" << endl;

                    int round = 0;
                    Ai AiOne(choiceAiSymbol, choicePcDifficulty);

                    while (true) {
                        // PLAYER 1: pcOne
                        pcOneTurn(board, round, choicePcSymbol);

                        if (gameOver(board, round, choicePcSymbol)) {
                            break;
                        }
                        clearScreen();

                        // PLAYER 2: AiOne
                        if (!aiOneTurn(board, round, AiOne))
                            break; // break if an error occurs

                        if (gameOver(board, round, choicePcSymbol)) {
                            break;
                        }
                    }
                    // ## END OF GAME
                } else {
                    // random play order loop #2
                    // ## START OF GAME: pc/ai, ai goes first
                    clearScreen();
                    cout << "  ################ \n"
                            "  New game started! \n"
                            "  ################ \n" << endl;

                    int round = 0;
                    Ai AiOne(choiceAiSymbol, choicePcDifficulty);

                    while (true) {
                        // PLAYER 1: AiOne
                        if (!aiOneTurn(board, round, AiOne))
                            break; // break if an error occurs

                        if (gameOver(board, round, choicePcSymbol)) {
                            break;
                        }

                        // PLAYER 2: pcOne
                        pcOneTurn(board, round, choicePcSymbol);

                        if (gameOver(board, round, choicePcSymbol)) {
                            break;
                        }
                        clearScreen();

                    }
                    // ## END OF GAME
                }


            } // end of 'Who goes first?' branch
        } // end of pc/ai branch

        // ## END OF GAME. CHECK IF WANT TO PLAY AGAIN ##
        int choicePlayAgain,
            choiceSaveConfig;

        cout << "\n ###################################### \n"
                "It's over! Would you like to play again? \n"
                "\t1: Yes    2: No" << endl;

        while (true) {
            cout << ">> ";
            cin >> choicePlayAgain;
            cout << endl;
            if (!cin.good() || (choicePlayAgain != 1 && choicePlayAgain != 2) ) {
                cout << "Invalid option. Choices are 1 or 2." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else {
                break;
            }
        }

        if (choicePlayAgain == 2) {
            cout << "\nThanks for playing!" << endl;
            cout << "## Peyton Seigo. March 2017. ## \n";
            gameRunning = 0;
            return 0;
        }

        // if gameRunning = 0, saveConfig = 0 because you want the game to end.
        if (gameRunning == 0) {
            saveConfig = 0;
        } else {
            if (!saveConfigDontAsk) { // ask to save config if option 3 hasn't been chosen
                cout << "Would you like to use the same game settings as before? \n"
                    "\t1: Yes    2: No    3: Yes, and don't ask until next game launch" << endl;

                while (true) {
                    cout << ">> ";
                    cin >> choiceSaveConfig;
                    cout << endl;
                    if (!cin.good() || (choiceSaveConfig != 1 && choiceSaveConfig != 2 && choiceSaveConfig != 3) ) {
                        cout << "Invalid option. Choices are 1, 2 or 3." << endl;
                        cin.clear();
                        cin.ignore(128, '\n');
                    } else {
                        break;
                    }
                }

                if (choiceSaveConfig == 2) {
                    saveConfig = 0;
                } else {
                    saveConfig = 1;
                    if (choiceSaveConfig == 3) {
                        saveConfigDontAsk = 1;
                    }
                }

            }
        }

        } while (saveConfig);
    } while (gameRunning);


    return 0;
}

/*
 * == Turn Functions
 * turns for each player
*/

// --------------------------------------------------------------------------
void pcOneTurn(int board[3][3], int round, int player)
{
    cout << "------- turn " << round + 1 << " -------" << endl;
    printBoard(board);

    playMove(board, player);
}

// --------------------------------------------------------------------------
void pcTwoTurn(int board[3][3], int round, int player)
{
    cout << "------- turn " << round + 1 << " -------" << endl;
    printBoard(board);

    playMove(board, player);
}

// --------------------------------------------------------------------------
bool aiOneTurn(int board[3][3], int &round, Ai AiOne)
{
    cout << "------- turn " << round + 1 << " -------" << endl;
    printBoard(board);

    switch (1) {
        case 1:
            if (round == 0) {
                if (AiOne.playCornerMove(board))
                    break;
            }
        case 2:
            if (AiOne.playWinningMove(board))
                break;
        case 3:
            if (AiOne.blockWinningMove(board))
                break;
        case 4:
            //if (AiOne.playForkMove(board))
            //    break;
        case 5:
            //if (AiOne.blockForkMove(board))
            //    break;
        case 6:
            if (AiOne.playCenterMove(board))
                break;
        case 7:
            if (AiOne.playOppositeCornerMove(board))
                break;
        case 8:
            if (AiOne.playCornerMove(board))
                break;
        case 9:
            if (AiOne.playSideMove(board))
                break;
        case 10:
            if (AiOne.playRandomMove(board))
                break;
        default:
            cerr << "ERROR, nothing happened! AI was unable to play a valid move." << endl;
            cerr << "\tPlease report this error with a screenshot of the board, thanks!\n" << endl;
            round = 100;
            return false;
    }

    return true;
}

// --------------------------------------------------------------------------
bool aiTwoTurn(int board[3][3], int &round, Ai AiTwo)
{
    cout << "------- turn " << round + 1 << " -------" << endl;
    printBoard(board);

    switch (1) {
        case 1:
            if (round == 0) {
                if (AiTwo.playCornerMove(board))
                    break;
            }
        case 2:
            if (AiTwo.playWinningMove(board))
                break;
        case 3:
            if (AiTwo.blockWinningMove(board))
                break;
        case 4:
            //if (AiTwo.playForkMove(board))
            //    break;
        case 5:
            //if (AiTwo.blockForkMove(board))
            //    break;
        case 6:
            if (AiTwo.playCenterMove(board))
                break;
        case 7:
            if (AiTwo.playOppositeCornerMove(board))
                break;
        case 8:
            if (AiTwo.playCornerMove(board))
                break;
        case 9:
            if (AiTwo.playSideMove(board))
                break;
        case 10:
            if (AiTwo.playRandomMove(board))
                break;
        default:
            cerr << "ERROR, nothing happened! AI was unable to play a valid move." << endl;
            cerr << "\tPlease report this error with a screenshot of the board, thanks!\n" << endl;
            round = 100;
            return false;
    }

    return true;
}

/*
 * == Board Functions ==
 * deals with board manipulation and output and some other game mechanics
*/

bool gameOver(const int board[3][3], int &round, int pcPlayer) // return, 0: game isn't over, 1: game is over
{
    if (checkWin(board, pcPlayer)) {
        return true;
    }

    round++;
    if (checkTie(board, round)) {
        return true;
    }

    return false;
}

void resetBoard(int board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // resets all values on board to 0
            board[i][j] = 0;
        }
    }
}

// --------------------------------------------------------------------------
void printBoard(const int board[3][3]) {
    cout << "    1 2 3" << endl;
    for (int row = 0; row < 3; ++row) {
        switch (row) {
        case 0: cout << " A "; break;
        case 1: cout << " B "; break;
        case 2: cout << " C "; break;
        }

        for (int column = 0; column < 3; ++column) {

            switch (board[row][column]) {
            case 0: cout << " -"; break;
            case 1: cout << " X"; break;
            case 2: cout << " O"; break;
            default: cout << " n"; break;
            }

        }
        // new row
        cout << endl;
    }
    cout << endl;
}

// --------------------------------------------------------------------------
bool checkWin(const int board[3][3], int pcPlayer) // pcPlayer 0: disable scoreboard 1: pc is playing X 2: pc is playing O
{
    int winner = 0;

    // checks horizontal rows for win
    for (int row = 0; row < 3; ++row) {
        // check if all 3 are == 1 or 2. if true, break and return 1 for winner 1 and 2 for winner 2. else 0 for no win.
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            winner = board[row][0];

            if (winner) {
                break;
            }
        }
    }

    if (winner == 0) {
        // checks vertical columns for win
        for (int column = 0; column < 3; ++column) {
            // check if all 3 are == 1 or 2. if true, break and return 1 for winner 1 and 2 for winner 2. else 0 for no win.
            if (board[0][column] == board[1][column] && board[0][column] == board[2][column]) {
                winner = board[0][column];

                if (winner) {
                    break;
                }
            }

        }
    }

    if (winner == 0) {
        // top left to bottom right
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            winner = board[0][0];
        }

        // top right to bottom left
        if (winner == 0 && (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
            winner = winner = board[0][2];
        }
    }
    if (winner) {
        cout << "------- end of game -------" << endl;
        printBoard(board);
    }
    switch (winner) {
    case 1: cout << "Three in a row, X wins!" << endl; break;
    case 2: cout << "Three in a row, O wins!" << endl; break;
    }

    // only update scoreboard if playing pc/ai. if ai/ai or pc/pc, don't update scoreboard.

    if (winner) {
        if (pcPlayer == winner) {
            loadScoreboard();
            updateScoreboard(1); // win
            printScoreboard();
            cout << endl;
        } else if (pcPlayer == 0) {
            return true; // disabled scoreboard
        } else {
            loadScoreboard();
            updateScoreboard(2); // loss
            printScoreboard();
            cout << endl;
        }

        return true;
    }

    return false;
}

// --------------------------------------------------------------------------
bool checkTie(const int board[3][3], int round)
{
    if (round > 8) {
        cout << "------- end of game -------" << endl;
        printBoard(board);

        cout << "Game, over, it's a tie!" << endl;
        loadScoreboard();
        updateScoreboard(0);
        printScoreboard();
        return true;
    }

    return false;
}

// --------------------------------------------------------------------------
void playMove(int board[3][3], int player)
{
    string inputMoveRow;
    int inputMoveColumn,
        inputMoveX,
        inputMoveY;
    char playerSymbol;
    locale loc;

    if (player == 1) {
        playerSymbol = 'X';
    } else {
        playerSymbol = 'O';
    }

    cout << "It's " << playerSymbol << "'s turn! \nWhere would you like to play? (A-C 1-3)" << endl;

    while (true) {
        while (true) {
            cout << ">> ";
            cin >> inputMoveRow >> inputMoveColumn;
            cout << endl;

                // converts inputMoveColumn to lowercase
            for (string::size_type i=0; i < inputMoveRow.length(); i++)
                inputMoveRow[i] = std::toupper(inputMoveRow[i],loc);


            if (!cin.good() || (inputMoveColumn < 1 || inputMoveColumn > 3) || (inputMoveRow != "A" && inputMoveRow != "B" && inputMoveRow != "C") ) {
                cout << "Invalid position! Row must be from A-C and column from 1-3 (eg. A 1)." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else {
                cin.ignore(128, '\n');
                break;
            }
        } // end of input error trap

        if (inputMoveRow == "A") {
            inputMoveX = 0;
        } else if (inputMoveRow == "B") {
            inputMoveX = 1;
        } else {
            inputMoveX = 2;
        }

        switch (inputMoveColumn) {
        case 1:
            inputMoveY = 0;
            break;
        case 2:
            inputMoveY = 1;
            break;
        case 3:
            inputMoveY = 2;
            break;
        }

        if (board[inputMoveX][inputMoveY] != 0) {
            cout << "Invalid position, that tile is not empty!" << endl;
        } else {
            cout << "You placed an " << playerSymbol << " at tile " << inputMoveRow << " " << inputMoveColumn << ". (" << inputMoveX + 1 << ", " << inputMoveY + 1 << ")" << endl << endl;

            board[inputMoveX][inputMoveY] = player;
            break;
        }
    } // end of valid move check error trap

}

/*
 * == Scoreboard ==
 * loading, updating, and printing scoreboard
*/

void loadScoreboard()
{
    try
    {
        ifstream inFile;
        inFile.open("./doc/scoreboard.txt",ios::in);

        inFile >> scoreboardWins;
        inFile >> scoreboardLosses;
        inFile >> scoreboardTies;

        inFile.close();

    } catch (exception X)
    { cout << "File Error! Could not LOAD SCOREBOARD." << endl; }

}

// --------------------------------------------------------------------------
void updateScoreboard(const int gameResult)
{
    try
    {
        // gameResult is the win, loss, or tie of a game.
        // 0: tie, 1: win, 2: loss
        switch (gameResult) {
        case 0:
            scoreboardTies++;
            break;
        case 1:
            scoreboardWins++;
            break;
        case 2:
            scoreboardLosses++;
            break;
        }

        ofstream outFile;
        outFile.open("./doc/scoreboard.txt",ios::out);

        // endl is delimiter
        outFile << scoreboardWins << endl;
        outFile << scoreboardLosses << endl;
        outFile << scoreboardTies;

        outFile.close();
    } catch (exception X)
    { cerr << "File Error! Could not UPDATE SCOREBOARD." << endl; }

}

// --------------------------------------------------------------------------
void printScoreboard()
{
    try
    {
        cout << "=============== \n" <<
                "SCOREBOARD" << endl;
        cout << "Wins: " << scoreboardWins << endl;
        cout << "Losses: " << scoreboardLosses << endl;
        cout << "Ties: " << scoreboardTies << endl;
        cout << "===============" << endl;
    }
    catch (exception X)
    { cerr << "File Error! Could not PRINT SCOREBOARD." << endl; }
}

// --------------------------------------------------------------------------
void resetScoreboard()
{
    try
    {
        ofstream outFile;
        outFile.open("./doc/scoreboard.txt",ios::out);

        outFile << 0 << endl;
        outFile << 0 << endl;
        outFile << 0 << endl;

        outFile.close();
    }
    catch (exception X)
    { cerr << "File Error! Could not RESET SCOREBOARD." << endl; }
}

void clearScreen()
{
#if defined(_WIN32)
    system("cls");
#elif defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}
