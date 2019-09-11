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
#include <string.h>

using namespace std;

void BFS(int startVertex, vector<int> * edges, int vertex, bool * visit){
    queue<int> qu;
    qu.push(startVertex);
    visit[startVertex] = true;
    cout << qu.front() << " " ;
    while (!qu.empty()){
        int currVertex = qu.front();
        qu.pop();
        for(int i = 0 ; i < edges[currVertex].size(); i++){
            int nextVertex = edges[currVertex][i];
            if (!visit[nextVertex]){
                cout << nextVertex << " ";
                visit[nextVertex] = true;
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
    else return;
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
        bool visit[vertex+1];
        memset(visit, 0, sizeof(visit));
        for(int j = 1; j <= vertex; j++)
            sort(edges[j].begin(), edges[j].end());
        
        DFS(startVertex,edges,vertex,visit);
        cout << "\n";
        memset(visit, 0, sizeof(visit));
        BFS(startVertex,edges,vertex,visit);
    }
