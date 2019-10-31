//
//  11403.cpp
//  BOJ
//
//  Created by 김경준 on 2019/10/31.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;

vector<int> edge[100];
bool isConnected[100][100];
bool isVisit[100];

void sol(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(isConnected[i][j])
                cout << "1 ";
            else cout << "0 ";
        }
        cout << "\n";
    }
}

void BFS(){
    queue<int> qu;
    for(int i = 0 ; i < n ; i++){
        memset(isVisit,false,sizeof(isVisit));
        int firstVertex = i;
        qu.push(i);
        isVisit[i]= true;
        while(!qu.empty()){
            int currVertex = qu.front();
            qu.pop();
            for(int j = 0 ; j < edge[currVertex].size() ; j++){
                int nextVertex = edge[currVertex][j];
                if(isVisit[nextVertex]){
                    isConnected[firstVertex][nextVertex]=true;
                    continue;
                }
                qu.push(nextVertex);
                isVisit[nextVertex]=true;
                isConnected[firstVertex][nextVertex]=true;
            }
        }
    }
}

void init(){
    cin >> n;
    for(int i = 0; i < n ; i ++){
        for(int j = 0 ; j < n ; j++){
            int val;
            int from, to;
            cin >> val;
            if(val){
                from = i;
                to = j;
                edge[from].push_back(to);
            }
            
        }
    }
    memset(isConnected, false, sizeof(isConnected));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    BFS();
    sol();
    return 0;
}
