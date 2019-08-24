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

int vertex , edge , startVertex;
 // from , to, cost


void func(int vertex, vector <pair<int,int> > * arr){
    int dist[vertex+1];
    fill(dist,dist+vertex+1,INF);
    priority_queue<pair<int,int> > qu; // cost , to
    qu.push({0,startVertex});
    dist[startVertex] = 0;
    
    
    while(!qu.empty()){
        int val = -qu.top().first;
        int here = qu.top().second;
        
        qu.pop();
        
        for (int i = 0 ; i < arr[here].size() ; i++){
            int next = arr[here][i].first;
            int nextCost = arr[here][i].second;
            
            if(dist[next] > dist[here] + nextCost){
                dist[next] = dist[here] + nextCost;
                qu.push({-dist[next],next});
            }
        }
    }
    for (int i = 1 ; i <= vertex ; i++){
        if (dist[i] !=INF)
            cout << dist[i] << endl;
        else cout << "INF" << endl;
    }
}

void init(){
    
    cin >> vertex >> edge;
    cin >> startVertex;
    vector<pair<int,int> > arr[vertex+1];
   
    for (int i = 0 ; i < edge ; i++){
        int from, to, cost;
        cin >> from >> to >> cost ;
        arr[from].push_back({to,cost});
    }
    func(vertex, arr);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}
