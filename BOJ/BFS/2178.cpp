//
//  2178.cpp
//  BOJ
//
//  Created by 김경준 on 04/10/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100

typedef struct{
    int row;
    int col;
}Pos;

int map[MAX+2][MAX+2];
int height, width;
bool isVisit[MAX+2][MAX+2];
int countMap[MAX+2][MAX+2];

int dR[4] = {1,0,-1,0};
int dC[4] = {0,1,0,-1};

void init(){
    cin >> height >> width;
    string inputArr[height];
    for(int i = 0; i < height+2 ; i++)
        for(int j = 0; j < width+2 ; j++)
            map[i][j] = -1;
    for(int i = 0 ; i < height ; i++){
        cin >> inputArr[i];
        for(int j = 0 ; j < width ; j++)
            map[i+1][j+1] = (int)inputArr[i][j] - '0';
    }
}

void visitBFS(){
    Pos startPos = {1,1};
    queue<Pos> qu;
    qu.push(startPos);
    countMap[startPos.row][startPos.col] = 1;
    isVisit[startPos.row][startPos.col]=true;
    while(!qu.empty()){
        Pos currPos = qu.front();
        if(currPos.row == height && currPos.col == width)
            break;
        qu.pop();
        for(int i = 0 ; i < 4 ; i++){
            Pos nextPos = {currPos.row + dR[i], currPos.col + dC[i]};
            if(isVisit[nextPos.row][nextPos.col] == true)
                continue;
            if(map[nextPos.row][nextPos.col] == 1){
                countMap[nextPos.row][nextPos.col] = countMap[currPos.row][currPos.col]+1;
                qu.push(nextPos);
                isVisit[nextPos.row][nextPos.col]=true;
            }
        }
    }
}
int main(){
    init();
    visitBFS();
    cout << countMap[height][width] << endl;
}

