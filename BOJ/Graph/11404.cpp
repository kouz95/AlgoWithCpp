//
//  11404.cpp
//  BOJ
//
//  Created by 김경준 on 21/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10000000

int n;
int m;

int start, _end, newCost;

int cost[101][101];

void res(){
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if(cost[i][j] == INF)
                cost[i][j] = 0;
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}

void func(){
    for (int k = 1 ; k <= n ; k++)
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= n ; j++)
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
}

void init(){
     cin >> n >> m;
    for (int i = 1; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++)
            cost[i][j] = INF;
    
    
    for (int i = 1; i <= n ; i++)
        for(int j = 1 ; i<= n ; j++)
            if (i == j)
                cost[i][j] = 0;
    
    for (int i = 1 ; i <= m ; i++){
        cin >> start >> _end >> newCost;
        if (cost[start][_end] > newCost)
            cost[start][_end] = newCost;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    func();
    res();
}
