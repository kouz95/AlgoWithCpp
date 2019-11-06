//
//  14503.cpp
//  BOJ
//
//  Created by 김경준 on 2019/11/06.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_MAP_SIZE 50

int height, width;

typedef struct {
    int row;
    int col;
} Pos;

Pos myRobot;
int myRobotDir;
int turnCnt = 0;

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool isVisit[MAX_MAP_SIZE][MAX_MAP_SIZE];

int dR[4] = { 1, 0, -1, 0 };
int dC[4] = { 0, 1, 0, -1 };


int getSize(){
    int size = 0;
    for( int i = 0 ; i < height ; i++ ) {
        for ( int j = 0 ; j < width ; j++ ) {
            if(isVisit[i][j])
                size++;
        }
    }
    return size;
}

Pos getNextPos(Pos currPos) {
    Pos nextPos;
    
    switch (myRobotDir) {
        case 0:
            nextPos.row = currPos.row + dR[3];
            nextPos.col = currPos.col + dC[3];
            break;
        case 1:
            nextPos.row = currPos.row + dR[0];
            nextPos.col = currPos.col + dC[0];
            break;
        case 2:
            nextPos.row = currPos.row + dR[1];
            nextPos.col = currPos.col + dC[1];
            break;
        case 3:
            nextPos.row = currPos.row + dR[2];
            nextPos.col = currPos.col + dC[2];
            break;
            
        default:
            break;
    }
    
    return nextPos;
}

Pos goBack(){
    Pos nextPos;
    
    switch (myRobotDir) {
        case 0:
            nextPos.row = myRobot.row + dR[2];
            nextPos.col = myRobot.col + dC[2];
            break;
        case 1:
            nextPos.row = myRobot.row + dR[3];
            nextPos.col = myRobot.col + dC[3];
            break;
        case 2:
            nextPos.row = myRobot.row + dR[0];
            nextPos.col = myRobot.col + dC[0];
            break;
        case 3:
            nextPos.row = myRobot.row + dR[1];
            nextPos.col = myRobot.col + dC[1];
            break;
            
        default:
            break;
    }
    
    return nextPos;
}

void simulation() {
    Pos currPos, nextPos;
    while(1){
        currPos.row = myRobot.row;
        currPos.col = myRobot.col;
        isVisit[currPos.row][currPos.col] = true;
        if(turnCnt == 4) {
            nextPos = goBack();
            if(map[nextPos.row][nextPos.col] != 1) {
                myRobot = nextPos;
                turnCnt = 0;
                continue;
            }
            else break;
        }
        
        nextPos = getNextPos(currPos);
        if(!isVisit[nextPos.row][nextPos.col] && map[nextPos.row][nextPos.col] != 1) {
            myRobot = nextPos;
            if(myRobotDir == 0)
                myRobotDir = 3;
            else myRobotDir -= 1;
            turnCnt = 0;
            continue;
        }
        else {
            if(myRobotDir == 0)
                myRobotDir = 3;
            else myRobotDir -= 1;
            turnCnt++;
            continue;
        }
    }
    
}

void init() {
    cin >> height >> width;
    cin >> myRobot.row >> myRobot.col >> myRobotDir;
    
    for(int i = 0 ; i < height ; i++) {
        for(int j = 0 ; j < width ; j++) {
            cin >> map[i][j];
        }
    }
    memset(isVisit, false, sizeof(isVisit));
}

int main() {
    init();
    simulation();
    cout << getSize() << endl;
}

