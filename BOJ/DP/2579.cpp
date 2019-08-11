//
//  2579.cpp
//  BOJ
//
//  Created by 김경준 on 11/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int score[301] ={0,};
int dp[301] = {0,};


void func(){
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    for (int i = 3 ; i <= n ; i++)
        dp[i] = max(dp[i-3] + score[i-1] + score[i],dp[i-2] + score[i]);
    
    cout << dp[n] <<endl;
}

void input(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> score[i];
}

int main(){
    input();
    func();
}

