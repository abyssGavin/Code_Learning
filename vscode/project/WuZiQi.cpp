#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
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
void ComputerHard();

int mode, col, row, COL, ROW, pre = 0;//prevent
char** board;
struct FULL{
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
    BoardDisplay();
    while (true) {
        PlayerTurn();
        if (WinCheck()) {
            BoardDisplay();
            cout << "YOU WIN!" << endl;
            break;
        }
        if (isfull()) {
            BoardDestroy();
            return;
        }
        if (mode) ComputerEasy();
        else {
            pre = 0;
            ComputerHard();
        }
        if (WinCheck()) {
            BoardDisplay();
            cout << "YOU LOSE" << endl;
        }
        BoardDisplay();
        if (isfull()) {
            BoardDestroy();
            return;
        }
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
    for (int i = 0; i < COL; i++) cout << "****";
    cout << endl;
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            cout << " " << board[i][j] << " ";
            if (j < COL) cout << '|';
            else cout << endl;
        }
        for (int j = 1; i < ROW && j <= COL; j++) {
            cout << "---";
            if (j < COL) cout << '+';
            else cout << endl;
        }
    }
    for (int i = 0; i < COL; i++) cout << "****";
    cout << endl;
}

void PlayerTurn() {
    cout << "Enter X,Y coordinates for your move (row, col)" << endl;
    while (true) {
        if (cin >> row >> col) {
            if(row > 0 && col > 0 && row <= ROW && col <= COL) {
                if (board[row][col] != ' ') {
                    wrong();
                    continue;
                }
                board[row][col] = '*';
                return;
            }
            else {
                wrong();
                break;
            }
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

void ComputerHard() {
    int dr[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; // 行的方向
    int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 }; // 列的方向
    int DP[8] = {0}, hs[8] = {0};
    int maxx = -1, num;
    for (int i = 0; i < 8; i++) {
        int j = (i + 4) % 8;
        if(row + dr[j] <= 0 || row + dr[j] > ROW || col + dc[j] <= 0 || col + dc[j] > COL) continue;
        if (board[row + dr[j]][col + dc[j]] != ' ') hs[j] = 1;
        num = 0;
        for (int y = row, x = col; y > 0 && x > 0 && y <= ROW && x <= COL && board[y][x] == '*'; y += dr[i], x += dc[i]) {
            num++;
        }
        DP[j] = num;
        if (maxx < num) {
            maxx = num;
        }
    }
    while(true) {
        if(pre == 120) ComputerEasy();
        int j = rand() % 8;
        if(DP[j] != maxx && pre < 100) continue;
        pre++;
        if(hs[j] == 1) {
            for(int y = row + dr[j], x = col + dc[j]; ; y += dr[j], x += dc[j]) {
                if(y > 0 && x > 0 && y <= ROW && x <= COL) {
                    if(board[y][x] == ' ') {
                        col = x, row = y;
                        board[y][x] = '#';
                        return;
                    }
                    if(board[y][x] == '#') {
                        pre++;
                        break;
                    }
                }
                pre++;
            }
        }
        else {
            int x = col + dc[j], y = row + dr[j];
            if(y > 0 && x > 0 && y <= ROW && x <= COL) {
                col = x, row = y;
                board[row][col] = '#';
                return;
            }
            pre++;
            break;
        }
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
    for (int i = 0; i <= ROW; i++) {
        delete[] board[i];
    }
    delete[] board;
    board = NULL;
}
void wrong() {
    cout << "Invalid input!" << endl << "Please enter again" << endl;
}

bool isfull() {
    while (board[full.y][full.x] != ' ') {
        if (full.x > COL) {
            full.y++;
            full.x = 1;
        }
        if (full.y == ROW && full.x == COL) {
            cout << "The board is full";
            return true;
        }
        full.x++;
    }
    return false;
}