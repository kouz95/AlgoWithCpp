//
//  14502.cpp
//  BOJ
//
//  Created by 김경준 on 22/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
#define MAX 8

int map[MAX+2][MAX+2];
int tmpMap[MAX+2][MAX+2];

typedef struct pos{
    int val;
    int x;
    int y;
}Pos;

Pos wall1, wall2, wall3;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<pair <int, int> > virusPos;
vector<pair <int, int> > tmpVirusPos;
int maxSize = 0;

void resetMap(){
    for(int i = 0 ; i < MAX+2 ; i++)
        for(int j = 0 ; j < MAX+2 ; j++)
            map[i][j] = tmpMap[i][j];
}

void copyMap(){
    for(int i = 0 ; i < MAX+2 ; i++)
        for(int j = 0 ; j < MAX+2 ; j++)
            tmpMap[i][j] = map[i][j];
}

void setWalls(){
    map[wall1.y][wall1.x] = 1;
    map[wall2.y][wall2.x] = 1;
    map[wall3.y][wall3.x] = 1;
}

void spreadVirus(){
    setWalls();
    virusPos.assign(tmpVirusPos.begin(), tmpVirusPos.end());
    while(!virusPos.empty()){
        int VirusX = virusPos.back().first;
        int VirusY = virusPos.back().second;
        virusPos.pop_back();
        
        queue<pair<int, int> > qu;
        qu.push({VirusX,VirusY});
        while (!qu.empty()) {
            int currVirusX = qu.front().first;
            int cuurVirusY = qu.front().second;
            qu.pop();
            for(int q = 0 ; q < 4 ; q++){
                int nextVirusX = currVirusX + dx[q];
                int nextVirusY = cuurVirusY + dy[q];
                if(map[nextVirusY][nextVirusX] == 0){
                    qu.push({nextVirusX,nextVirusY});
                    map[nextVirusY][nextVirusX] = 2;
                }
            }
        }
    }
}

void getSafeAreaSize(int height, int width){
    spreadVirus();
    int res = 0;
    for(int o = 1 ; o <= height ; o++)
        for(int p = 1 ; p <= width ; p++)
            if(map[o][p] == 0)
                res++;
    if(!maxSize || maxSize < res)
        maxSize = res;
    resetMap();
}
void setThreeWalls(int height, int width){
    vector<pair <int, int> > wallMap;
    for(int i = 1 ; i <= height ; i++)
        for(int j = 1 ; j <= width ; j++)
            if(map[i][j] == 0)
                wallMap.push_back({j,i});
    for(int i = 0 ; i < wallMap.size() - 2 ; i++){
        wall1.x = wallMap[i].first;
        wall1.y = wallMap[i].second;
        for(int j = i+1 ; j < wallMap.size() - 1 ; j++){
            wall2.x = wallMap[j].first;
            wall2.y = wallMap[j].second;
            for(int k = j+1 ; k < wallMap.size() ; k++){
                wall3.x = wallMap[k].first;
                wall3.y = wallMap[k].second;
                getSafeAreaSize(height, width);
            }
        }
    }
//    wall1.x = 5;
//    wall1.y = 1;
//    wall2.x = 4;
//    wall2.y = 2;
//    wall3.x = 4;
//    wall3.y = 4;
//    getSafeAreaSize(height, width);
}

int main(){
    int height, width;
    cin >> height >> width;
    memset(map, -1, sizeof(map));
    map[0][0] = -1;
    for(int i = 1 ; i <= height ; i++)
        for(int j = 1 ; j <= width ; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                virusPos.push_back({j,i});
        }
    copyMap();
    tmpVirusPos.assign(virusPos.begin(), virusPos.end());
    wall1.val = 1;
    wall2.val = 1;
    wall3.val = 1;
    setThreeWalls(height, width);
    cout << maxSize << endl;
}

