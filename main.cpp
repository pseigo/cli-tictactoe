#include <iostream>

using namespace std;

void resetBoard(int board[][3]);   // resets all board values to 0 (blank)
void printBoard(int board[][3]);   // prints current board to screen
int checkWin();     // checks for 3 in a row



int main()
{
    int board[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

    bool gameRunning = 1,
        saveConfig = 0;

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

    return 0;
}

/*
 * == Board Functions ==
 * deals with board manipulation and output
*/

void resetBoard(int board[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // resets all values on board to 0
            board[i][j] = 0;
        }
    }
}

void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            switch (board[i][j]) {
            case 0:
                cout << " .";
                break;
            case 1:
                cout << " X";
                break;
            case 2:
                cout << " X";
                break;
            case 3:
                cout << " O";
                break;
            case 4:
                cout << " O";
                break;
            }

        }
        // new row
        cout << endl;
    }
}

int checkWin() {

}

/*
 * == AI Class and Methods ==
*/
