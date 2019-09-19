//
//  1260.cpp
//  BOJ
//
//  Created by 김경준 on 10/09/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

void BFS(int startVertex, vector<int> * edges, int vertex, bool * visit){
    queue<int> qu;
    qu.push(startVertex);
    cout << qu.front() << " ";
    visit[startVertex] = true;
    while(!qu.empty()){
        int currVertex = qu.front();
        qu.pop();
        for(int i = 0 ; i < edges[currVertex].size(); i++){
            int nextVertex = edges[currVertex][i];
            if(!visit[nextVertex]){
                visit[nextVertex] = true;
                cout << nextVertex << " ";
                qu.push(nextVertex);
            }
            
        }
    }
}

void DFS(int startVertex, vector<int> * edges, int vertex, bool * visit){
    int currVertex = startVertex;
    if(!visit[currVertex]){
        visit[currVertex] = true;
        cout << currVertex << " ";
        for(int i = 0 ; i < edges[currVertex].size(); i++){
            int nextVertex = edges[currVertex][i];
            DFS(nextVertex,edges,vertex,visit);
        }
    }
}

int main(){
    int vertex, edge, startVertex;
    cin >> vertex >> edge >> startVertex;
    vector<int> edges[vertex+1];
    for(int i = 0 ; i < edge ; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    /*
     vertex
     0  1   2   3   4
     0
     1  2   3   4
     2  1   4
     3  1   4
     4  1   2   3
     */
    
    
    bool visit[vertex+1];
    for(int j = 1; j <= vertex; j++)
        sort(edges[j].begin(), edges[j].end());
    memset(visit, false, sizeof(visit));
    DFS(startVertex,edges,vertex,visit);
    cout << "\n";
    memset(visit, false, sizeof(visit));
    BFS(startVertex,edges,vertex,visit);
}
