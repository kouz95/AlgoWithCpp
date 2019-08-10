#include <iostream>
using namespace std;

int t;
int num;

typedef struct dp{
    int zero;
    int one;
}Dp;

Dp dp[41];

void func(){
    cin >> num;
    cout << dp[num].zero << " " << dp[num].one <<endl;
}
void input(){
    cin >> t;
    while (t > 0){
        func();
        t--;
    }
}
void init(){
    dp[0].zero = 1;
    dp[0].one = 0;
    dp[1].zero = 0;
    dp[1].one = 1;
    
    for (int i = 2; i < 41 ; i ++){
        dp[i].zero = dp[i-1].zero + dp[i-2].zero;
        dp[i].one = dp[i-1].one + dp[i-2].one;
    }
}
int main()
{
    init();
    input();
    return 0;
}
