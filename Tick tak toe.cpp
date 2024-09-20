#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';

void displayBoard() {
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---------" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---------" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void playMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = player;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    return false;
}

int main() {
    int move;
    do {
        displayBoard();
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        playMove(move);
        if (checkWin()) {
            displayBoard();
            cout << "Player " << player << " wins!" << endl;
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    } while (true);
    return 0;
}