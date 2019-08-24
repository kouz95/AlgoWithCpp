//
//  1753.cpp
//  BOJ
//
//  Created by 김경준 on 23/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9
using namespace std;

void func(int vertex, int startVertex, vector<pair<int, int> > * cost,int * dist){
    priority_queue<pair<int,int> > qu;
    
    qu.push({0,startVertex});
    dist[startVertex] = 0;
    
    while(!qu.empty()){
        int currCost = -qu.top().first;
        int currVertex = qu.top().second;
        qu.pop();
        
        for(int i = 0 ; i < cost[currVertex].size(); i++){
            int nextVertex = cost[currVertex][i].first;
            int nextCost = cost[currVertex][i].second;
            
            dist[nextVertex] = dist[nextVertex] > dist[currVertex] + nextCost ? (qu.push({-(dist[currVertex] + nextCost),nextVertex}), dist[currVertex] + nextCost ) : dist[nextVertex];
            
        }
        
    }
    
    for (int i = 1 ; i<=vertex; i++){
        if (dist[i] != INF)
            cout << dist[i] << "\n";
        else cout << "INF" << "\n";
        
    }
}

void init(){
    int vertex, edge, startVertex;
    cin >> vertex >> edge >> startVertex;
    
    vector<pair<int, int> > cost[vertex+1]; // from , to , cost;
    
    for (int i = 0 ; i < edge ; i++){
        int from, to , val;
        cin >> from >> to >> val;
        cost[from].push_back({to,val});
    }
    int dist[vertex+1];
    fill(dist, dist+vertex+1,INF);
    func(vertex,startVertex,cost,dist);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}
