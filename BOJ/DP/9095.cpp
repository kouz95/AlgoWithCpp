#include <iostream>
using namespace std;

int dp[11];
int n;

void init(){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
}

void func(){
    cin >> n;
    init();
    cout << dp[n]<< endl;
}

void input(){
    int t;
    cin >> t;
    while (t){
        func();
        t--;
    }
}
int main(){
    input();
}
