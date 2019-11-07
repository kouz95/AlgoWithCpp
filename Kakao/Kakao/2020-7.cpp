#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

#define MAX_MAP_SIZE 100

typedef struct {
    int row1;
    int col1;
    int row2;
    int col2;
    int dir;
}Pos;

Pos myRobot;

bool isVisit[MAX_MAP_SIZE+2][MAX_MAP_SIZE+2][2];

void visitCheck(Pos currPos) {
    isVisit[currPos.row1][currPos.col1][currPos.dir] = true;
    isVisit[currPos.row2][currPos.col2][currPos.dir] = true;
}

void init(){
    myRobot.row1 = 1;
    myRobot.col1 = 1;
    myRobot.row2 = 1;
    myRobot.col2 = 2;
    myRobot.dir = 0; // 0 : 가로 , 1 : 세로
    memset(isVisit, false, sizeof(isVisit));
}

bool isFinished(Pos currPos, int boardLen) {
    return ( (currPos.row1 == boardLen) && (currPos.col1 == boardLen) ) || ( (currPos.row2 == boardLen) && (currPos.col2 == boardLen) );
}

bool isOutOfRange(Pos currPos, vector<vector<int>> borad) {
    return (currPos.row1 > 0 && currPos.col1 > 0) && (currPos.row2 > 0 && currPos.col2 > 0) && (currPos.row1 <= borad.size() && currPos.col1 <= borad.size()) && (currPos.row2 <= borad.size() && currPos.col2 <= borad.size());
}

pair<int, int> getBoardValue(Pos currPos, vector<vector<int>> board) {
    return {board[currPos.row1][currPos.col1], board[currPos.row2][currPos.col2]};
}

bool isThereAWall(Pos currPos, vector<vector<int>> board) {
    if(isOutOfRange(currPos, board))
        return false;
    return getBoardValue(currPos, board).first || getBoardValue(currPos, board).second;
}

Pos turnTwoDown(Pos currPos) {
    Pos nextPos = currPos;
    if(currPos.dir) { // 세로
        nextPos.row2 -= 1;
        nextPos.col2 += 1;
        nextPos.dir = 0;
        return nextPos;
    }
    // 가로
    nextPos.row2 += 1;
    nextPos.col2 += 1;
    nextPos.dir = 1;
    return nextPos;
}

Pos turnTwoUp(Pos currPos) {
    Pos nextPos = currPos;
    
    if(currPos.dir) { // 세로
        nextPos.row2 -= 1;
        nextPos.col2 -= 1;
        nextPos.dir = 0;
        return nextPos;
    }
    // 가로
    nextPos.row2 -= 1;
    nextPos.col2 -= 1;
    nextPos.dir = 1;
    return nextPos;
}

Pos turnOneDown(Pos currPos) {
    Pos nextPos = currPos;
    if(currPos.dir) { // 세로
        nextPos.row1 -= 1;
        nextPos.col1 += 1;
        nextPos.dir = 0;
        return nextPos;
    }
    // 가로
    nextPos.row1 += 1;
    nextPos.col1 += 1;
    nextPos.dir = 1;
    return nextPos;
}

Pos turnOneUp(Pos currPos) {
    Pos nextPos;
    if(currPos.dir) { // 새로
        
    }
    return nextPos;
}

Pos goLeft(Pos currPos) {
    Pos nextPos = currPos;
    nextPos.col1 -= 1;
    nextPos.col2 -= 1;
    return nextPos;
}

Pos goDown(Pos currPos) {
    Pos nextPos = currPos;
    nextPos.row1 += 1;
    nextPos.row2 += 1;
    return nextPos;
}

Pos goRight(Pos currPos) {
    Pos nextPos = currPos;
    nextPos.col1 += 1;
    nextPos.col2 += 1;
    return nextPos;
}

Pos goUp(Pos currPos) {
    Pos nextPos = currPos;
    nextPos.row1 -= 1;
    nextPos.row2 -= 1;
    return nextPos;
}

bool canMove(Pos currPos, int wayNum, vector<vector<int>> board) {
    bool res = true;
    Pos nextPos;
    int turnNum = 0;
    switch (wayNum) {
        case 0:
            nextPos = goUp(currPos);
            break;
        case 1:
            nextPos = goRight(currPos);
            break;
        case 2:
            nextPos = goDown(currPos);
            break;
        case 3:
            nextPos = goLeft(currPos);
            break;
        case 4:
            nextPos = turnOneUp(currPos);
            turnNum = 1;
            break;
        case 5:
            nextPos = turnOneDown(currPos);
            turnNum = 2;
            break;
        case 6:
            nextPos = turnTwoUp(currPos);
            turnNum = 3;
            break;
        case 7:
            nextPos = turnTwoDown(currPos);
            turnNum = 4;
            break;
        default:
            break;
    }
    if(isThereAWall(nextPos, board))
        return false;
    if(turnNum){
        return !isThereAWallInTurning(currPos, turnNum, board)
    }
    return res;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int boardSize = board.size();
    queue<Pos> qu;
    map<Pos, int> timeCheck;
    map<Pos, int>::iterator iter;
    init();
    qu.push(myRobot);
    visitCheck(myRobot);
    timeCheck.insert({myRobot,0});
    while(!qu.empty()){
        Pos currPos = qu.front();
        if(isFinished(currPos, boardSize))
            break;
        qu.pop();
        for(int i = 0 ; i < 8 ; i++){
            if(!canMove(currPos, i, board))
                continue;
            Pos nextPos = getNextPos(currPos, i);
            if(isVisited(nextPos))
                continue;
            if(isLated(nextPos))
                continue;
            qu.push(nextPos);
            iter = timeCheck.find(currPos);
            timeCheck.insert({nextPos, iter->second});
            visitCheck(nextPos);
        }
    }
    return answer;
}
