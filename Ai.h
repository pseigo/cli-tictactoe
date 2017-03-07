// Header ==> Function Declarations

#include <iostream>
#include <string>
#include <cstdlib> // rng
#include <time.h> // time

using namespace std;

#ifndef AI_H
#define AI_H

class Ai
{
    private:
        int currentPlayer;
        int difficulty; // 0: easy 1: medium 2: hard

    public:
        // Default Constructor
        Ai();

        // Overload Constructor
        Ai(int, int);
            // current player (1: X, 2: 0), difficulty (1-3)

        // Destructor
        ~Ai();

        // Accessor Functions
        void printConfig() const;
            // prints config, debug command

        bool checkValidMove(int board[3][3], const int inputMoveX, const int inputMoveY);

        bool checkFirstMove(int board[3][3]);
            // plays if playing first move, if board is empty

        void playMove(int board[3][3], const int player, const int inputMoveX, const int inputMoveY);
            // plays move on the board


};

#endif // AI_H
