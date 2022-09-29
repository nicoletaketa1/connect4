#include <iostream>
#include <stdlib.h>

using namespace std;

char board[6][7] = {{' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '} };
char player = 'x';
int last_col, last_row;
char last_player = 'x';

void reset_board(){
    for (int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++){
            board[j][i] = ' ';
        }
    }
}

void display_board(){
    cout << "Player 1: X\t\tPlayer 2:O\n";
    cout << "---------------------------------------------\n";
    cout << "  |  0  |  1  |  2  |  3  |  4  |  5  |  6  |\n";
    cout << "0 |  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |  "<<board[0][3]<<
    "  |  "<<board[0][4]<<"  |  "<<board[0][5]<<"  |  "<<board[0][6]<<"  |\n";
    cout << "1 |  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |  "<<board[1][3]<<
         "  |  "<<board[1][4]<<"  |  "<<board[1][5]<<"  |  "<<board[1][6]<<"  |\n";
    cout << "2 |  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |  "<<board[2][3]<<
         "  |  "<<board[2][4]<<"  |  "<<board[2][5]<<"  |  "<<board[2][6]<<"  |\n";
    cout << "3 |  "<<board[3][0]<<"  |  "<<board[3][1]<<"  |  "<<board[3][2]<<"  |  "<<board[3][3]<<
         "  |  "<<board[3][4]<<"  |  "<<board[3][5]<<"  |  "<<board[3][6]<<"  |\n";
    cout << "4 |  "<<board[4][0]<<"  |  "<<board[4][1]<<"  |  "<<board[4][2]<<"  |  "<<board[4][3]<<
         "  |  "<<board[4][4]<<"  |  "<<board[4][5]<<"  |  "<<board[4][6]<<"  |\n";
    cout << "5 |  "<<board[5][0]<<"  |  "<<board[5][1]<<"  |  "<<board[5][2]<<"  |  "<<board[5][3]<<
         "  |  "<<board[5][4]<<"  |  "<<board[5][5]<<"  |  "<<board[5][6]<<"  |\n";
    cout << "---------------------------------------------\n\n";

}


void turn(){
    if (player == 'x'){
        cout << "Player 1: choose a column: ";
    }else {
        cout << "Player 2: choose a column: ";
    }
    int column;
    cin >> column;
    int x = 5;
/*
    switch(move){
        case 0: column = 0; break;
        case 1: column = 1; break;
        case 2: column = 2; break;
        case 3: column = 3; break;
        case 4: column = 4; break;
        case 5: column = 5; break;
        case 6: column = 6; break;
        default:
            cout << "Invalid move.\n";
    }
*/
    while(board[x][column] != ' ') {
        x--;
    }
    board[x][column] = player;

    last_col = column;
    last_row = x;
    display_board();
    last_player = player;
    if (player == 'x')
        player = 'o';
    else if (player == 'o')
        player = 'x';
    return;

}


bool check_win(){
    // check across
    for(int j = 0; j < 4; j++){
        for(int i = 0; i < 7; i++){
            if(board[i][j] == last_player && board[i][j+1] == last_player && board[i][j+2] == last_player && board[i][j+3] == last_player) {
                return false; // you won across
            }
        }
    }

    // check vertical
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 6; j++){
            if(board[i][j] == last_player && board[i+1][j] == last_player && board[i+2][j] == last_player && board[i+3][j] == last_player) {
                return false;
            }
        }
    }

    for(int i = 3; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if(board[i][j] == last_player && board[i-1][j+1] == last_player && board[i-2][j+2] == last_player && board[i-3][j+3] == last_player) {
                return false;
            }
        }
    }

    for (int i = 3; i < 6; i++){
        for (int j = 3; j < 6; j++){
            if(board[i][j] == last_player && board[i-1][j-1] == last_player && board[i-2][j-2] == last_player && board[i-3][j-3] == last_player){
                return false;
            }
        }
    }
    return true;
}


int main() {
    bool play = true;
    int temp;
    while(play) {
        cout << "\t\tCONNECT 4\n";
        while (check_win()) {
            display_board();
            turn();
        }
        if (last_player == 'x') cout << "Player 1 has won the game\n";
        else if (last_player == 'o') cout << "Player 2 has won the game\n";

        cout << "\nPlay Again? Yes[1] No[2]: ";
        cin >> temp;
        if(temp == 1) {
            play = true;
            reset_board();
        }
        if(temp == 2) play = false;
    }
}

