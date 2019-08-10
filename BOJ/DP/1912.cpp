#include <iostream>
using namespace std;
int nArr[100001] = {0,};
int dp[100001] = {0,};
int n;
int nMax = -1001;

void input(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> nArr[i];
    }
}
void init(){
    dp[0] = nMax;
    
    for (int i = 1 ; i <= n ; i++){
        if (dp[i-1] + nArr[i] > nArr[i])
            dp[i] = dp[i-1] + nArr[i];
        else dp[i] = nArr[i];
    }
    nMax = dp[1];
    for (int i = 2 ; i<= n ; i++){
        if(nMax < dp[i])
            nMax = dp[i];
    }
}
int main(){
    input();
    init();
    cout << nMax <<endl;
    
}
