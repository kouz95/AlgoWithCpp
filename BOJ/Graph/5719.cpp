//
//  5719.cpp
//  BOJ
//
//  Created by 김경준 on 28/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define INF 2e9
#define MAX 500

int map[MAX][MAX];

vector<pair<int, int> > path[MAX];
queue<int> Nodes;

void initCost(vector<pair<int, int> > * cost, int vertex,int * dist){
    for(int i = 0 ; i < vertex; i++)
        cost[i].clear();
    for(int i = 0 ; i < vertex ; i++)
        for(int j = 0 ; j < vertex; j++)
            if (map[i][j] != INF)
                cost[i].push_back({j,map[i][j]});
    fill(dist,dist+vertex,INF);
}
void deleteShortestPath(int startVertex,int endVertex,vector<pair<int, int> > * cost, int * dist){
    Nodes.push(endVertex);
    while(!Nodes.empty()){
        int currNode = Nodes.front();
        Nodes.pop();
        for (int i = 0 ; i < path[currNode].size(); i++){
            int from = path[currNode][i].first;
            int to = path[currNode][i].second;
            map[from][to] = INF;
            Nodes.push(from);
        }
    }
}

void dijkstra(int vertex,int startVertex,vector<pair<int,int> > * cost,int * dist){
    priority_queue<pair<int,int> > qu;
    qu.push({0,startVertex});
    dist[startVertex] = 0;
    
    while(!qu.empty()){
        int currVertex = qu.top().second;
        int currCost = -qu.top().first;
        qu.pop();
        for(int i = 0 ; i < cost[currVertex].size(); i++){
            int nextVertex = cost[currVertex][i].first;
            int nextCost = cost[currVertex][i].second;
            if(dist[nextVertex] > dist[currVertex] + nextCost){
                dist[nextVertex] = dist[currVertex] + nextCost;
                qu.push({-dist[nextVertex],nextVertex});
                path[nextVertex].clear();
                path[nextVertex].push_back({currVertex,nextVertex});
            }
            if (dist[nextVertex] == dist[currVertex] + nextCost)
                path[nextVertex].push_back({currVertex,nextVertex});
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int vertex, edge, startVertex, endVertex;
    vector<pair<int,int> > cost[MAX];
    int dist[MAX];
    while(1){
        cin >> vertex >> edge >> startVertex >> endVertex;
        if(!vertex && !edge)
            break;
        for(int i = 0 ; i < MAX; i++)
            cost[i].clear();
        fill(&map[0][0],&map[MAX-1][MAX],INF);
        for(int i = 0 ; i < edge ; i++){
            int from , to , val;
            cin >> from >> to >> val ;
            cost[from].push_back({to,val});
            map[from][to] = val;
        }
        fill(dist,dist+vertex,INF);
        dijkstra(vertex,startVertex,cost,dist);
        deleteShortestPath(startVertex,endVertex,cost,dist);
        initCost(cost,vertex,dist);
        dijkstra(vertex,startVertex,cost,dist);
        for(int i = 0 ; i < MAX; i++)
            path[i].clear();
        if(dist[endVertex] == INF)
            cout << -1 << "\n";
        else cout << dist[endVertex] << "\n";
        
    }
}

