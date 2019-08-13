//
//  2156.cpp
//  BOJ
//
//  Created by 김경준 on 13/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int amt[10001];
int dp[10001];

void func(){
    dp[0] = 0;
    dp[1] = amt[1];
    dp[2] = dp[1] + amt[2];
    for (int i = 3 ; i<= n; i ++)
        dp[i] = max(max(dp[i-2] + amt[i],dp[i-3] + amt[i-1] + amt[i]),dp[i-1]);
    cout << dp[n]<<endl;
}

void input(){
    cin >> n;
    for ( int i = 1 ; i<= n ; i++)
        cin >> amt[i];
}

int main(){
    input();
    func();
}
