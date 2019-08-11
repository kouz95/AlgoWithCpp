//
//  11726.cpp
//  BOJ
//
//  Created by 김경준 on 11/08/2019.
//  Copyright © 2019 kouz. All rights reserved.
//

#include <iostream>
using namespace std;

int n;

int dp[1001] = {0,};

void func(){
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3 ; i<= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    
    cout << dp[n] <<endl;
}

void input(){
    cin >> n;
}

int main(){
    input();
    func();
}
