//
//  5719.cpp
//  BOJ
//
//  Created by 김경준 on 22/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 1000000

int node , edge;
int map[500][500];
int u, v, p;
int dist[500];
bool visit[500] = {false,};
int sNode, eNode;

void getShortestPath(){
    dist[0] = 0;
    for (int i = 1 ; i < 500 ; i++)
        dist[i] = INF;
    int curNode = 0;
    for(int i = 1 ; i < node ; i++){
        dist[i] = dist[curNode] +
    }
    
}

void init(){
    cin >> node >> edge;
    if(!node && !edge){
        cin >> sNode >> eNode;
        for (int i = 0 ; i < node ; i++)
            for (int j = 0 ; j < node ; j++)
                map[i][j] = i==j ? 0 : INF;
        for (int i = 0 ; i < edge ; i++){
            cin >> u >> v >> p;
            map[u][v] = p;
        }
        getShortestPath();
    }
}

int main(){
    init();
}

