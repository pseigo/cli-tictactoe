// Function Definitions

#include "Ai.h"

Ai::Ai() {
    currentPlayer = 2;
    difficulty = 2;
}

Ai::Ai(int configPlayer, int configDifficulty) {
    currentPlayer = configPlayer;
    difficulty = configDifficulty;
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

void Ai::playMove(int board[3][3], int player, int inputMoveX, int inputMoveY)
{
    char playerSymbol;
    char gridMoveRow;
    int gridMoveColumn;

    if (player == 1) {
        playerSymbol = 'X';
    } else {
        playerSymbol = 'O';
    }

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
    cout << "AI placed an " << playerSymbol << " at tile " << gridMoveRow << gridMoveColumn << ". (" << inputMoveX + 1 << ", " << inputMoveY + 1 << ")" << endl << endl;

    board[inputMoveX][inputMoveY] = player;
}

// if functions return 1, end loop. if 0, keep going through list of priorites

bool Ai::playFirstMove(int board[3][3], int currentPlayer)
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
            playMove(board, currentPlayer, locations[i].first, locations[i].second);
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

