#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int row;
    int col;
}Pos;

int R, C;
int room[252][252];
bool isVisit[252][252] = { false };
int sevenCnt = 0;
int fiveCnt = 0;
int ans[2] = { 0 };
queue<Pos> qu;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void BFS(int x, int y) {
    Pos startPos = { x, y };
    qu.push(startPos);
    isVisit[x][y] = true;
  
    while (!qu.empty()) {
        Pos currPos = qu.front();
        if(room[x][y] == 5) fiveCnt++;
          if(room[x][y] == 7) sevenCnt++;
          
        qu.pop();
        
        for (int i = 0; i < 4; i++) {
            Pos nextPos = { currPos.row + dy[i], currPos.col + dx[i] };
            if (room[nextPos.row][nextPos.col] != -1) {
                if (isVisit[nextPos.row][nextPos.col] == true)
                    continue;
                if (room[nextPos.row][nextPos.col] == 7) {
                    qu.push(nextPos);
                  
                    isVisit[nextPos.row][nextPos.col] = true;
                }
                else if (room[nextPos.row][nextPos.col] == 5) {
                    qu.push(nextPos);
                  
                    isVisit[nextPos.row][nextPos.col] = true;
                }
                else if (room[nextPos.row][nextPos.col] == -2) {
                    qu.push(nextPos);
                    isVisit[nextPos.row][nextPos.col] = true;
                }
            }
        }
    }
    
}

int main() {
    cin >> R >> C;
    
    string* inputArr;
    inputArr = new string[250];
    
    for (int i = 0; i < R+2; i++)
        for (int j = 0; j < C+2; j++)
            room[i][j] = -1;
    
    for (int i = 0; i < R; i++) {
        cin >> inputArr[i];
        for (int j = 0; j < C; j++)
            room[i + 1][j + 1] = (int)inputArr[i][j] - '0';//ascii
    }
    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (room[i][j] != -13) {
                fiveCnt = 0;
                sevenCnt = 0;
                BFS(i, j);
                if (fiveCnt >= sevenCnt) {
                    sevenCnt = 0;
                }
                else fiveCnt = 0;
                ans[0] += sevenCnt;
                ans[1] += fiveCnt;
            }
        }
    }
    
    cout << ans[0] << " " << ans[1];
}
