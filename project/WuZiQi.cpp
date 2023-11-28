#include<iostream>
#include<cctype>
#include<cstring>
#include<ctime>
using namespace std;

void GameBegin();
void BoardInit();
void BoardDisplay();
void PlayerTurn();
void BoardDestroy();
void wrong();
bool WinCheck();
void ComputerEasy();
bool isfull();

int mode, col, row, COL, ROW;
char** board;
struct {
    int y, x;
} full;

int main() {
    srand(time(0));
    int opera;
    while (true) {
        cout << "**********************\n"
            "*0.exit 1.easy 2.hard*\n"
            "**********************\n";
        if (cin >> opera) {
            switch (opera) {
            case 0: return 0;
            case 1: mode = 1; GameBegin(); break;
            case 2: mode = 0; GameBegin(); break;
            default: wrong();
            }
        }
        else {
            wrong();
            for (char ch = getchar(); ch != '\n'; );
        }
    }
}





void GameBegin() {
    BoardInit();
    while (true) {
        BoardDisplay();
        PlayerTurn();
        if (WinCheck()) {
            cout << "YOU WIN!" << endl;
            break;
        }
        if(isfull()) return;
        if (mode) ComputerEasy();
        BoardDisplay();
        if (WinCheck()) {
            cout << "YOU LOSE" << endl;
        }
        if(isfull()) return;
    }
    BoardDestroy();
}

void BoardInit() {
    cout << "Please enter the size of the board (row,col)" << endl;
    cin >> ROW >> COL;
    board = new char* [ROW + 1];
    for (int i = 0; i <= ROW; i++) {
        board[i] = new char[COL + 1];
        memset(board[i], ' ', COL + 1);
    }
    full.y = full.x = 1;
}

void BoardDisplay() {
    cout << endl;
    for (int i = 0; i <= COL; i++) cout << "***";
    cout << endl;
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            cout << " " << board[i][j] << " ";
            if (j < COL) cout << '|';
            else cout << endl;
        }
        for (int j = 1; j <= COL; j++) {
            cout << "---";
            if (j < COL) cout << '+';
            else cout << endl;
        }
    }
    for (int i = 0; i <= COL + 1; i++) cout << "***";
    cout << endl;
}

void PlayerTurn() {
    cout << "Enter X,Y coordinates for your move (row, col)" << endl;
    while (true) {
        if (cin >> row >> col) {
            if (board[row][col] != ' ') {
                wrong();
                continue;
            }
            board[row][col] = '*';
            return;
        }
        else {
            wrong();
            for (char ch = getchar(); ch != '\n'; );
        }
    }
}

void ComputerEasy() {
    while (true) {
        col = rand() % COL;
        row = rand() % ROW;
        if (board[row][col] != ' ') continue;
        board[row][col] = '#';
        break;
    }
}

bool WinCheck() {
    int cnt[4] = { 0 };
    for (int i = -4; i <= 4; i++) {
        if (row + i > 0 && row + i <= ROW && board[row + i][col] == board[row][col]) cnt[0]++; else cnt[0] = 0;
        if (col + i > 0 && col + i <= COL && board[row][col + i] == board[row][col]) cnt[1]++; else cnt[1] = 0;
        if (row + i > 0 && row + i <= ROW && col + i > 0 && col + i <= COL && board[row + i][col + i] == board[row][col]) cnt[2]++; else cnt[2] = 0;
        if (row + i > 0 && row + i <= ROW && col - i > 0 && col - i <= COL && board[row + i][col - i] == board[row][col]) cnt[3]++; else cnt[3] = 0;
        for (int j = 0; j < 4; j++) if (cnt[j] == 5) return true;
    }
    return false;
}

void BoardDestroy() {
    for (int i = 0; i < ROW; i++) {
        delete[] board[i];
    }
    delete[] board;
    board = nullptr;
}
void wrong() {
    cout << "Invalid input!" << endl << "Please enter again" << endl;
}

bool isfull() {
    while(board[full.y][full.x] != ' ') {
        if(full.x > COL) {
            full.y++;
            full.x = 1;
        }
        if(full.y == ROW && full.x == COL) {
            cout << "The board is full";
            return false;
        }
        full.x++;
    }
    return false;
}