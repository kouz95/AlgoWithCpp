#include <iostream>
using namespace std;
int nArr[100001] = {0,};
int dp[100001] = {0,};
int n;

void input(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> nArr[i];
    }
}
void init(){
    int nMax;
    int newMax = 0;
    dp[0] = -1001;
    nMax = dp[0];
    dp[1] = nArr[1];
    nMax = dp[1];
    if (nArr[1] < 0){
        newMax = 0;
    }
    else newMax += nArr[1];
    for (int i = 2 ; i <= n ; i++){
        if(nArr[i] < 0){
            dp[i] = nMax;
            newMax = 0;
        }
        else{
            newMax += nArr[i];
            nMax = max(nMax,newMax);
            dp[i] = nMax;
        }
    }
}
int main(){
    input();
    init();
    cout << dp[n] <<endl;
    
}

// if negative -> cout << max & save index
// if positive -> compare max , newMax , cout << newMax
