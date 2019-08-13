//
//  1932.cpp
//  BOJ
//
//  Created by 김경준 on 13/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int tri[501][501];
int dp[501][501];

void func(){
    dp[1][1] = tri[1][1];
    for(int i = 2; i <= n ; i++){
        for (int j = 1; j<=n ; j++){
            if(j == 1)
                dp[i][j] = dp[i-1][j] + tri[i][j];
            if(j == i)
                dp[i][j] = dp[i-1][j-1] + tri[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tri[i][j];
        }
    }
    int max = 0;
    for (int i = 1 ; i <= n ; i++){
        if(!max || max < dp[n][i])
            max = dp[n][i];
    }
    cout << max << endl;
}

void input(){
    cin >> n;
    for (int i = 1; i <= n ; i++)
        for (int j = 1 ; j <= i ; j++)
            cin >> tri[i][j];
}

int main(){
    input();
    func();
}
