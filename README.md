# Tic Tac Toe - Basic Console Game in C++
A console based Tic Tac Toe game with moderate AI. Written for CS 15 course.

## Available Functions (wip)
### Board
| Func. # |                   Description                  |      Function Syntax      |       Arguments       |       Returns       |
|:-------:|:----------------------------------------------:|:-------------------------:|:---------------------:|:-------------------:|
|    1    | Reset board to 0 state                         | `resetBoard(board);`      | board array           |                     |
|    2    | Print board to screen                          | `printBoard(board)`       | board array           |                     |
|  [3](#board3) | Check for 3 in a row win                       | `checkWin(board);`        | board array           | 0/1/2: none/X's/O's |
|    4    | Ask for move, check if valid, and update array | `playMove(board, 1 or 2);`| board array, player # |                     |


<a name="board3">**3. checkWin(board);**</a>  
Run this to check for win.

```c++
winner = checkWin(board);
if (winner == 1) {
        cout << "Three in a row, X wins!" << endl;
        break;
} else if (winner == 2) {
        cout << "Three in a row, O wins!" << endl;
        break;
} else {
        winner = 0;
}
```

### Scoreboard
| Func. # | Description                                                                                                                                                     |  Function Syntax                 | Arguments                   |
|---------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------|-----------------------------|
| 1       | Writes from doc/scoreboard.txt to global variables. If file doesn't exist, variables remain initialized at 0.                                                   | `loadScoreboard();`              |                             |
| 2       | Takes input to determine game end state (win/loss/tie), increments appropriate global variable, and updates doc/scoreboard.txt file with current global values. | `updateScoreboard(0 or 1 or 2);` | 0/1/2: PC wins/PC loses/tie |
| 3       | Prints global variables for the scoreboard                                                                                                                      | `printScoreboard();`             |                             |
