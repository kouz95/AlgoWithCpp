//
//  2193.cpp
//  BOJ
//
//  Created by 김경준 on 12/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
long long int dp[91][2];

void func(){
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[n][0] + dp[n][1] <<endl;
}

void input(){
    cin >> n;
}

int main(){
    input();
    func();
}
