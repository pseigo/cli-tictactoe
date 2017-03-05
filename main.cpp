#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream> // scoreboard file io

using namespace std;

// Globals
int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
int scoreboardWins = 0,
    scoreboardLosses = 0,
    scoreboardTies = 0;

// Function Prototypes
void resetBoard(int board[3][3]);   // resets all board values to 0 (blank)
void printBoard(const int board[3][3]);   // prints current board to screen
bool checkWin(const int board[3][3]);     // checks for 3 in a row
void playMove(int board[3][3], const int player);

void loadScoreboard();      // loads current values from ./doc/scoreboard.txt to global variables
void updateScoreboard(const int gameResult);    // 0: win, 1: losses, 2: ties
void printScoreboard();
void resetScoreboard();     // reset scoreboard to 0

// --------------------------------------------------------------------------
int main()
{
    bool gameRunning = 1,
        saveConfig = 0;

    loadScoreboard();   // should this be loaded at launch, or before each win/loss/tie/scoreboard view?

    // temp testing variables
    int winner = 0;
    int round = 0;


    printBoard(board);

    while (int pie = 1) {
        playMove(board, 1);
        system("cls");  // clear old board and replace with updated board
        printBoard(board);

        if (checkWin(board)) {
            break;
        }

        round++;
        if (round > 8) {
            cout << "Game over, it's a tie!" << endl;
            updateScoreboard(2);
            printScoreboard();
            break;
        }

        // PLAYER 2
        playMove(board, 2);
        system("cls");  // clear old board and replace with updated board
        printBoard(board);

        if (checkWin(board)) {
            break;
        }

        round++;
        if (round > 8) {
            cout << "Game over, it's a tie!" << endl;
            updateScoreboard(2);
            printScoreboard();
            break;
        }
    }


    /* testing functions rn

    // ## START OF gameRunning main loop
    do {
        int choicePcAi,  // 1: pc/ai, 2: pc/pc
            choicePcOrder, // 1: pc 1, 2: pc 2, 3: random
            choicePcSymbol; // 1: X (1/2), 2: O (3/4)

        cout << "####################### \n"
                "Welcome to Tic Tac Toe! \n"
                "Before you play, please select your options. \n"
                "Entering '1' will select choice 1, while entering '2' will select choice 2. \n"
                << endl;

        cout << "Play with against a computer (PC vs AI) or a friend (PC vs PC)? \n"
                "\t1: PC vs AI    2: PC vs PC" << endl;

        for (;;) {
            cout << ">> ";
            cin >> choicePcAi;
            cout << endl;
            if (!cin.good() || (choicePcAi != 1 && choicePcAi != 2) ) {
                cout << "Invalid option. Choices are 1 and 2." << endl;
                cin.clear();
                cin.ignore
                (128, '\n');
            } else {
                break;
            }
        }

        // skip order of play question and symbol if playing PC/PC
        if (choicePcAi == 1) {
            cout << "Do you want to play first, second, or choose randomly? \n"
                    "The second player will be given the opposite if you choose \n"
                    "option 1 or 2. \n"
                    "\t1: Play first    2: Play second    3: Choose randomly" << endl;

            for (;;) {
                cout << ">> ";
                cin >> choicePcOrder;
                cout << endl;
                if (!cin.good() || (choicePcOrder != 1 && choicePcOrder != 2 && choicePcOrder != 3) ) {
                    cout << "Invalid option. Choices are 1, 2 or 3." << endl;
                    cin.clear();
                    cin.ignore
                    (128, '\n');
                } else {
                    break;
                }
            }

            cout << "Do you want to play as X or O? \n"
                    "\t1: X    2: O" << endl;

            for (;;) {
                cout << ">> ";
                cin >> choicePcSymbol;
                cout << endl;
                if (!cin.good() || (choicePcSymbol != 1 && choicePcSymbol != 2) ) {
                    cout << "Invalid option. Choices are 1 and 2." << endl;
                    cin.clear();
                    cin.ignore
                    (128, '\n');
                } else {
                    break;
                }
            }
        }
        // END OF CONFIG

        // ## START OF saveConfig loop
        do {

        // game variables init
        resetBoard(board);
        int winner = 0;


        // pc or ai? 1: pc/ai, 2: pc/pc
        if (choicePcAi == 2) {
            // pc/pc loop
            cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
            cout << "pc/pc" << endl;

        } else {    // pc/ai

            // Who goes first?
            if (choicePcOrder == 1) {   // pc goes first

                // What symbol is PC?
                if (choicePcSymbol == 1) {  // pc is X (1)
                    // pc is X (1)
                    // assign O to AI (3)
                    // ## START LOOP: pc/ai, pc goes first, pc is X

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, pc goes first, pc is X" << endl;


                } else {    // pc is O (3)
                    // pc is O (3)
                    // assign X to AI (1)
                    // ## START LOOP: pc/ai, pc goes first, pc is O

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, pc goes first, pc is O" << endl;
                }

            } else if (choicePcOrder == 2) {    // ai goes first

                // What symbol is PC?
                if (choicePcSymbol == 1) {  // pc is X (1)
                    // pc is X (1)
                    // assign O to AI (3)
                    // ## START LOOP: pc/ai, ai goes first, pc is X

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, ai goes first, pc is X" << endl;

                } else {    // pc is O (3)
                    // pc is O (3)
                    // assign X to AI (1)
                    // ## START LOOP: pc/ai, ai goes first, pc is O

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, ai goes first, pc is O" << endl;
                }

            } else {    // random order

                // What symbol is PC?
                if (choicePcSymbol == 1) {  // pc is X (1)
                    // pc is X (1)
                    // assign O to AI (3)
                    // ## START LOOP: pc/ai, order is random, pc is X

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, order is random, pc is X" << endl;

                    // random play order loop #1


                    // random play order loop #2


                } else {    // pc is O (3)
                    // pc is O (3)
                    // assign X to AI (1)
                    // ## START LOOP: pc/ai, order is random, pc is O

                    cout << "PATH NOT YET IMPLEMENTED. \nIntended purpose: ";
                    cout << "pc/ai, order is random, pc is O" << endl;

                    // random play order loop #1


                    // random play order loop #2


                }

            } // end of 'Who goes first?' branch
        } // end of pc/ai branch


        // END OF GAME. CHECK IF WANT TO PLAY AGAIN
        gameRunning = 0;    // 0: quit game    1: replay game

        // if gameRunning = 0, make saveConfig = 0 because you want the game to end.
        if (gameRunning == 0) {
            saveConfig = 0;
        } else {
            // ask to save config. 0: do not save config    1: save config, skip setup process
            saveConfig = 0;
        }

        } while (saveConfig);
    } while (gameRunning);
    */

    return 0;
}

/*
 * == Board Functions ==
 * deals with board manipulation and output
*/

void resetBoard(int board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // resets all values on board to 0
            board[i][j] = 0;
        }
    }
}

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
            }

        }
        // new row
        cout << endl;
    }
    cout << endl;
}

// --------------------------------------------------------------------------
bool checkWin(const int board[3][3])
{
    int winner = 0;

    // checks horizontal rows for win
    for (int row = 0; row < 3; ++row) {
        // check if all 3 are == 1 or 2. if true, break and return 1 for winner 1 and 2 for winner 2. else 0 for no win.
        if ( (board[row][0] == 1 && board[row][1] == 1 && board[row][2] == 1) ) {
            winner = 1;
            break;
        } else if ( (board[row][0] == 2 && board[row][1] == 2 && board[row][2] == 2) ) {
            winner = 2;
            break;
        }
    }

    if (winner == 0) {
        // checks horizontal rows for win
        for (int column = 0; column < 3; ++column) {
            // check if all 3 are == 1 or 2. if true, break and return 1 for winner 1 and 2 for winner 2. else 0 for no win.
            if ( (board[0][column] == 1 && board[1][column] == 1 && board[2][column] == 1) ) {
                winner = 1;
                break;
            } else if ( (board[0][column] == 2 && board[1][column] == 2 && board[2][column] == 2) ) {
                winner = 2;
                break;
            }

        }
    }

    if (winner == 0) {
        // top left to bottom right
        if ( (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ) {
            winner = 1;
        } else if ( (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) ) {
            winner = 2;
        }

        // top right to bottom left
        if ( (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) ) {
            winner = 1;
        } else if ( (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) ) {
            winner = 2;
        }
    }

    switch (winner) {
    case 1: cout << "Three in a row, X wins!" << endl; break;
    case 2: cout << "Three in a row, O wins!" << endl; break;
    }

    if (winner) {
        updateScoreboard(winner);
        printScoreboard();
        return true;
    }

    return false;
}

// --------------------------------------------------------------------------
void playMove(int board[3][3], const int player)
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

    for (;;) {
        for (;;) {
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
            cout << "You placed an " << playerSymbol << " at tile " << inputMoveRow << inputMoveColumn << ". (" << inputMoveX + 1 << ", " << inputMoveY + 1 << ")" << endl << endl;

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
        // 0: win, 1: loss, 2: tie
        switch (gameResult) {
        case 0:
            scoreboardWins++;
            break;
        case 1:
            scoreboardLosses++;
            break;
        case 2:
            scoreboardTies++;
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
        cout << "Wins: " << scoreboardWins << endl;
        cout << "Losses: " << scoreboardLosses << endl;
        cout << "Ties: " << scoreboardTies << endl;
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

/*
 * == AI Class and Methods ==
*/
