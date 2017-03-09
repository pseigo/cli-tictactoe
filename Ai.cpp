// Function Definitions

#include "Ai.h"

Ai::Ai() {
    currentPlayer = 2;
    difficulty = 2;
    playerSymbol = 'O';
}

Ai::Ai(int configPlayer, int configDifficulty) {
    currentPlayer = configPlayer;
    difficulty = configDifficulty;

    if (currentPlayer == 1) {
        playerSymbol = 'X';
    } else {
        playerSymbol = 'O';
    }
}

Ai::~Ai()
{

}

void Ai::printConfig() const {
    cout << "The AI is playing as player " << currentPlayer << endl;
    cout << "The AI is set to difficulty " << difficulty << endl;
}

bool Ai::isValidMove(const int board[3][3], int inputMoveX, int inputMoveY) {
    if (board[inputMoveX][inputMoveY] == 0) {
        return true;
    }

    // invalid move
    return false;
}

bool Ai::isBoardEmpty(const int board[3][3])
{
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (board[row][column] != 0) {
                // found something other than 0, therefore board is not empty
                return false;
            }
        }
    }

    return true;
}

void Ai::playMove(int board[3][3], int inputMoveX, int inputMoveY)
{
    char gridMoveRow;
    int gridMoveColumn;

    // converts to readable grid coordinates for output
    switch (inputMoveX) {
    case 0:
        gridMoveRow = 'A';
        break;
    case 1:
        gridMoveRow = 'B';
        break;
    case 2:
        gridMoveRow = 'C';
        break;
    }

    gridMoveColumn = inputMoveY + 1;

    cout << "It's " << playerSymbol << "'s turn!" << endl;
    cout << "AI placed an " << playerSymbol << " at tile " << gridMoveRow << " " << gridMoveColumn << ". (" << inputMoveX + 1 << ", " << inputMoveY + 1 << ")" << endl << endl;

    board[inputMoveX][inputMoveY] = currentPlayer;
}

// if functions return 1, end loop. if 0, keep going through list of priorites

bool Ai::playWinningMove(int board[3][3]) {
    bool winner = false;

    // checks horizontal rows for win
    for (int row = 0; row < 3; ++row) {

        // X X - (horizontal)
        if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == 0) {
            playMove(board, row, 2);
            return true;
        }

        // X - X (horizontal)
        if (board[row][0] == currentPlayer && board[row][2] == currentPlayer && board[row][1] == 0) {
            playMove(board, row, 1);
            return true;
        }

        // - X X (horizontal)
        if (board[row][1] == currentPlayer && board[row][2] == currentPlayer && board[row][0] == 0) {
            playMove(board, row, 0);
            return true;
        }
    }

    if (winner == false) {
        // checks vertical columns for win
        for (int column = 0; column < 3; ++column) {

            // X X - (vertical)
            if (board[0][column] == currentPlayer && board[1][column] == currentPlayer && board[2][column] == 0) {
                playMove(board, 2, column);
                return true;
            }

            // X - X (vertical)
            if (board[0][column] == currentPlayer && board[2][column] == currentPlayer && board[1][column] == 0) {
                playMove(board, 1, column);
                return true;
            }

            // - X X (vertical)
            if (board[1][column] == currentPlayer && board[2][column] == currentPlayer && board[0][column] == 0) {
                playMove(board, 0, column);
                return true;
            }

        }
    }

    if (winner == 0) {
        // top left to bottom right
        /*  X - -
            *  - X -
            *  - - -  */
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == 0) {
            playMove(board, 2, 2);
            return true;
        }

        /*  X - -
            *  - - -
            *  - - X  */
        if (board[0][0] == currentPlayer && board[2][2] == currentPlayer && board[1][1] == 0) {
            playMove(board, 1, 1);
            return true;
        }

        /*  - - -
            *  - X -
            *  - - X  */
        if (board[1][1] == currentPlayer && board[2][2] == currentPlayer && board[0][0] == 0) {
            playMove(board, 0, 0);
            return true;
        }

        // top right to bottom left
        /*  - - X
            *  - X -
            *  - - -  */
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == 0) {
            playMove(board, 2, 0);
            return true;
        }

        /*  - - X
            *  - - -
            *  X - -  */
        if (board[0][2] == currentPlayer && board[2][0] == currentPlayer && board[1][1] == 0) {
            playMove(board, 1, 1);
            return true;
        }

        /*  - - -
            *  - X -
            *  X - -  */
        if (board[1][1] == currentPlayer && board[2][0] == currentPlayer && board[0][2] == 0) {
            playMove(board, 0, 2);
            return true;
        }
    }

    return false;
}

bool Ai::playFirstMove(int board[3][3])
{
    if (!isBoardEmpty(board)) {
        return false;
    }

    const int numLocations = 4;
    vector<pair<int, int> > locations;
    locations.push_back(make_pair(0, 0));
    locations.push_back(make_pair(0, 2));
    locations.push_back(make_pair(2, 0));
    locations.push_back(make_pair(2, 2));

    random_shuffle(locations.begin(), locations.end());

    int i = 0;
    for (; i < numLocations; ++i) {
        if (isValidMove(board, locations[i].first, locations[i].second)) {
            // do the move
            playMove(board, locations[i].first, locations[i].second);
            return true;
        } // else do nothing & try the next move
    }

    if (i == numLocations) {
        // all corners were occupied
        return false;
    }

    /* old, inefficient method
    int inputMoveX,
        inputMoveY,
        rngMin = 1,
        rngMax = 4;
    bool moveFailure = true;

    int lastCaseAttempt;
    int caseFail[4] = {0, 0, 0 ,0};

    while (moveFailure) {
        switch (rand() % (rngMax - rngMin + 1) + rngMin) {
            case 1:
                // cout << "top left" << endl;
                inputMoveX = 0, inputMoveY = 0;

                lastCaseAttempt = 0;
                break;
            case 2:
                // cout << "top right" << endl;
                inputMoveX = 0, inputMoveY = 2;

                lastCaseAttempt = 1;
                break;
            case 3:
                // cout << "bottom left" << endl;
                inputMoveX = 2, inputMoveY = 0;

                lastCaseAttempt = 2;
                break;
            case 4:
                // cout << "bottom right" << endl;
                inputMoveX = 2, inputMoveY = 2;

                lastCaseAttempt = 3;
                break;
        }

        // if move was valid, break out of loop. if not, mark that case as invalid.
        if (checkValidMove(board, inputMoveX, inputMoveY)) {
            playMove(board, currentPlayer, inputMoveX, inputMoveY);
            moveFailure = false;
        } else {
            caseFail[lastCaseAttempt] = 1;
        }

        // if every case is invalid, return false to indicate failure
        bool caseAllFail = true;
        while (true) {
            for (int caseCount = 0; caseCount < 4; caseCount++) {
                if (caseFail[caseCount] == 0) {
                    caseAllFail = false;
                    break;
                }
            }

            if (caseAllFail) {
                return false;
            } else {
                break;
            }
        }

    }

    return true;
    */
}

