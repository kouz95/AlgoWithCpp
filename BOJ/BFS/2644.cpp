//
//  2644.cpp
//  BOJ
//
//  Created by 김경준 on 04/10/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 100

int vertexNum;
int startVertex, endVertex;
int edgeNum;
vector<int> edge[MAX+1];
bool isVisit[MAX+1];
int numCnt[MAX+1];
bool isValid = true;

void init(){
    cin >> vertexNum >> startVertex >> endVertex >> edgeNum;
    for(int i = 0 ; i < edgeNum ; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    memset(isVisit,false,sizeof(isVisit));
    memset(numCnt, 0, sizeof(numCnt));
}

void visitBFS(){
    queue<int> qu;
    qu.push(startVertex);
    isVisit[startVertex] = true;
    numCnt[startVertex] = 0;
    while(!qu.empty()){
        int currVertex = qu.front();
        if(currVertex == endVertex)
            break;
        qu.pop();
        for(int i = 0 ; i < edge[currVertex].size() ; i++){
            int nextVertex = edge[currVertex][i];
            if(isVisit[nextVertex])
                continue;
            qu.push(nextVertex);
            isVisit[nextVertex] = true;
            numCnt[nextVertex] = numCnt[currVertex] + 1;
        }
    }
    if(qu.empty())
        isValid = false;
}

int main(){
    init();
    visitBFS();
    if(isValid)
    cout << numCnt[endVertex] << endl;
    else cout << -1 <<endl;
}
