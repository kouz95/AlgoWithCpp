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
pair <int,int> route;
vector<pair<int,int>> vRoute;
int sNode, eNode;

void getShortestPath(){

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

