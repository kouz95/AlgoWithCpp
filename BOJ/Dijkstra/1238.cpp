//
//  1238.cpp
//  BOJ
//
//  Created by 김경준 on 24/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 2e9

void func(int vertex, int startVertex , vector<pair<int, int> > * oneToAll, int * oneToAllDist, vector<pair<int, int> > * allToOne, int * allToOneDist){
    priority_queue<pair<int, int> > qu;
    qu.push({0,startVertex});
    while (!qu.empty()) {
        int currCost = -qu.top().first;
        int currVertex = qu.top().second;
        qu.pop();
        for(int i = 0 ; i < oneToAll[currVertex].size(); i++){
            int nextVertex = oneToAll[currVertex][i].first;
            int nextCost = oneToAll[currVertex][i].second;
            oneToAllDist[nextVertex] = oneToAllDist[nextVertex] > oneToAllDist[currVertex] + nextCost ?
            (qu.push({-(oneToAllDist[currVertex] + nextCost),nextVertex}),oneToAllDist[currVertex] + nextCost) :
            oneToAllDist[nextVertex];
        }
    }
    qu.push({0,startVertex});
    while (!qu.empty()) {
        int currCost = -qu.top().first;
        int currVertex = qu.top().second;
        qu.pop();
        for(int i = 0 ; i < allToOne[currVertex].size(); i++){
            int nextVertex = allToOne[currVertex][i].first;
            int nextCost = allToOne[currVertex][i].second;
            allToOneDist[nextVertex] = allToOneDist[nextVertex] > allToOneDist[currVertex] + nextCost ?
            (qu.push({-(allToOneDist[currVertex] + nextCost),nextVertex}),allToOneDist[currVertex] + nextCost) :
            allToOneDist[nextVertex];
        }
    }
    int sum = 0;
    for (int i = 1 ; i <= vertex ; i++){
        
        if(!sum || sum < allToOneDist[i]+oneToAllDist[i])
            sum = allToOneDist[i]+oneToAllDist[i];
    }
    cout << sum << "\n";
}

void init(){
    int vertex , edge , startVertex;
    cin >> vertex >> edge >> startVertex;
    vector<pair<int, int> > oneToAll[vertex+1];
    vector<pair<int, int> > allToOne[vertex+1];
    for (int i = 0 ; i < edge ; i++){
        int from, to , val;
        cin >> from >> to >> val;
        oneToAll[from].push_back({to,val});
        allToOne[to].push_back({from,val});
    }
    int oneToAllDist[vertex+1];
    int allToOneDist[vertex+1];
    fill(oneToAllDist,oneToAllDist+vertex+1,INF);
    fill(allToOneDist,allToOneDist+vertex+1,INF);
    oneToAllDist[startVertex] = 0;
    allToOneDist[startVertex] = 0;
    func(vertex,startVertex,oneToAll,oneToAllDist,allToOne,allToOneDist);
}

int main(){
    init();
}
