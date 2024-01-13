#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function prototypes
void printBoard(const vector<vector<char>> &board);
bool isMoveValid(const vector<vector<char>> &board, int row, int col);
bool isBoardFull(const vector<vector<char>> &board);
char checkWinner(const vector<vector<char>> &board);
void playerMove(vector<vector<char>> &board);
void computerMove(vector<vector<char>> &board);

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 Tic-Tac-Toe board

    int currentPlayer = 1; // 1 for user, 2 for computer
    char winner = ' ';

    srand(static_cast<unsigned>(time(nullptr))); // Seed for random number generation

    while (true)
    {
        printBoard(board);

        if (currentPlayer == 1)
        {
            playerMove(board);
        }
        else
        {
            computerMove(board);
        }

        // Check for a winner
        winner = checkWinner(board);
        if (winner != ' ')
        {
            printBoard(board);
            if (winner == 'X')
            {
                cout << "You win!" << endl;
            }
            else
            {
                cout << "Computer wins!" << endl;
            }
            break;
        }

        // Check for a tie
        if (isBoardFull(board))
        {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

void printBoard(const vector<vector<char>> &board)
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl
             << "-------------" << endl;
    }
}

bool isMoveValid(const vector<vector<char>> &board, int row, int col)
{
    // Check if the cell is empty and within the valid range
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool isBoardFull(const vector<vector<char>> &board)
{
    // Check if the board is full (no empty cells)
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

char checkWinner(const vector<vector<char>> &board)
{
    // Check rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0]; // Row win
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[0][i]; // Column win
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[0][0]; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[0][2]; // Diagonal win (top-right to bottom-left)
    }
    return ' '; // No winner yet
}

void playerMove(vector<vector<char>> &board)
{
    int row, col;
    cout << "Your turn. Enter row (0-2) and column (0-2) separated by space: ";
    cin >> row >> col;

    while (!isMoveValid(board, row, col))
    {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }

    board[row][col] = 'X';
}

void computerMove(vector<vector<char>> &board)
{
    cout << "Computer's turn:" << endl;

    int row, col;

    // Generate random moves until a valid one is found
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (!isMoveValid(board, row, col));

    board[row][col] = 'O';
}
