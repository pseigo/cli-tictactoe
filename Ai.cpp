// Function Definitions

#include "Ai.h"

Ai::Ai() {
    currentPlayer = 2;
    enemyPlayer = 1;
    difficulty = 2;
    playerSymbol = 'O';
}

// --------------------------------------------------------------------------
Ai::Ai(int configPlayer, int configDifficulty) {
    currentPlayer = configPlayer;
    difficulty = configDifficulty;

    if (currentPlayer == 1) {
        playerSymbol = 'X';
    } else {
        playerSymbol = 'O';
    }

    if (currentPlayer == 1) {
        enemyPlayer = 2;
    } else {
        enemyPlayer = 1;
    }
}

// --------------------------------------------------------------------------
Ai::~Ai()
{

}

// --------------------------------------------------------------------------
void Ai::printConfig() const {
    cout << "The AI is playing as player " << currentPlayer << endl;
    cout << "The AI is set to difficulty " << difficulty << endl;
}

// --------------------------------------------------------------------------
bool Ai::difficultyCheck(string aiMove)
{
    int percentConfig = 1;
    if (aiMove == "playWinningMove") percentConfig = 0;
    else if (aiMove == "blockWinningMove") percentConfig = 0;
    // else if (aiMove == "playForkMove") percentConfig = 3;
    // else if (aiMove == "blockForkMove") percentConfig = 3;
    else if (aiMove == "playCenterMove") percentConfig = 1;
    else if (aiMove == "playOppositeCornerMove") percentConfig = 2;
    else if (aiMove == "playCornerMove") percentConfig = 2;
    else if (aiMove == "playSideMove") percentConfig = 1;
    else cout << "AI difficulty check FAILED. Invalid move name." << endl;

    int easyPercent,
        mediumPercent,
        hardPercent;

    switch (percentConfig)
    {
    case 0: // playWinningMove, blockWinningMove
        easyPercent = 40;
        mediumPercent = 70;
        hardPercent = 95;
    case 1: // playCenterMove, playSideMove
        easyPercent = 20;
        mediumPercent = 65;
        hardPercent = 85;
    case 2: // playOppositeCornerMove, playCornerMove
        easyPercent = 10;
        mediumPercent = 60;
        hardPercent = 80;
    case 3: // playForkMove, blockForkMove
        easyPercent = 10;
        mediumPercent = 35;
        hardPercent = 70;
    }


    int difficultyRng = rand() % (100 - 1 + 1) + 1;
    switch (difficulty)
    {
    case 1:
        if (difficultyRng > easyPercent)
            return false;
    case 2:
        if (difficultyRng > mediumPercent)
            return false;
    case 3:
        if (difficultyRng > hardPercent)
            return false;
    default:
        break; // nightmare or no difficulty
    }

    return true;
}

// --------------------------------------------------------------------------
bool Ai::isValidMove(const int board[3][3], int inputMoveX, int inputMoveY) {
    if (board[inputMoveX][inputMoveY] == 0) {
        return true;
    }

    // invalid move
    return false;
}

// --------------------------------------------------------------------------
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

// --------------------------------------------------------------------------
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

// --------------------------------------------------------------------------
bool Ai::playWinningMove(int board[3][3]) {
    if (!difficultyCheck("playWinningMove"))
        return false; // difficulty check failed, move skipped

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

    return false;
}

// --------------------------------------------------------------------------
bool Ai::blockWinningMove(int board[3][3])
{
    if (!difficultyCheck("blockWinningMove"))
        return false; // difficulty check failed, move skipped

    // checks horizontal rows for win
    for (int row = 0; row < 3; ++row) {

        // X X - (horizontal)
        if (board[row][0] == enemyPlayer && board[row][1] == enemyPlayer && board[row][2] == 0) {
            playMove(board, row, 2);
            return true;
        }

        // X - X (horizontal)
        if (board[row][0] == enemyPlayer && board[row][2] == enemyPlayer && board[row][1] == 0) {
            playMove(board, row, 1);
            return true;
        }

        // - X X (horizontal)
        if (board[row][1] == enemyPlayer && board[row][2] == enemyPlayer && board[row][0] == 0) {
            playMove(board, row, 0);
            return true;
        }
    }

    // checks vertical columns for win
    for (int column = 0; column < 3; ++column) {

        // X X - (vertical)
        if (board[0][column] == enemyPlayer && board[1][column] == enemyPlayer && board[2][column] == 0) {
            playMove(board, 2, column);
            return true;
        }

        // X - X (vertical)
        if (board[0][column] == enemyPlayer && board[2][column] == enemyPlayer && board[1][column] == 0) {
            playMove(board, 1, column);
            return true;
        }

        // - X X (vertical)
        if (board[1][column] == enemyPlayer && board[2][column] == enemyPlayer && board[0][column] == 0) {
            playMove(board, 0, column);
            return true;
        }

    }

    // top left to bottom right
    /*  X - -
     *  - X -
     *  - - -  */
    if (board[0][0] == enemyPlayer && board[1][1] == enemyPlayer && board[2][2] == 0) {
        playMove(board, 2, 2);
        return true;
    }

    /*  X - -
     *  - - -
     *  - - X  */
    if (board[0][0] == enemyPlayer && board[2][2] == enemyPlayer && board[1][1] == 0) {
        playMove(board, 1, 1);
        return true;
    }

    /*  - - -
     *  - X -
     *  - - X  */
    if (board[1][1] == enemyPlayer && board[2][2] == enemyPlayer && board[0][0] == 0) {
        playMove(board, 0, 0);
        return true;
    }

    // top right to bottom left
    /*  - - X
     *  - X -
     *  - - -  */
    if (board[0][2] == enemyPlayer && board[1][1] == enemyPlayer && board[2][0] == 0) {
        playMove(board, 2, 0);
        return true;
    }

    /*  - - X
     *  - - -
     *  X - -  */
    if (board[0][2] == enemyPlayer && board[2][0] == enemyPlayer && board[1][1] == 0) {
        playMove(board, 1, 1);
        return true;
    }

    /*  - - -
     *  - X -
     *  X - -  */
    if (board[1][1] == enemyPlayer && board[2][0] == enemyPlayer && board[0][2] == 0) {
        playMove(board, 0, 2);
        return true;
    }

    return false;
}

/*
* Unimplemented functions

bool Ai::playForkMove(int board[3][3]);

bool Ai::blockForkMove(int board[3][3]);

*/

// --------------------------------------------------------------------------
bool Ai::playCenterMove(int board[3][3]) {
    if (!difficultyCheck("playCenterMove"))
        return false; // difficulty check failed, move skipped

    if (isValidMove(board, 1, 1)) {
        playMove(board, 1, 1);
        return true;
    }
    return false;
}

// --------------------------------------------------------------------------
bool Ai::playOppositeCornerMove(int board[3][3])
{
    if (!difficultyCheck("playOppositeCornerMove"))
        return false; // difficulty check failed, move skipped

    if (board[0][0] == enemyPlayer) {
        if (isValidMove(board, 2, 2)) {
            playMove(board, 2, 2);
            return true;
        }
    }

    if (board[0][2] == enemyPlayer) {
        if (isValidMove(board, 2, 0)) {
            playMove(board, 2, 0);
            return true;
        }
    }

    if (board[2][0] == enemyPlayer) {
        if (isValidMove(board, 0, 2)) {
            playMove(board, 0, 2);
            return true;
        }
    }

    if (board[2][2] == enemyPlayer) {
        if (isValidMove(board, 0, 0)) {
            playMove(board, 0, 0);
            return true;
        }
    }

    return false;
}

// --------------------------------------------------------------------------
bool Ai::playCornerMove(int board[3][3])
{
    if (!difficultyCheck("playCornerMove"))
        return false; // difficulty check failed, move skipped

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
}

// --------------------------------------------------------------------------
bool Ai::playSideMove(int board[3][3]) {
    if (!difficultyCheck("playSideMove"))
        return false; // difficulty check failed, move skipped

    const int numLocations = 4;
    vector<pair<int, int> > locations;
    locations.push_back(make_pair(0, 1));
    locations.push_back(make_pair(1, 0));
    locations.push_back(make_pair(1, 2));
    locations.push_back(make_pair(2, 1));

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
        // all sides were occupied
        return false;
    }
}

// --------------------------------------------------------------------------
bool Ai::playRandomMove(int board[3][3])
{
    const int numLocations = 9;
    vector<pair<int, int> > locations;
    locations.push_back(make_pair(0, 0));
    locations.push_back(make_pair(0, 1));
    locations.push_back(make_pair(0, 2));
    locations.push_back(make_pair(1, 0));
    locations.push_back(make_pair(1, 1));
    locations.push_back(make_pair(1, 2));
    locations.push_back(make_pair(2, 0));
    locations.push_back(make_pair(2, 1));
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
        // all locations were occupied, board is full!
        cerr << "Unable to play, board is full! (randomMove)" << endl;
        return false;
    }
}
