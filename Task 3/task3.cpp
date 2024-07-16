#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char player;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), player('X') {}

    void showBoard() {
        cout << "Current board state:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--+---+--\n";
        }
    }

    void switchPlayer() {
        player = (player == 'X') ? 'O' : 'X';
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = player;
        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    void resetBoard() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        player = 'X';
    }

    void playGame() {
        while (true) {
            showBoard();
            int row, col;
            cout << "Player " << player << ", enter your move (row and column): ";
            cin >> row >> col;
            if (makeMove(row - 1, col - 1)) {
                if (checkWin()) {
                    showBoard();
                    cout << "Player " << player << " wins!\n";
                    break;
                }
                if (checkDraw()) {
                    showBoard();
                    cout << "The game is a draw!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }

    bool playAgain() {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
};

int main() {
    TicTacToe game;
    do {
        game.playGame();
        game.resetBoard();
    } while (game.playAgain());

    cout << "Thank you for playing Tic-Tac-Toe!\n";
    return 0;
}
