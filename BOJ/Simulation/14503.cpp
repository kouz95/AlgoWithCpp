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

Pos myRobotPos;
int myRobotDir;

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
bool isClean[MAX_MAP_SIZE][MAX_MAP_SIZE];

int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, 1, 0, -1 };

Pos getNextPos() {
    Pos nextPos;
    switch (myRobotDir) {
        case 0:
            nextPos.row = myRobotPos.row + dR[3];
            nextPos.col = myRobotPos.col + dC[3];
            break;
            
        case 1:
            nextPos.row = myRobotPos.row + dR[0];
            nextPos.col = myRobotPos.col + dC[0];
            break;
            
        case 2:
            nextPos.row = myRobotPos.row + dR[1];
            nextPos.col = myRobotPos.col + dC[1];
            break;
            
        case 3:
            nextPos.row = myRobotPos.row + dR[2];
            nextPos.col = myRobotPos.col + dC[2];
            break;
            
        default:
            break;
    }
    return nextPos;
}

bool isCleaned(Pos robotPos) {
    return isClean[robotPos.row][robotPos.col];;
}

bool backIsWall(){

    Pos nextPos;
    
    switch (myRobotDir) {
        case 0:
            nextPos.row = myRobotPos.row + dR[2];
            nextPos.col = myRobotPos.col + dC[2];
            break;
            
        case 1:
            nextPos.row = myRobotPos.row + dR[3];
            nextPos.col = myRobotPos.col + dC[3];
            break;
            
        case 2:
            nextPos.row = myRobotPos.row + dR[0];
            nextPos.col = myRobotPos.col + dC[0];
            break;
            
        case 3:
            nextPos.row = myRobotPos.row + dR[1];
            nextPos.col = myRobotPos.col + dC[1];
            break;
            
        default:
            break;
    }
    
    return map[nextPos.row][nextPos.col] == 1;
}

bool noWays() {
    bool res = true;
    Pos nextPos;
    for(int i = 0 ; i < 4 ; i++){
        nextPos.row = myRobotPos.row + dR[i];
        nextPos.col = myRobotPos.col + dC[i];
        if(isCleaned(nextPos) || map[nextPos.row][nextPos.col] == 1)
            continue;
        res = false;
    }
    
    return res;
}

void turnLeft(){
    myRobotDir = myRobotDir == 0 ? 3 : myRobotDir - 1;
}
void cleaningHere() {
    isClean[myRobotPos.row][myRobotPos.col] = true;
}

void goBack(){
    Pos nextPos;
    
    switch (myRobotDir) {
        case 0:
            nextPos.row = myRobotPos.row + dR[2];
            nextPos.col = myRobotPos.col + dC[2];
            break;
            
        case 1:
            nextPos.row = myRobotPos.row + dR[3];
            nextPos.col = myRobotPos.col + dC[3];
            break;
            
        case 2:
            nextPos.row = myRobotPos.row + dR[0];
            nextPos.col = myRobotPos.col + dC[0];
            break;
            
        case 3:
            nextPos.row = myRobotPos.row + dR[1];
            nextPos.col = myRobotPos.col + dC[1];
            break;
            
        default:
            break;
    }
    myRobotPos = nextPos;
}

void simulation(){
    cleaningHere();
    if(noWays() && backIsWall())
        return;
    if(!backIsWall() && noWays()){
        goBack();
        simulation();
        return;
    }
    Pos nextPos = getNextPos();
    if(!isCleaned(nextPos) && map[nextPos.row][nextPos.col] != 1){
        myRobotPos = nextPos;
        turnLeft();
        simulation();
    }
    else {
        turnLeft();
        simulation();
    }
}


void init() {
    cin >> height >> width;
    cin >> myRobotPos.row >> myRobotPos.col >> myRobotDir;
    
    for(int i = 0 ; i < height ; i++) {
        for(int j = 0 ; j < width ; j++) {
            cin >> map[i][j];
        }
    }
    memset(isClean, false, sizeof(isClean));
}

int getCleanArea(){
    int res = 0;
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            res = isClean[i][j] ? res + 1 : res;
        }
    }
    return res;
}

int main() {
    init();
    simulation();
    cout << getCleanArea() << "\n";
}

