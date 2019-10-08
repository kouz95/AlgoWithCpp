//
//  11052.cpp
//  BOJ
//
//  Created by 김경준 on 08/10/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>

#define MAX 1000

using namespace std;

int dp[MAX+1];
int n;
int cost[MAX+1];

void init(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> cost[i];
}

void getDp(){
    dp[0] = 0;
    dp[1] = cost[1];
    for(int i = 2 ; i <= n ; i++)
        for(int j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i-j] + cost[j]);
}

int main(){
    init();
    getDp();
    cout << dp[n] << endl;
    
}
