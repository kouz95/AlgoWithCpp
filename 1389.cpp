//
//  1389.cpp
//  BOJ
//
//  Created by 김경준 on 23/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;
#define INF 2e9

const int MAX = 100;

int friends[MAX+1][MAX+1];
int n, m;

void res(){
    int num = INF;
    int person;
    for (int i = 1; i <= n; i++){
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += friends[i][j];
        if (num > sum){
            num = sum;
            person = i;
        }
    }
    cout << person << endl;
}
void func(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    continue;
                else if (friends[i][k] && friends[k][j]){
                    if (friends[i][j] == 0)
                        friends[i][j] = friends[i][k] + friends[k][j];
                    else
                        friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
                    
                }
}

void init(){
    cin >> n >> m;
    int from, to;
    for (int i = 0 ; i < m ; i++){
        cin >> from >> to;
        friends[from][to] = 1;
        friends[to][from] = 1;
    }
}

int main(){
    init();
    func();
    res();
}
