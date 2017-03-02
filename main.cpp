#include <iostream>

using namespace std;

void resetBoard(int board[3][3]);   // resets all board values to 0 (blank)
void printBoard(const int board[3][3]);   // prints current board to screen
int checkWin(const int board[3][3]);     // checks for 3 in a row
void playMove(const int board[3][3], const int player);


int main()
{
    int board[3][3] = { {2, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    bool gameRunning = 1,
        saveConfig = 0;
    // temp testing variables
    int winner = 0;

    while (int pie = 1) {
        playMove(board, 1);
    }


    // test for winner
    winner = checkWin(board);
    if (winner == 1) {
        cout << "Three in a row, X wins!" << endl;
        //break;
    } else if (winner == 2) {
        cout << "Three in a row, O wins!" << endl;
        //break;
    } else {
        winner = 0;
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
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {

            switch (board[row][column]) {
            case 0:
                cout << " .";
                break;
            case 1:
                cout << " X";
                break;
            case 2:
                cout << " O";
                break;
            }

        }
        // new row
        cout << endl;
    }
}

int checkWin(const int board[3][3]) {
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

    return winner;
}

void playMove(const int board[3][3], const int player) {
    int inputMove,
        inputMoveRow,
        inputMoveColumn;
    char playerSymbol;

    if (player == 1) {
        playerSymbol = 'X';
    } else {
        playerSymbol = 'O';
    }

    cout << "Where would you like to play? (1-9)" << endl;

    for (;;) {
        for (;;) {
            cout << ">> ";
            cin >> inputMove;
            cout << endl;

            if (!cin.good() || inputMove < 1 || inputMove > 9) {
                cout << "Invalid position! Input must be from 1-9." << endl;
                cin.clear();
                cin.ignore(128, '\n');
            } else {
                cin.ignore(128, '\n');
                break;
            }
        } // end of input error trap

        switch (inputMove) {
        case 1:
            inputMoveRow = 0;
            inputMoveColumn = 0;
            break;
        case 2:
            inputMoveRow = 0;
            inputMoveColumn = 1;
            break;
        case 3:
            inputMoveRow = 0;
            inputMoveColumn = 2;
            break;
        case 4:
            inputMoveRow = 1;
            inputMoveColumn = 0;
            break;
        case 5:
            inputMoveRow = 1;
            inputMoveColumn = 1;
            break;
        case 6:
            inputMoveRow = 1;
            inputMoveColumn = 2;
            break;
        case 7:
            inputMoveRow = 2;
            inputMoveColumn = 0;
            break;
        case 8:
            inputMoveRow = 2;
            inputMoveColumn = 1;
            break;
        case 9:
            inputMoveRow = 2;
            inputMoveColumn = 2;
            break;
        }

        if (board[inputMoveRow][inputMoveColumn] != 0) {
            cout << "Invalid position, that tile is not empty!" << endl;
        } else {
            cout << "You placed an " << playerSymbol << " at tile " << inputMove << ". (" << inputMoveRow + 1 << ", " << inputMoveColumn + 1 << ")" << endl << endl;
            break;
        }
    } // end of valid move check error trap

}

/*
 * == AI Class and Methods ==
*/
